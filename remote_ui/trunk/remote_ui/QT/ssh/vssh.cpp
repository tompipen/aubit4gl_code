#include "vssh.h"
#include "mainframe.h"
#include "sshtunnel.h"
#include "login.h"
#include <QDebug>

VSSH::VSSH(QString host, QString user, QString password, QString exec, QObject *parent) :
  QThread(parent)
{


  tunnelport = 0;
  session = ssh_new();

  if(!session)
  {
      qDebug()<<"Session cant be established";
      qDebug() << "SSH Error 4: ", ssh_get_error(session);
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
     //ssh_disconnect(session);
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
      qDebug() << "SSH Error 5: ", ssh_get_error(session);
      return;

  }
  //mh again again? fail!
  if(rc == SSH_ERROR || rc == SSH_AGAIN)
  {
      emit connectionfailed(rc, host());
      emit fail();
      VDC::arrowCursor();
      qDebug() << "SSH Error 6: ", ssh_get_error(session);
      return;
  }

  rc = this->auth();

  if(rc == SSH_ERROR)
  {
      VDC::arrowCursor();
      qDebug() << "SSH Error 7: ", ssh_get_error(session);
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
  qDebug() << "rc: " << QString::number(rc);
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
             qDebug() << "SSH Error 8: ", ssh_get_error(session);
             return;
         }
         else
         {
         QStringList args = QApplication::arguments();
         if(!args.contains("-squish")) {
             QMetaObject::invokeMethod(MainFrame::lastmainframe, "close", Qt::QueuedConnection);
         }
         this->execute(port);
         break;
         }
    default:
      emit authfailed(rc, user());
      emit fail();
      VDC::arrowCursor();
      qDebug() << "SSH Error 9: ", ssh_get_error(session);
      return;

    }


      ssh_mutex.lock();
      if(session != NULL)
      {
          //ssh_disconnect(session);
          if(ssh_is_connected(session))
          {
              ssh_disconnect(session);
          }
          session = NULL;
      }
      ssh_mutex.unlock();

}

int VSSH::connectToHost()
{


  if(!session)
  {
      qDebug()<<"Session is not established";
      qDebug() << "SSH Error 10: ", ssh_get_error(session);
      return -1;
     //Todo: msgbox auslagern das es abstract ist und hier fehler ausgeben
  }



  int rc = 0;

  rc = ssh_connect(session);

  if(rc != SSH_OK)
  {
      qDebug()<<"Connect failed";
      qDebug() << "SSH Error 11: ", ssh_get_error(session);
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
  int methodFound = 0;

  if(!session)
  {
      qDebug()<<"Session not established";
      qDebug() << "SSH Error 12: ", ssh_get_error(session);
      return -1;
  }

  rc = ssh_userauth_none(session, NULL);
  method = ssh_userauth_list(session, NULL);

  qDebug() << "method: " << QString::number(method);

  if(method & SSH_AUTH_METHOD_PASSWORD)
  {
      methodFound = 1;
      rc = this->auth_password();
      if(rc == SSH_OK)
      {
          emit authsuccess();
          return rc;
      }
  }

  if(method & SSH_AUTH_METHOD_INTERACTIVE)
  {
      methodFound = 1;
      rc = this->auth_interactive();
      if(rc == SSH_OK)
      {
          emit authsuccess();
          return rc;
      }
  }

  if(method & SSH_AUTH_METHOD_PUBLICKEY)
  {
     methodFound = 1;
     rc = this->auth_pubkey();
     if(rc == SSH_OK)
     {
         emit authsuccess();
         return rc;
     }
  }

  if(methodFound > 0) {
      emit authfailed(SSH_AUTH_DENIED, "");
      return SSH_ERROR;
  }

  qDebug() << "SSH Error 13: ", ssh_get_error(session);
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
      int rc = 0;
      char *password;

      QByteArray ba_password = this->password().toLocal8Bit();
      password = ba_password.data();

      rc = ssh_userauth_kbdint(session, NULL, NULL);
      while (rc == SSH_AUTH_INFO) {
          const char *instruction;
          const char *name;
          char buffer[128];
          int i, n;

          name = ssh_userauth_kbdint_getname(session);
          instruction = ssh_userauth_kbdint_getinstruction(session);
          n = ssh_userauth_kbdint_getnprompts(session);

          if (name && strlen(name) > 0) {
              printf("%s\n", name);
          }

          if (instruction && strlen(instruction) > 0) {
              printf("%s\n", instruction);
          }

          for (i = 0; i < n; i++) {
              const char *answer;
              const char *prompt;
              char echo;

              prompt = ssh_userauth_kbdint_getprompt(session, i, &echo);
              if (prompt == NULL) {
                  break;
              }

              if (echo) {
                  char *p;

                  printf("%s", prompt);

                  if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
                      return SSH_AUTH_ERROR;
                  }

                  buffer[sizeof(buffer) - 1] = '\0';
                  if ((p = strchr(buffer, '\n'))) {
                      *p = '\0';
                  }

                  if (ssh_userauth_kbdint_setanswer(session, i, buffer) < 0) {
                      return SSH_AUTH_ERROR;
                  }

                  memset(buffer, 0, strlen(buffer));
              } else {
                  if (password && strstr(prompt, "Password:")) {
                      answer = password;
                  } else {
                      buffer[0] = '\0';

                      if (ssh_getpass(prompt, buffer, sizeof(buffer), 0, 0) < 0) {
                          return SSH_AUTH_ERROR;
                      }
                      answer = buffer;
                  }
                  rc = ssh_userauth_kbdint_setanswer(session, i, answer);
                  memset(buffer, 0, sizeof(buffer));
                  if (rc < 0) {
                      return SSH_AUTH_ERROR;
                  }
              }
          }
          rc=ssh_userauth_kbdint(session,NULL,NULL);
    }
    return rc;

}

