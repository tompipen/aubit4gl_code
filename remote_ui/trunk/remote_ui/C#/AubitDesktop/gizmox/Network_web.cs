/*
 *  Copyright (c) 2008 The Aubit Development Team. 
 *  All rights reserved. See CREDITS file.
 *  
 *  
 *  This file is part of Aubit 4gl.
 *
 *  Aubit 4gl is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as 
 *  published by the Free Software Foundation.
 *
 *  Aubit 4gl is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Aubit 4gl.  If not, see <http://www.gnu.org/licenses/>.
 */

using System;
using System.Collections.Generic;
using System.Text;
using System.Net;
using System.Net.Sockets;
using System.ComponentModel;
using Gizmox.WebGUI.Forms;
using Tamir.SharpSsh;
using Tamir.SharpSsh.jsch;


namespace AubitDesktop
{

    public delegate void ServerDisconnectedEventHandler(object sender, ServerEventArgs e);
    public delegate void ConnectingFailedEventHandler(object sender, EventArgs e);
    public delegate void ConnectingSuccessedEventHandler(object sender, EventArgs e);
    public delegate void ReceivedEventHandler (object sender, ReceivedEventArgs e);
    public delegate void ReceivedEnvelopeEventHandler(object sender, ReceivedEventArgs e);
    /// <summary>
    /// Occurs when this client disconnected from the server.
    /// </summary>
    /// <param name="sender">Sender.</param>
    /// <param name="e">EventArgs.</param>
    public delegate void DisconnectedEventHandler(object sender, EventArgs e);


    public class ReceivedEventArgs : EventArgs
    {
        private TcpClient s;
       
        private string msg;

        public string Data
        {
            get
            {
                return msg;
            }

        }

        public ReceivedEventArgs(TcpClient t, string msg)
        {
            this.msg = msg;
            this.s = t;
        }

    }


    public class ServerEventArgs : EventArgs
    {
        private TcpClient tcpClient;
        /// <summary>
        /// The IP address of server.
        /// </summary>
        public IPAddress IP
        {
            get { return ((IPEndPoint)this.tcpClient.Client.RemoteEndPoint).Address; }
        }
        /// <summary>
        /// The port of server.
        /// </summary>
        public int Port
        {
            get { return ((IPEndPoint)this.tcpClient.Client.RemoteEndPoint).Port; }
        }

        public ServerEventArgs(TcpClient client)
        {
            this.tcpClient = client;
        }
    }

    public class AubitNetwork
    {
        private string connectionType;
        private TcpClient tcpClient;
        internal string server;
        internal string username;
        internal string password;
        internal string application;
        internal bool connectionFailed;
        private frmMainAppWindow _appwin=null;
        private frmMainAppWindow appwin
        {
            get
            {
                return _appwin;
            }
        }

        
        private ssh sshExec;

        private System.IO.Stream sshStreamRead;
        private System.IO.Stream sshStreamWrite;

        private IPAddress ipAddress;
        private com.thosmos.TcpStream tcpStream;
       // private BackgroundWorker bwReceiver;
        private bool useExplicitStreams;
  
        public enum SocketStyle
        {
            SocketStyleLine,
            SocketStyleBlock,
            SocketStyleEnvelope
        };
        AubitNetwork.SocketStyle sockStyle;



        // Transport agnostic methods : 
        #region TRANSPORT AGNOSTIC ROUTINES

        /// <summary>
        /// Occurs when this client failed on connecting to server.
        /// </summary>
        public event ConnectingFailedEventHandler ConnectingFailed;
        /// <summary>
        /// Occurs when this client failed on connecting to server.
        /// </summary>
        /// <param name="e">EventArgs.</param>
        protected virtual void OnConnectingFailed(EventArgs e)
        {
            if (ConnectingFailed != null)
            {
                Control target = ConnectingFailed.Target as Control;
                    ConnectingFailed(this, e);
            }
        }
        public event EventHandler ConnectionDied;


        /// <summary>
        /// Occurs when this client connected to the remote server Successfully.
        /// </summary>
        public event ConnectingSuccessedEventHandler ConnectingSuccessed;
        /// <summary>
        /// Occurs when this client connected to the remote server Successfully.
        /// </summary>
        /// <param name="e">EventArgs.</param>
        protected virtual void OnConnectingSuccessed(EventArgs e)
        {
            if (ConnectingSuccessed != null)
            {
                Control target = ConnectingSuccessed.Target as Control;
                    ConnectingSuccessed(this, e);
            }
        }






















