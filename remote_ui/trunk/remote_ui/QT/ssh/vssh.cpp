#include "vssh.h"
#include "mainframe.h"
#include "sshtunnel.h"
#include <QDebug>

VSSH::VSSH(QString host, QString user, QString password, QString exec, QObject *parent) :
  QThread(parent)
{


  tunnelport = 0;
  session = ssh_new();

  if(!session)
  {
      qDebug()<<"Session cant be established";
      return;
     //Todo: msgbox auslagern das es abstract ist und hier fehler ausgeben
  }

  if(host.isEmpty())
  {
      //Todo Fehler ausgeben.
      return;
  }

  setHost(host);
  setUser(user);
  setPassword(password);
  setExecuteCommand(exec);

}

VSSH::~VSSH()
{
  if(session)
  {
     ssh_free(session);
     session = NULL;
  }
}

void VSSH::run()
{


  cnt_tunnel = 0;

  QTime now = QTime::currentTime();
  qsrand(now.second() + now.msec());

  int rc = 0;
  this->loadSettings();
  rc = this->connectToHost();
  //Try again or fail
  switch(rc)
  {

    case SSH_AGAIN:
       rc = this->connectToHost();
       break;
    case SSH_ERROR:
      emit connectionfailed(rc, host());
      return;

  }
  //mh again again? fail!
  if(rc == SSH_ERROR || rc == SSH_AGAIN)
  {
      emit connectionfailed(rc, host());
      emit fail();
      VDC::arrowCursor();
      return;
  }

  rc = this->auth();

  if(rc == SSH_ERROR)
  {
      VDC::arrowCursor();
      return;
  }

  //rc = this->tunnel();
/*
  t_sshtunnel = new SSHTunnel;
  t_sshtunnel->tunnelport = 0;
  t_sshtunnel->base_session = session;
  t_sshtunnel->sctunnel = NULL;
  t_sshtunnel->start(QThread::NormalPriority);
*/

  /*
  while(t_sshtunnel->tunnelport == 0)
  {
      usleep(500000);
  }

  int port = t_sshtunnel->tunnelport;
*/



  int port=0;
  switch(rc)
    {
      case SSH_AUTH_SUCCESS:
         ssh_mutex.lock();
         rc = ssh_forward_listen(session, NULL, 0, &port);
         ssh_mutex.unlock();
         if(port == -1)
         {
             //Fehler beim Forwarding
             QString err = "Portforwarding konnte nicht auf dem Server initialisiert werden";
             emit error(err);
             emit fail();
             VDC::arrowCursor();
             return;
         }
         else
         this->execute(port);
         break;
    default:
      emit authfailed(rc, user());
      emit fail();
      VDC::arrowCursor();
      return;

    }

  ssh_mutex.lock();
  ssh_free(session);
  session = NULL;
  ssh_mutex.unlock();


}

int VSSH::connectToHost()
{


  if(!session)
  {
      qDebug()<<"Session is not established";
      return -1;
     //Todo: msgbox auslagern das es abstract ist und hier fehler ausgeben
  }



  int rc = 0;

  rc = ssh_connect(session);

  if(rc != SSH_OK)
  {
      qDebug()<<"Connect failed";
      return rc;
  }
  else
  {
      emit connection_established();
  }

  return rc;

}

int VSSH::auth()
{
  int rc = 0;
  int method;

  if(!session)
  {
      qDebug()<<"Session not established";
      return -1;
  }

  method = ssh_userauth_list(session, NULL);


  if(method & SSH_AUTH_METHOD_PASSWORD)
  {
      rc = this->auth_password();
      if(rc == SSH_OK)
      {
          emit authsuccess();
      }

      return rc;
  }

  if(method & SSH_AUTH_METHOD_PUBLICKEY)
  {
     rc = this->auth_pubkey();
     if(rc == SSH_OK)
     {
         emit authsuccess();
     }
     return rc;
  }


  if(method & SSH_AUTH_METHOD_INTERACTIVE)
  {
      rc = this->auth_interactive();
      if(rc == SSH_OK)
      {
          emit authsuccess();
      }
      return rc;
  }

  QString err = "SSH Method \"" + QString::number(method) + "\" is not supported. Please contact VENTAS.";


  emit error(err);
  emit fail();

  return SSH_ERROR;
}

int VSSH::auth_pubkey()
{
  int rc = 0;

  rc = ssh_userauth_autopubkey(session, NULL);

  if(rc == SSH_AUTH_ERROR)
  {
      qDebug()<<"AUTH ERROR ON PUBLICKEY"<<ssh_get_error(session);
      return rc;
  }

  return rc;

}

