#ifndef VSSH_H
#define VSSH_H

#include <QThread>
#ifdef SSH_USE
#include <libssh/libssh.h>
#endif

class VSSH : public QThread
{
  Q_OBJECT
public:

  void run();
  explicit VSSH(QString host, QString user, QString password, QString exec, QObject *parent);
  ~VSSH();
  void setHost(QString);
  QString host();
  void setUser(QString);
  QString user();
  void setPassword(QString);
  void setExecuteCommand(QString);
  QString executeCommand();

  void loadSettings();
  int connect(); //Returns returncode
  int auth_pubkey();
  int auth();
  int auth_interactive();
  int auth_password();
  int execute();

private:
  ssh_session session;
  QString qs_host;
  QString qs_user;
  QString qs_pass;
  QString qs_exec;
  QString password();

  
signals:
  
public slots:
  
};

#endif // VSSH_H
