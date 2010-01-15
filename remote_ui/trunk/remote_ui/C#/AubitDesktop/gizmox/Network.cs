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
using System.IO.Compression;


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
        private frmMainAppWindow appwin;


        bool inEnvelope = false;
        string cmd = "";
        string Envelope = "";


        
        private ssh sshExec;

        private System.IO.Stream sshStreamRead;
        private System.IO.Stream sshStreamWrite;

        private IPAddress ipAddress;
        private NetworkStream tcpStream;
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
                Application.DoEvents();
                if (cnt > 40)
                {
                    Program.Show("No envelope handler ????");
                    this.Disconnect();
                    return;
                }
            }

            Console.WriteLine("Got Message from server:" + DateTime.Now);
            //
          ReceivedEnvelopeFromServer(this, e);
          Console.WriteLine("Processed Message from server:" + DateTime.Now);
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
            this.appwin = appWindow;



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
                        
                        this.appwin.Close();
                        this.appwin.Dispose();
                        this.appwin = null;
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

        public AubitNetwork(AubitNetwork.SocketStyle s, TcpClient c)
        {
            this.sockStyle = s;
            this.username = "Unknown";
            this.password = "Unknown";
            this.application = "Unknown";
            this.useExplicitStreams = false;
            this.tcpClient = c;


            tcpStream = tcpClient.GetStream();
            

           // startNetworkReceive();
        }

        public void SendString(string s)
        {
            Console.WriteLine("Sending Message to server:" + DateTime.Now);
            if (s.Contains("<TRIGGERED") && !s.Contains("ENVELOPEID"))
            {
                MessageBox.Show("Got a triggered without an envelope ID...");
                throw new ApplicationException("Internal error...");
            }


            if (sockStyle == AubitNetwork.SocketStyle.SocketStyleLine || sockStyle == AubitNetwork.SocketStyle.SocketStyleEnvelope)
            {
                s = s + "\n";
            }
            byte[] msg = Program.remoteEncoding.GetBytes(s);
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
            Console.WriteLine("Sent Message to server:" + DateTime.Now);
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



       public  void startNetworkReceive() {
          //  byte[] buffer = new byte[100000];
            startStreamAsyncRead();
        }





       private void xxxbwReceiver_doWork(object sender , DoWorkEventArgs e)
        {
            bool inEnvelope=false;
            string cmd="";
            string Envelope = "";

            e.Result = true;

            while (true)
            {
                int index;

                //Read the command's Type.
                //System.Diagnostics.Debug.WriteLine("In loop...");
                byte[] buffer = new byte[100000];
                if (this.isConnected() == false)
                {
                    System.Diagnostics.Debug.WriteLine("Connection dropped");   
                    break;
                }



                try
                {
                    int readBytes = streamRead(buffer, 0, buffer.Length);

                    if (readBytes > 0) 
                    {

                        cmd +=Program.getLocalisedString(buffer,readBytes);
                    }
                    else
                    {
                       // break;
                    }
                } catch (Exception ) {
                    System.Diagnostics.Debug.WriteLine("Exceptioned..");
                    if (this.ConnectionDied != null)
                    {
                        this.ConnectionDied(sender, new EventArgs());
                    }
                }



                if (this.sockStyle == AubitNetwork.SocketStyle.SocketStyleLine || this.sockStyle == AubitNetwork.SocketStyle.SocketStyleEnvelope)
                {
                   
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
                                Envelope += (c+"\n");
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
                                Program.Show("OOps\n");
                                cmd = "";
                            }
                        }
                        index = cmd.IndexOf('\n');
                    }
                }
            }

            if (this.isConnected() == false)
            {
                System.Diagnostics.Debug.WriteLine("isconnected is false");
                this.OnServerDisconnected(new ServerEventArgs(this.tcpClient));
                this.Disconnect();
            }
        }

  


        public void setEnvelopeMode()
        {
            this.sockStyle = AubitNetwork.SocketStyle.SocketStyleEnvelope;
        }

        private void bwReceiver_RunWorkerCompleted(object sender, RunWorkerCompletedEventArgs e)
        {
            bool b;
            b = (bool)e.Result;

            if (b)
                this.OnConnectingFailed(new EventArgs());
            else
                this.OnConnectingSuccessed(new EventArgs());

            ((BackgroundWorker)sender).Dispose();
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


        void processBytes(byte[] bytes, int nBytes)
        {
            cmd += Program.getLocalisedString(bytes, nBytes);

            if (this.sockStyle == AubitNetwork.SocketStyle.SocketStyleLine || this.sockStyle == AubitNetwork.SocketStyle.SocketStyleEnvelope)
            {
                int index;
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
                            Program.Show("OOps\n");
                            cmd = "";
                        }
                    }
                    index = cmd.IndexOf('\n');
                }
            }
        }

        void dataReceivedSsh(IAsyncResult i)
        {
            byte[] buffer = (byte[])i.AsyncState;
            int nBytes = sshStreamRead.EndRead(i);
            if (nBytes != 0)
            {
                processBytes(buffer, nBytes);
            }
            startStreamAsyncRead();
        }

        void dataReceived(IAsyncResult i ) {
            byte[] buffer = (byte[])i.AsyncState;
            
            try
            {
                int nBytes = tcpStream.EndRead(i);
                if (nBytes != 0) { processBytes(buffer, nBytes); }
            }
            catch (Exception )
            {

            }
            startStreamAsyncRead();
        }

        private void startStreamAsyncRead()
        {
            byte[] buffer = new byte[100000];

            if (this.isConnected() == false)
            {
                System.Diagnostics.Debug.WriteLine("isconnected is false");
                this.OnServerDisconnected(new ServerEventArgs(this.tcpClient));
                this.Disconnect();
                return;
            }

            if (useExplicitStreams)
            {
                
                AsyncCallback networkReadCallback = new AsyncCallback(dataReceivedSsh);
                 sshStreamRead.BeginRead(buffer, 0, 100000, networkReadCallback, buffer);                
            }
            else
            {
                if (!tcpStream.CanRead) return; /* program probably died */

                AsyncCallback networkReadCallback = new AsyncCallback(dataReceived);
                try
                {
                    tcpStream.BeginRead(buffer, 0, 100000, networkReadCallback, buffer);
                }
                catch (Exception )
                {
                    MessageBox.Show("Disconnected?");
                }
               // tcpStream.Read(buffer, p, p_3);
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
                    Program.Show(e.ToString());
                }
                return a;
            }
            else
            {
                int n=0;
               // tcpStream.ReadTimeout = 100000000;
                try
                {
                    n =
                     tcpStream.Read(buffer, p, p_3);
                }
                catch (Exception e)
                {
                    MessageBox.Show(e.Message);
                }
                
                return n;
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
                  //  this.bwReceiver.CancelAsync();
                    this.OnDisconnectedFromServer(new EventArgs());
                    return true;
                }
                catch (Exception )
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
            
            IPAddress[] ipaddresses=  Dns.GetHostAddresses(server);
            if (ipaddresses.Length > 0) { ipAddress = ipaddresses[0]; }
            Application.DoEvents();
            try
            {
                tcpClient.Connect(ipAddress, port);
            }
            catch (Exception ex)
            {
                Program.Show(ex.Message);
                tcpStream = null;
                return;
            }
            /*
            if (bwReceiver != null)
            {
                if (bwReceiver.IsBusy)
                {
                    bwReceiver.CancelAsync();
                }
                bwReceiver = null;
            }
            */


            if (tcpClient.Connected)
            {
                tcpStream = tcpClient.GetStream();

                //this.bwReceiver = new BackgroundWorker();
                this.ReceivedFromServer += new ReceivedEventHandler(n_ReceivedFromServer);
                //bwReceiver.DoWork += new DoWorkEventHandler(bwReceiver_doWork);
                //bwReceiver.WorkerSupportsCancellation = true;
                //bwReceiver.RunWorkerCompleted += new RunWorkerCompletedEventHandler(bwReceiver_RunWorkerCompleted);        
                //bwReceiver.RunWorkerAsync();
                startNetworkReceive();

            }
            else
            {
                tcpStream = null;
            }
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
                Program.Show(e.ToString());
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

            /*
            this.bwReceiver = new BackgroundWorker();

            bwReceiver.DoWork += new DoWorkEventHandler(bwReceiver_doWork);
            bwReceiver.WorkerSupportsCancellation = true;
            bwReceiver.RunWorkerCompleted += new RunWorkerCompletedEventHandler(bwReceiver_RunWorkerCompleted);
            bwReceiver.RunWorkerAsync();
            */
            startNetworkReceive();

        
        }

        private bool Disconnect_SSH()
        {


            if (this.sshExec != null && this.sshExec.isConnected())
            {
                try
                {
                    //this.tcpClient.Shutdown(SocketShutdown.Both);
                    this.sshExec.Disconnect();
                    //this.bwReceiver.CancelAsync();
                    this.OnDisconnectedFromServer(new EventArgs());
                    return true;
                }
                catch (Exception )
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
               
                appwin.Invoke(new MethodInvoker(appwin.ShowApplication));
                //appwin.ShowApplication();
                return;
            }

            if (e.Data == "FAILED TO START")
            {
                Program.Show("Application did not start\nIs that the correct Application name ? ");
                this.Disconnect();
                this.connectionFailed = true;
                if (appwin.FailedToStart())
                {
                    appwin.Dispose();
                    appwin = null;
                }
                
                return;
            }

            if (e.Data == "AUTHFAILED")
            {
                Program.Show("Incorrect login details - connection refused");
                this.Disconnect();
                this.connectionFailed = true;
                if (appwin.FailedToStart())
                {
                    appwin.Dispose();
                    appwin = null;
                } 
                //stdNetworkConnection = null;
                return;
            }
            if (e.Data == "TIMEOUT")
            {
                Program.Show("Timeout...");
                if (appwin.FailedToStart())
                {
                    appwin.Dispose();
                    appwin = null;
                }
                return;
            }
            Program.Show(e.Data);
        }
    }
}