        /// <summary>
        /// Occurs when this client disconnected from the remote server.
        /// </summary>
        public event DisconnectedEventHandler DisconnectedFromServer;
        /// <summary>
        /// Occurs when this client disconnected from the remote server.
        /// </summary>
        /// <param name="e">EventArgs.</param>
        protected virtual void OnDisconnectedFromServer(EventArgs e)
        {
            if (DisconnectedFromServer != null)
            {
                Control target = DisconnectedFromServer.Target as Control;
                    DisconnectedFromServer(this, e);
            }
        }

        
        /// <summary>
        /// Occurs when this client disconnected from the remote server.
        /// </summary>
        public event ReceivedEventHandler ReceivedFromServer;
        /// <summary>
        /// Occurs when this client disconnected from the remote server.
        /// </summary>
        /// <param name="e">EventArgs.</param>
        protected virtual void OnReceivedFromServer(ReceivedEventArgs e)
        {
            if (ReceivedFromServer != null)
            {
                Control target = ReceivedFromServer.Target as Control;
                    ReceivedFromServer(this,e);
            }
        }
        

        /// <summary>
        /// Occurs when this client disconnected from the remote server.
        /// </summary>
        public event ReceivedEnvelopeEventHandler ReceivedEnvelopeFromServer;

        /// <summary>
        /// Occurs when this client disconnected from the remote server.
        /// </summary>
        /// <param name="e">EventArgs.</param>
        protected virtual void OnReceivedEnvelopeFromServer(ReceivedEventArgs e)
        {
            int cnt = 0;
            while (ReceivedEnvelopeFromServer == null)
            {
                System.Threading.Thread.Sleep(100);
                cnt++;
                if (cnt > 40)
                {
                    MessageBox.Show(appwin,"No envelope handler ????");
                    this.Disconnect();
                    return;
                }
            }
            
            //
          ReceivedEnvelopeFromServer(this, e);

        }
    
 


        /// <summary>
        /// Occurs when the client disconnected.
        /// </summary>
        public event ServerDisconnectedEventHandler ServerDisconnected;
       
        /// <summary>
        /// Occurs when the server disconnected.
        /// </summary>        
        /// <param name="e">Server information.</param>
        protected virtual void OnServerDisconnected(ServerEventArgs e)
        {
            if (ServerDisconnected != null)
            {
                Control target = ServerDisconnected.Target as Control;
                    ServerDisconnected(this, e);
            }
        }





        public void NewConnection(string server, string port, string username, string password, string application, string ConnectionType, frmMainAppWindow appWindow)
        {
            connectionFailed = false;
            this.connectionType = ConnectionType;
            this.username = username;
            this.password = password;
            this.application = application;
            this.server = server;
            this._appwin = appWindow;



            switch (ConnectionType)
            {
                case "SSH":
                    useExplicitStreams = true;
                    NewConnectionSSH(server, port, username, password, application);
                    break;

                case "SSHT":
                    useExplicitStreams = true;
                    NewConnectionSSH(server, port, username, password, application);
                    break;

                case "PROXY":
                    useExplicitStreams = false;
                    NewConnectionTCP(server, port);
                    if (tcpStream == null)
                    {

                        this.connectionFailed = true;
                        this.OnConnectingFailed(new EventArgs());
                        return;
                    }
                    break;

                default:
                    throw new ApplicationException("Invalid Connection type");
            }
        }


        public AubitNetwork(AubitNetwork.SocketStyle s)
        {
            this.sockStyle = s;
            this.application = "Unknown";
        }


        /*
        public AubitNetwork(AubitNetwork.SocketStyle s, TcpClient c)
        {
            this.sockStyle = s;
            this.username = "Unknown";
            this.password = "Unknown";
            this.application = "Unknown";
            this.useExplicitStreams = false;
            this.tcpClient = c;

            tcpStream = new com.thosmos.TcpStream(this.tcpClient.GetStream());

            

        }
        */

        public void SendString(string s)
        {
            if (sockStyle == AubitNetwork.SocketStyle.SocketStyleLine || sockStyle == AubitNetwork.SocketStyle.SocketStyleEnvelope)
            {
                s = s + "\n";
            }
            byte[] msg = System.Text.Encoding.ASCII.GetBytes(s);
            try
            {
                streamWrite(msg, 0, msg.Length);
            }
            catch (Exception )
            {
                if (this.ConnectionDied != null)
                {
                    this.ConnectionDied(null, new EventArgs());
                }

            }
        }

        private void streamWrite(byte[] msg, int p, int p_3)
        {
            if (useExplicitStreams)
            {
                sshStreamWrite.Write(msg, p, p_3);
            }
            else
            {
                
                tcpStream.Write(msg, p, p_3);
            }
        }