int VSSH::auth_interactive()
{
  /*int nprompts, iprompt;
  const char *name, *instruction;*/

}

int VSSH::auth_password()
{
  char *user, *password;
  int rc = 0;


  if(!session)
  {

      qDebug()<<"Session not established";
      return -1;
  }
  QByteArray ba_user = this->user().toLocal8Bit();
  QByteArray ba_password = this->password().toLocal8Bit();
  user = ba_user.data();
  password = ba_password.data();
 // user = (char*) this->user().toStdString();
  //password = (char*) this->password().toStdString();
  rc = ssh_userauth_password(session, NULL, password);

  return rc;

}


int VSSH::execute(int port = 0)
{
  int rc = 0;
  if(!session)
  {

      qDebug()<<"Session not established";
      return -1;
  }


  ssh_channel channel;


  channel = ssh_channel_new(session);
  if(channel == NULL) return SSH_ERROR;

  rc = ssh_channel_open_session(channel);
  if(rc != SSH_OK)
  {

      qDebug()<<"Channel cannot open at Execute";
      ssh_channel_free(channel);
      return rc;
  }

  char *cmd = "";
  QByteArray ba_cmd = this->executeCommand().toLocal8Bit();
  cmd = ba_cmd.data();

  rc = ssh_channel_request_pty_size(channel, "xterm", 80, 24);

  if(rc != SSH_OK)
  {
      qDebug()<<"Cannot change PTY size";
  }
  else
  {

  }


  rc = ssh_channel_request_env(channel, "LANG", "de_DE.UTF-8");

  if(rc != SSH_OK)
  {
      qDebug()<<"Cannot change PTY size";
  }
  else
  {
      emit enviorment_set();
  }

  rc = ssh_channel_request_shell(channel);


  if (rc != SSH_OK)
  {
    ssh_channel_close(channel);
    ssh_channel_free(channel);
    return rc;
  }

  char buffer[512];
  unsigned int nbytes;

  QByteArray ba_test;
  QByteArray ba_buffertest;
  memset(buffer, 0, sizeof(buffer));
  nbytes = ssh_channel_read(channel, &buffer, sizeof(buffer), 0);
  bool b_test = true;
  while (ssh_channel_is_open(channel) &&
         !ssh_channel_is_eof(channel))
  {


    memset(buffer, 0, sizeof(buffer));
    ssh_mutex.lock();
    nbytes = ssh_channel_read_nonblocking(channel, &buffer, sizeof(buffer), 0);
    ssh_mutex.unlock();
    ba_test += buffer;
    ba_buffertest = buffer;




    if(!ba_buffertest.isEmpty())
       qDebug()<<buffer;

    QString qs_buffer(ba_buffertest);

    if(qs_buffer.contains("not found") && qs_buffer.contains(executeCommand()))
    {
       emit commandnotfound(0, executeCommand());
       emit fail();
    }

    if(b_test)
    {
      char exec[1000] = "";
      char l_buffer[50] = "";
      memcpy(l_buffer,"\nlogout\n", 10);
      if(port > 0)
      {
          char afglport[35] = "";
          sprintf(afglport, "export AFGLPORT=%i\n", port);
          strcat(exec, afglport);

      }
      strcat(exec, cmd);
      strcat(exec, l_buffer);
      ssh_mutex.lock();
      rc = ssh_channel_write(channel, exec, strlen(exec));
      rc = ssh_channel_send_eof(channel);
      ssh_mutex.unlock();
      emit command_executed(executeCommand());
      this->requestNewThread();
      //t_sshtunnel->programm_not_started = false;
      b_test = false;

    }
      usleep(50000L);
  }

  for(int i=0; i<ql_tunnelthreads.size(); i++)
  {
    //  QMetaObject::invokeMethod(ql_tunnelthreads.at(i), "interrupt", Qt::QueuedConnection);
      ql_tunnelthreads.at(i)->exit(0);
      ql_tunnelthreads.at(i)->session_mutex = NULL;
  }


  if (nbytes < 0)
  {
    ssh_channel_close(channel);
    ssh_channel_free(channel);
    return SSH_ERROR;
  }

  if(rc != SSH_OK)
  {

      ssh_channel_close(channel);
      ssh_channel_free(channel);
      return SSH_ERROR;

  }

  ssh_channel_close(channel);
  ssh_channel_free(channel);

  return SSH_OK;
}


