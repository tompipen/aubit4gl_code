#include "sshtunnel.h"
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
        return; //
    }


    while(!sctunnel)
    {
       if(!base_session)
       {
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

       sctunnel = ssh_forward_accept(base_session, 10);
       if(session_mutex)
       {
           session_mutex->unlock();
       }
       usleep(500000L);
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
                     usleep(10000L);
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
          usleep(50000L);
        }



        if(!ba_readssh.isEmpty())
        {
           ph.t_tunnel = this;
           ph.request.append(ba_readssh);
           ph.start();

        }
        ba_readssh = "";


        while(!qsl_sendqueue.isEmpty())
        {
        int bytes_written = 0;

          QString resp = qsl_sendqueue.takeFirst();
          if(!resp.isEmpty())
          {
             resp.append("\n");
             if(session_mutex)
             {
                 session_mutex->lock();
             }
             bytes_written = ssh_channel_write(sctunnel, resp.toAscii().constData(), strlen(resp.toAscii().constData()));
             if(session_mutex)
             {
                 session_mutex->unlock();
             }
             if(bytes_written < 1)
             {
                 qDebug()<<"ERROR";
             }
          }
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