        private string cmd="";
        string Envelope = "";
        bool inEnvelope = false;
       private void tcpStream_DataReceived(object sender, com.thosmos.TcpStream.TcpDataEventArgs e)
       {
           Encoding enc=null;
       //    Console.WriteLine("Got Data");

        //   Console.WriteLine("Loading encoding : " + Program.AppSettings.defaultEncoding);
           try
           {
               enc = System.Text.Encoding.GetEncoding(Program.AppSettings.defaultEncoding);
           }
           catch (Exception ex)
           {
               Console.WriteLine("Unable to load encoding : " + ex.Message);
           }

      //     Console.WriteLine("Read encoding");
            //bool inEnvelope=false;
               int index;
            //string Envelope="";
       //        Console.WriteLine("Got Data as:" + e.data);

               if (enc == null)
               {
                   cmd += e.data.ToString();
               }
               else
               {
                   cmd += enc.GetString(e.data);
               }

      //     Console.WriteLine("Converts to " + cmd);


           if (this.sockStyle == AubitNetwork.SocketStyle.SocketStyleLine || this.sockStyle == AubitNetwork.SocketStyle.SocketStyleEnvelope)
           {
            //   Console.WriteLine("Check if 1");
               index = cmd.IndexOf('\n');
               while (index >= 0)
               {
                   string c;

                   c = cmd.Substring(0, index);

                   if (c.Length > 0)
                   {
                       if (c.StartsWith("<ENVELOPE"))
                       {
                           Envelope = "";
                           inEnvelope = true;
                       }
                       if (inEnvelope && this.sockStyle == AubitNetwork.SocketStyle.SocketStyleEnvelope)
                       {
                           Envelope += (c + "\n");
                       }

                       if (!inEnvelope)
                       {
                           this.OnReceivedFromServer(new ReceivedEventArgs(null, c));
                       }

                       if (c.StartsWith("</ENVELOPE>"))
                       {

                           inEnvelope = false;


                           this.OnReceivedEnvelopeFromServer(new ReceivedEventArgs(null, Envelope));

                           Envelope = "";
                       }
                   }

                   if (cmd.Length > index)
                   {
                       cmd = cmd.Substring(index + 1);
                       if (cmd == "\n")
                       {
                           MessageBox.Show(appwin, "OOps\n");
                           cmd = "";
                       }
                   }
                   index = cmd.IndexOf('\n');
               }
           }
           else
           {
               Console.WriteLine("Check if 2");
           }
            
        }
  


        public void setEnvelopeMode()
        {
            this.sockStyle = AubitNetwork.SocketStyle.SocketStyleEnvelope;
        }


        #endregion

        #region TRANSPORT SWITCHING ROUTINES

        public bool Disconnect()
        {
            if (useExplicitStreams)
            {
                return Disconnect_SSH();
            }
            else
            {
                return Disconnect_TCP();
            }
        }


        private int streamRead(byte[] buffer, int p, int p_3)
        {
            if (useExplicitStreams)
            {
                int a = 0;
                try
                {
                    a = sshStreamRead.Read(buffer, p, p_3);
                    if (a < 0)
                    {
                        this.Disconnect();
                    }
                }
                catch (Exception e)
                {
                    MessageBox.Show(appwin,e.ToString());
                }
                return a;
            }
            else
            {

                return 0;
               // return tcpStream.Read(buffer, p, p_3);
            }

        }

        public bool isConnected()
        {
            if (useExplicitStreams)
            {
                bool isConnected;
                isConnected = sshExec.isConnected();
                return isConnected;
            }
            else
            {
                if (tcpClient == null) return false;
                if (tcpClient.Connected) return true;
            }
            return false;
        }
        #endregion



        #region TCP direct connect routines

        /// <summary>
        /// Disconnect the client from the server and returns true if the client had been disconnected from the server.
        /// </summary>
        /// <returns>True if the client had been disconnected from the server,otherwise false.</returns>
        private bool Disconnect_TCP()
        {

            if (this.tcpClient != null && this.tcpClient.Connected)
            {
                try
                {
                    //this.tcpClient.Shutdown(SocketShutdown.Both);
                    this.tcpClient.Close();
                   // this.bwReceiver.CancelAsync();
                    this.OnDisconnectedFromServer(new EventArgs());
                    return true;
                }
                catch
                {
                    return false;
                }

            }
            else
            {
                return true;
            }
        } 