/*
int VSSH::verify_knownhost()
{

  if(!session)
  {
      qDebug()<<"Session is not established";
      return;
     //Todo: msgbox auslagern das es abstract ist und hier fehler ausgeben
  }


  int state, hlen;
  unsigned char *hash = NULL;
  char *hexa;
  char buf[10];

  state = session->isServerKnown();

  hlen = ssh_get_pubkey_hash(session, &hash);
  if (hlen < 0)
    return -1;

  switch (state)
  {
    case SSH_SERVER_KNOWN_OK:
      break;

    case SSH_SERVER_KNOWN_CHANGED:
      fprintf(stderr, "Host key for server changed: it is now:\n");
      ssh_print_hexa("Public key hash", hash, hlen);
      fprintf(stderr, "For security reasons, connection will be stopped\n");
      free(hash);
      return -1;

    case SSH_SERVER_FOUND_OTHER:
      fprintf(stderr, "The host key for this server was not found but an other"
        "type of key exists.\n");
      fprintf(stderr, "An attacker might change the default server key to"
        "confuse your client into thinking the key does not exist\n");
      free(hash);
      return -1;

    case SSH_SERVER_FILE_NOT_FOUND:
      fprintf(stderr, "Could not find known host file.\n");
      fprintf(stderr, "If you accept the host key here, the file will be"
       "automatically created.\n");
      fallback to SSH_SERVER_NOT_KNOWN behavior

    case SSH_SERVER_NOT_KNOWN:
      hexa = ssh_get_hexa(hash, hlen);
      fprintf(stderr,"The server is unknown. Do you trust the host key?\n");
      fprintf(stderr, "Public key hash: %s\n", hexa);
      free(hexa);
      if (fgets(buf, sizeof(buf), stdin) == NULL)
      {
        free(hash);
        return -1;
      }
      if (strncasecmp(buf, "yes", 3) != 0)
      {
        free(hash);
        return -1;
      }
      if (ssh_write_knownhost(session) < 0)
      {
        fprintf(stderr, "Error %s\n", strerror(errno));
        free(hash);
        return -1;
      }
      break;

    case SSH_SERVER_ERROR:
      fprintf(stderr, "Error %s", ssh_get_error(session));
      free(hash);
      return -1;
  }

  free(hash);
  return 0;
}
*/


void VSSH::loadSettings()
{
  if(!session)
  {
      qDebug()<<"No session established";
      return;
  }

  int port    = 22; //Todo: Eingabemaske
  int verbose = SSH_LOG_PROTOCOL;



  //Set connection details
  const char* server;
  const char* user;
  QByteArray ba_host = this->host().toLocal8Bit();
  QByteArray ba_user = this->user().toLocal8Bit();
  //std::string server = host().toStdString();
  server = ba_host.constData();
  user   = ba_user.constData();
  ssh_options_set(session, SSH_OPTIONS_HOST, server);
  ssh_options_set(session, SSH_OPTIONS_USER, user);
  ssh_options_set(session, SSH_OPTIONS_LOG_VERBOSITY, &verbose);
  ssh_options_set(session, SSH_OPTIONS_PORT, &port);
  ssh_options_set(session, SSH_OPTIONS_COMPRESSION, "zlib@openssh.com");
  ssh_options_set(session, SSH_OPTIONS_COMPRESSION_LEVEL, "9");



}


void VSSH::setHost(QString h)
{
  this->qs_host = h;
}

QString VSSH::host()
{
  return this->qs_host;
}

void VSSH::setUser(QString u)
{
  this->qs_user = u;
}

QString VSSH::user()
{
  return this->qs_user;
}

void VSSH::setPassword(QString p)
{
  this->qs_pass = p;
}

void VSSH::setExecuteCommand(QString e)
{

  this->qs_exec = e;
}

QString VSSH::executeCommand()
{
  return this->qs_exec;
}

QString VSSH::password()
{
  return this->qs_pass;
}

void VSSH::requestNewThread()
{

    ssh_mutex.lock();
    SSHTunnel *l_t_sshtunnel = new SSHTunnel;

    l_t_sshtunnel->base_session = session;
    l_t_sshtunnel->sctunnel = NULL;
    l_t_sshtunnel->session_mutex = &ssh_mutex;
    l_t_sshtunnel->setObjectName(QString::number(cnt_tunnel));
    cnt_tunnel++;
    l_t_sshtunnel->start(QThread::NormalPriority);
    connect(l_t_sshtunnel, SIGNAL(bound()), this, SLOT(requestNewThread()));
    ql_tunnelthreads.append(l_t_sshtunnel);
    ssh_mutex.unlock();

}
