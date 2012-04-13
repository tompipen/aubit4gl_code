#include "vssh.h"
#include <QDebug>

VSSH::VSSH(QString host, QString user, QString password, QString exec, QObject *parent) :
  QThread(parent)
{


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
  ssh_free(session);
}

void VSSH::run()
{

  int rc = 0;
  this->loadSettings();
  this->connect();
  rc = this->auth();
  if(rc == SSH_AUTH_SUCCESS)
  {
      this->execute();
  }

}

int VSSH::connect()
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
      return rc;
  }

  if(method & SSH_AUTH_METHOD_PUBLICKEY)
  {
     rc = this->auth_pubkey();
     return rc;
  }


  if(method & SSH_AUTH_METHOD_INTERACTIVE)
  {
      rc = this->auth_interactive();
      return rc;
  }

  qFatal("SSH METHOD NOT SUPPORTED");
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
  int nprompts, iprompt;
  const char *name, *instruction;

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

int VSSH::execute()
{

  if(!session)
  {

      qDebug()<<"Session not established";
      return -1;
  }

  ssh_channel channel;
  int rc = 0;

  channel = ssh_channel_new(session);
  if(channel == NULL) return SSH_ERROR;

  rc = ssh_channel_open_session(channel);
  if(rc != SSH_OK)
  {

      qDebug()<<"Channel cannot open at Execute";
      ssh_channel_free(channel);
      return rc;
  }

  const char *cmd;
  QByteArray ba_cmd = this->executeCommand().toUtf8();
  cmd = ba_cmd.constData();
//  strncpy(cmd, this->executeCommand().toAscii(), 1024);


/*
  rc = ssh_channel_request_pty(channel);

  if(rc != SSH_OK)
  {
      qDebug()<<"PTY cannot requested";
  }
*/
  rc = ssh_channel_request_pty_size(channel, "xterm", 80, 24);

  if(rc != SSH_OK)
  {
      qDebug()<<"Cannot change PTY size";
  }


  rc = ssh_channel_request_env(channel, "LANG", "de_DE.UTF-8");

  if(rc != SSH_OK)
  {
      qDebug()<<"Cannot change PTY size";
  }

  rc = ssh_channel_request_shell(channel);


  if (rc != SSH_OK)
  {
    ssh_channel_close(channel);
    ssh_channel_free(channel);
    return rc;
  }

  char buffer[256];
  unsigned int nbytes;

  QByteArray ba_test;

  memset(buffer, 0, sizeof(buffer));
  nbytes = ssh_channel_read(channel, &buffer, sizeof(buffer), 0);
  bool b_test = true;
  while (ssh_channel_is_open(channel) &&
         !ssh_channel_is_eof(channel))
  {
    ba_test += buffer;
    qDebug()<<buffer;
      /*


    if (fwrite(&buffer, 1, nbytes, stdout) != nbytes)
    {
      ssh_channel_close(channel);
      ssh_channel_free(channel);
      return SSH_ERROR;
    }*/

    memset(buffer, 0, sizeof(buffer));
    nbytes = ssh_channel_read_nonblocking(channel, &buffer, sizeof(buffer), 0);
    if(b_test)
    {
       // const *char = "/opt/ventas/bin/vdc" + Q;
      char *exec;
      char buffer[10];
      QByteArray ba_exec = this->executeCommand().toLocal8Bit();
      exec = ba_exec.data();
      memcpy(buffer,"\nlogout\n", 9);
      strcat(exec, buffer);
      rc = ssh_channel_write(channel, exec, 13);
      rc = ssh_channel_send_eof(channel);
      b_test = false;
    }
      usleep(50000L);
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