        public void NewConnectionTCP(string server, string sport)
        {
            int port = Convert.ToInt32(sport);
            if (port == 0) port = 3490;
            tcpClient = new TcpClient();
            ipAddress = Dns.GetHostEntry(server).AddressList[0];
            Application.DoEvents();
            try
            {
                tcpClient.Connect(ipAddress, port);
            }
            catch (Exception ex)
            {
                MessageBox.Show(appwin,ex.Message);
                tcpStream = null;
                return;
            }

           // if (bwReceiver != null)
           // {
          //      if (bwReceiver.IsBusy)
         //       {
         //           bwReceiver.CancelAsync();
          //      }
          //      bwReceiver = null;
           // }

            if (tcpClient.Connected)
            {
                tcpStream = new com.thosmos.TcpStream(tcpClient.GetStream());

                tcpStream.DataReceived += new EventHandler<com.thosmos.TcpStream.TcpDataEventArgs>(tcpStream_DataReceived);
                tcpStream.ErrorOccurred += new EventHandler<com.thosmos.TcpStream.TcpErrorEventArgs>(tcpStream_ErrorOccurred);
                
                ReceivedFromServer += new ReceivedEventHandler(n_ReceivedFromServer);
                tcpStream.CloseOccurred += new EventHandler<com.thosmos.TcpStream.TcpCloseEventArgs>(tcpStream_CloseOccurred);
                tcpStream.BeginRead();

                

            }
            else
            {
                tcpStream = null;
            }
        }

        void tcpStream_CloseOccurred(object sender, com.thosmos.TcpStream.TcpCloseEventArgs e)
        {
            this.ConnectionDied(null, new EventArgs());
        }

        void tcpStream_ErrorOccurred(object sender, com.thosmos.TcpStream.TcpErrorEventArgs e)
        {
            Program.ShowMessage("Error Occurred:" + e.error.Message);
        }

        
        #endregion

        #region SSH specific routines
        public void NewConnectionSSH(string server, string sport, string username, string password,string application)
        {
            int port;
            if (sport == null) port = 22;
            else {
                if (sport.Trim()=="") {
                    port=22;
                } else {
                    port= Convert.ToInt32(sport);
                }
            }
            if (port == 3490) port = 22;

            sshExec = new ssh(server, username,password,application, port);
            

            try
            {
                sshExec.execute();
            }
            catch (Exception e)
            {
                MessageBox.Show(appwin,e.ToString());
            }

            if (this.connectionType == "SSH")
            { 
                // Execute only - we can finish here...
                // the program should start on the server and dial back
                // to the client in listenmode...
                return;
            }



            setEnvelopeMode();
            sshStreamWrite = sshExec.sIn;
            sshStreamRead = sshExec.sOut;
            //sshExec.RunCommand(application);

           // this.bwReceiver = new BackgroundWorker();

         //   bwReceiver.DoWork += new DoWorkEventHandler(bwReceiver_doWork);
          //  bwReceiver.WorkerSupportsCancellation = true;
          //  bwReceiver.RunWorkerCompleted += new RunWorkerCompletedEventHandler(bwReceiver_RunWorkerCompleted);
           // bwReceiver.RunWorkerAsync();
            

        
        }

        private bool Disconnect_SSH()
        {


            if (this.sshExec != null && this.sshExec.isConnected())
            {
                try
                {
                    //this.tcpClient.Shutdown(SocketShutdown.Both);
                    this.sshExec.Disconnect();
                  //  this.bwReceiver.CancelAsync();
                    this.OnDisconnectedFromServer(new EventArgs());
                    return true;
                }
                catch
                {
                    return false;
                }

            }
            else
            {
                return true;
            }
        } 
#endregion




        void n_ReceivedFromServer(object sender, ReceivedEventArgs e)
        {
        //    Console.WriteLine("Got message:"+e.Data);
            if (e.Data == "PROTOCOL?")
            {
                ((AubitNetwork)sender).SendString("UIVERSION 1.0");
                return;
            }

            if (e.Data == "PROGRAMNAME?")
            {
                ((AubitNetwork)sender).SendString(this.application);
                return;
            }

            if (e.Data == "USER?")
            {
                ((AubitNetwork)sender).SendString(this.username);
                return;
            }

            if (e.Data == "PASSWORD?")
            {
                ((AubitNetwork)sender).SendString(this.password);
                return;
            }

            if (e.Data == "START")
            {
                
                ((AubitNetwork)sender).setEnvelopeMode();
               

                appwin.ShowApplication();
                return;
            }

            if (e.Data == "FAILED TO START")
            {
                appwin.ErrorText="Application did not start - is that the correct Application name ? ";
               // MessageBox.Show(appwin,"Application did not start\nIs that the correct Application name ? ");
                this.Disconnect();
                this.connectionFailed = true;
                if (appwin.FailedToStart())
                {

                }
                
                return;
            }

            if (e.Data == "AUTHFAILED")
            {
                appwin.ErrorText = "Incorrect login details - connection refused";
                //MessageBox.Show(appwin,"Incorrect login details - connection refused");
                this.Disconnect();
                this.connectionFailed = true;
                if (appwin.FailedToStart())
                {
                    
                } 
                //stdNetworkConnection = null;
                return;
            }
            if (e.Data == "TIMEOUT")
            {
                try
                {
                    MessageBox.Show(appwin, "Timeout...");
                }
                catch (Exception )
                {

                }
                if (appwin.FailedToStart())
                {

                }
                return;
            }
            appwin.ErrorText = e.Data;
            //MessageBox.Show(appwin,e.Data);
        }
    }
}