int VSSH::auth_password()
{
  char *password;
  int rc = 0;


  if(!session)
  {

      qDebug()<<"Session not established";
      qDebug() << "SSH Error 14: ", ssh_get_error(session);
      return -1;
  }
  QByteArray ba_user = this->user().toLocal8Bit();
  QByteArray ba_password = this->password().toLocal8Bit();
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
      qDebug() << "SSH Error 15: ", ssh_get_error(session);
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
      qDebug() << "SSH Error 16: ", ssh_get_error(session);
      return rc;
  }

  QByteArray ba_cmd = this->executeCommand().toLocal8Bit();
  const char *cmd = ba_cmd.data();

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
    qDebug() << "SSH Error 17: ", ssh_get_error(session);
    return rc;
  }

  char buffer[256];
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
    MainFrame *mainframe = qobject_cast<MainFrame*> (MainFrame::lastmainframe);
    if(mainframe->closeSSH == 1)
    {
        ssh_channel_send_eof(channel);
        ssh_channel_close(channel);
        ssh_disconnect(session);
        quit();
        return SSH_OK;
    }
    ssh_mutex.lock();
    nbytes = ssh_channel_read_nonblocking(channel, &buffer, sizeof(buffer), 0);
    //usleep(3);
    ssh_mutex.unlock();
    ba_test += buffer;
    ba_buffertest = buffer;




    if(!ba_buffertest.isEmpty())
       qDebug()<<buffer;

    QString qs_buffer(ba_buffertest);

    if(qs_buffer.contains(executeCommand() + ": command not found"))
    {
       emit commandnotfound(0, executeCommand());
       emit fail();
    }

    if(b_test)
    {
      char exec[1000] = "";
      char l_buffer[50] = "";
      memcpy(l_buffer,"\n", 2);
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

  //char exec[1000] = "";
  char l_buffer[50] = "";
  memcpy(l_buffer,"\nlogout\n", 10);
  rc = ssh_channel_write(channel, l_buffer, strlen(l_buffer));
  rc = ssh_channel_send_eof(channel);

  if (nbytes < 0)
  {
    ssh_channel_close(channel);
    ssh_channel_free(channel);
    qDebug() << "SSH Error 18: ", ssh_get_error(session);
    return SSH_ERROR;
  }

  if(rc != SSH_OK)
  {

      ssh_channel_close(channel);
      ssh_channel_free(channel);
      qDebug() << "SSH Error 19: ", ssh_get_error(session);
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
      qDebug() << "SSH Error 20: ", ssh_get_error(session);
      return;
  }

  int verbose = SSH_LOG_NOLOG;

  //Set connection details
  const char* server;
  const char* user;
  const char* compression;

  int port    = 22; //Todo: Eingabemaske

  QSettings settings;
  QString username = settings.value("user").toString();
  QString password = settings.value("password").toString();


  if(username == "demovm" && password == "demovm")
  {
      server = "1.78.143.248";
      this->setHost("1.78.143.248");

      user = "demouser";
      this->setUser("demouser");

      this->setPassword("bB$12g%23=)assa");

  }

  QByteArray ba_compression = QString::number(VDC::getSSHCompressionLevel()).toLocal8Bit();
  compression = ba_compression.constData();
  qDebug() << "USING COMPRESSIONS LEVEL: " << QString::number(VDC::getSSHCompressionLevel());

  QByteArray ba_host = this->host().toLocal8Bit();
  QByteArray ba_user = this->user().toLocal8Bit();
  server = ba_host.constData();
  user   = ba_user.constData();

  ssh_options_set(session, SSH_OPTIONS_HOST, server);
  ssh_options_set(session, SSH_OPTIONS_USER, user);
  ssh_options_set(session, SSH_OPTIONS_LOG_VERBOSITY, &verbose);
  ssh_options_set(session, SSH_OPTIONS_PORT, &port);

  if(VDC::readSettingsFromLocalIni("", "compression").toInt() != 1)
  {
      qDebug() << "Enabling compression...";
      ssh_options_set(session, SSH_OPTIONS_COMPRESSION, "zlib@openssh.com");
      ssh_options_set(session, SSH_OPTIONS_COMPRESSION_LEVEL, compression);
      ssh_options_set(session, SSH_OPTIONS_COMPRESSION_S_C, "yes");
  }

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
