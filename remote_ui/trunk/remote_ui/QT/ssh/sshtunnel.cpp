#include "sshtunnel.h"
#include "mainframe.h"
/*
SSHTunnel::SSHTunnel(QObject *parent) :
    QThread(parent)
{
}
*/
QMutex mutex;

void SSHTunnel::run()
{

    int counter = 0;
    programm_not_started = true;
    int rc = 0;

    if(rc != SSH_OK)
    {
        tunnelport = -1;
        qDebug() << "SSH Error 1: ", ssh_get_error(base_session);
        return; //
    }


    while(!sctunnel)
    {
        MainFrame *main = qobject_cast<MainFrame*> (MainFrame::lastmainframe);
        if(main->closeSSH == 1)
        {
            quit();
        }
       if(!base_session)
       {
           qDebug() << "SSH Error 2: ", ssh_get_error(base_session);
           return;
       }
       if(!session_mutex)
       {
           return;
       }
       if(session_mutex)
       {
           session_mutex->lock();
       }

       sctunnel = ssh_forward_accept(base_session, 0);
       if(session_mutex)
       {
           session_mutex->unlock();
       }
       waitTimer::msleep(1);
    }

    emit bound();

    while (ssh_channel_is_open(sctunnel) &&
           !ssh_channel_is_eof(sctunnel))
      {
        QByteArray ba_readssh;
        char buffer[256];
        int nbytes = 1; //Damit er wieder in die While geht
        //std::fill( buffer, buffer+ sizeof(buffer)/sizeof(buffer[0]), 0 );
        memset(buffer, 0, sizeof buffer);
        while(nbytes > 0)
        {
             if(!base_session)
             {
                qDebug() << "SSH Error 3: ", ssh_get_error(base_session);
                return;
             }
             if(session_mutex)
             {
                 session_mutex->lock();
             }
             nbytes = ssh_channel_read_nonblocking(sctunnel, &buffer, sizeof(buffer)-1, 0);
             //usleep(3);
             if(session_mutex)
             {
                 session_mutex->unlock();
             }


             if(nbytes == 0)
             {
                 counter++;

                 if(counter >= 500000)
                 {
                     waitTimer::msleep(100);
                 }
             } else {
                 counter = 0;
             }


            ba_readssh += buffer;
            //Leere Buffer
            memset(buffer, 0, sizeof buffer);
            //std::fill( buffer, buffer+ sizeof(buffer)/sizeof(buffer[0]), 0 );
        }

        //QApplication::processEvents();

        while(ph.isRunning())
        {
            waitTimer::msleep(50);
            QApplication::processEvents();
        }



        if(!ba_readssh.isEmpty())
        {
           ph.t_tunnel = this;
           ph.request.append(ba_readssh);
           ph.start();

        }
        ba_readssh = "";

        if(session_mutex)
        {
            session_mutex->lock();
        }
        while(!qsl_sendqueue.isEmpty())
        {
        int bytes_written = 0;

          QString resp = qsl_sendqueue.takeFirst();
          if(!resp.isEmpty())
          {
             resp.append("\n");
             QByteArray respText = "";

             if(ph.qs_dblocale.contains("UTF8")) {
                 respText = resp.toUtf8();
             } else {
                 respText = resp.toLatin1();
             }

             if(ssh_channel_is_open(sctunnel))
             {
                 bytes_written = ssh_channel_write(sctunnel, respText.constData(), strlen(respText.constData()));
             }

             if(bytes_written < 1)
             {
                 qDebug()<<"ERROR";
             }
          }
        }

        if(session_mutex)
        {
            session_mutex->unlock();
        }

      }

      sleep(1);

      if(sctunnel)
      {
          //ssh_channel_send_eof(sctunnel);
          if(ssh_channel_is_open(sctunnel))
          {
              if(session_mutex)
              {
                  session_mutex->lock();
              }

              ssh_channel_send_eof(sctunnel);
              ssh_channel_free(sctunnel);

              if(session_mutex)
              {
                  session_mutex->unlock();
              }
          }
          sctunnel = NULL;
      }

      ph.closeAllScreenHandler();

}

void SSHTunnel::sendData(QString str)
{
    str = str.replace("&amp;#x0A;", "&#x0A;");
    if(session_mutex)
    {
        session_mutex->lock();
    }
    qsl_sendqueue.append(str);
    if(session_mutex)
    {
        session_mutex->unlock();
    }
}

void SSHTunnel::interrupt()
{
  // session_mutex->unlock();
  // exit(0);
}