/*
using System;
using System.Collections.Generic;
using System.Text;
using System.Net.Sockets;
using System.IO;
*/

namespace com.thosmos
{
  public class TcpStream {
    NetworkStream stream;
    public event EventHandler<TcpDataEventArgs> DataReceived;
    public event EventHandler<TcpErrorEventArgs> ErrorOccurred;
    public event EventHandler<TcpCloseEventArgs> CloseOccurred;

    public TcpStream(NetworkStream stream) {
      this.stream = stream;
        
    }

    public void Write(byte[] msg, int p, int p_3)
    {
        this.stream.Write(msg,p,p_3);
    }

    public void BeginRead() {
       // Console.WriteLine("Begin Read...");
      SocketState state = new SocketState();
      state.stream = stream;
      IAsyncResult ar = stream.BeginRead(state.data, 0, state.data.Length, handleRead, state); 
    }

    public void Send(byte[] data)
    {
      try
      {
        stream.Write(data, 0, data.Length);
      }
      catch (Exception ex)
      {
        OnError(new TcpErrorEventArgs(ex, stream));
      }
    }

    public void Send(String data)
    {
      byte[] d = Encoding.Default.GetBytes(data);
      Send(d);
    }

    public void Close()
    {
      stream.Close();
    }

    public void Close(int timeout) {
      stream.Close(timeout);
    }

    public NetworkStream BaseStream {
      get { return stream; }
    }

    void handleRead(IAsyncResult ar) {
      SocketState state = (SocketState)ar.AsyncState;
      NetworkStream stream = state.stream;
      int r;

//      Console.WriteLine("handle Read...");
      // check to see if stream has been closed
      if (!stream.CanRead)
        return;

      try {
        r = stream.EndRead(ar);
      } 
      catch (Exception ex) {
        OnError(new TcpErrorEventArgs(ex, stream));
        return;
      }

      if (r == 0)
      {
          onClose(new TcpCloseEventArgs(this.stream));
          return;
      }

        byte[] rdata = new byte[r];
      System.Buffer.BlockCopy(state.data, 0, rdata, 0, r);

      OnData(new TcpDataEventArgs(rdata));

      try
      {
        BeginRead();
      }
      catch(Exception ex)
      {
        OnError(new TcpErrorEventArgs(ex, stream));
      }
    }

    void OnData(TcpDataEventArgs args)
    {
//      Console.WriteLine("onData...");
      EventHandler<TcpDataEventArgs> temp = DataReceived;
      if (temp != null)
      {
//          Console.WriteLine("Calling temp");
          temp(this, args);
      }
      else
      {
          Console.WriteLine("Not calling temp - its null");
      }
    }

    void onClose(TcpCloseEventArgs args)
    {
//        Console.WriteLine("onClose...");
          EventHandler<TcpCloseEventArgs> temp = CloseOccurred;
          if (temp != null)
              temp(this, args);

      }

    void OnError(TcpErrorEventArgs args)
    {
//        Console.WriteLine("onError...");
      EventHandler<TcpErrorEventArgs> temp = ErrorOccurred;
      if (temp != null)
        temp(this, args);
    }


    class SocketState {
      public byte[] data = new byte[100];
      public NetworkStream stream;
    }

    public class TcpDataEventArgs : EventArgs {
      public byte[] data;
      public TcpDataEventArgs(byte[] data) {
        this.data = data;
      }
    }

    public class TcpCloseEventArgs : EventArgs
    {
        NetworkStream stream;
        public TcpCloseEventArgs(NetworkStream s)
        {
            this.stream = s;
        }
    }

    public class TcpErrorEventArgs : EventArgs {
      public Exception error;
      public NetworkStream stream;
      public TcpErrorEventArgs(Exception error, NetworkStream stream) {
        this.error = error;
        this.stream = stream;
      }
    }

    //internal int Read(byte[] buffer, int p, int p_3)
   // {
   //     throw new NotImplementedException();
   // }
  }
}
