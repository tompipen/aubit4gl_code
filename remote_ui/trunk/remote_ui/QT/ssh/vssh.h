#ifndef VSSH_H
#define VSSH_H

#include <QThread>
#include <QTime>
#ifdef SSH_USE
#include "libssh/libssh.h"
#endif

#include <ssh/sshtunnel.h>
#include <clienttcp.h>
#include <stdio.h>
#include <QMutex>
class VSSH : public QThread
{
  Q_OBJECT
public:

  void run();
  explicit VSSH(QString host, QString user, QString password, QString exec, QObject *parent = NULL);
  ~VSSH();
  void setHost(QString);
  QString host();
  void setUser(QString);
  QString user();
  void setPassword(QString);
  void setExecuteCommand(QString);
  QString executeCommand();

  void loadSettings();
  int connectToHost(); //Returns returncode
  int auth_pubkey();
  int auth();
  int auth_interactive();
  int auth_password();
  int execute(int port);
  QMutex ssh_mutex;

private:
  SSHTunnel *t_sshtunnel;
  ssh_session session;
  ssh_channel sctunnel;
  QString qs_host;
  QString qs_user;
  QString qs_pass;
  QString qs_exec;
  QString password();
  int tunnelport;
  ProtocolHandler ph;
  QStringList qsl_sendqueue;
  QList<SSHTunnel*> ql_tunnelthreads;
  int cnt_tunnel;

public slots:
  void requestNewThread();


signals:

  void authsuccess();
  void connection_established();
  void command_executed(QString);
  void enviorment_set();
  void fail();
  void authfailed(int, QString);
  void connectionfailed(int, QString);
  void commandnotfound(int, QString);
  void error(int);
  void error(QString);
  void fin();
  void waitForConnection();



public slots:

};

#endif // VSSH_H
