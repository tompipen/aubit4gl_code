#ifndef SSHTUNNEL_H
#define SSHTUNNEL_H

#include <QThread>
#include <libssh.h>
#include <clienttcp.h>
#include <QMutex>
#include <QtCore>

class SSHTunnel : public QThread
{
    Q_OBJECT
public:
   // explicit SSHTunnel(QObject *parent = 0);
    void run();
    ssh_channel sctunnel;
    ssh_session base_session;
    ProtocolHandler ph;
    int tunnelport;
    QMutex *session_mutex;
    bool programm_not_started;

private:
    QStringList qsl_sendqueue;

    
signals:
    void bound();

    
public slots:
    void sendData(QString);
    
        void interrupt();
};

#endif // SSHTUNNEL_H
