using System;
using System.Collections.Generic;
using System.Text;
using System.Net;
using System.Net.Sockets;
using System.ComponentModel;
using System.Windows.Forms;

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
        private TcpClient tcpClient;
        private IPAddress ipAddress;
        private NetworkStream stream;
        private BackgroundWorker bwReceiver;   
        
  
        public enum SocketStyle
        {
            SocketStyleLine,
            SocketStyleBlock,
            SocketStyleEnvelope
        };
        AubitNetwork.SocketStyle sockStyle;

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
                if (target != null && target.InvokeRequired)
                    target.Invoke(ConnectingFailed, new object[] { this, e });
                else
                    ConnectingFailed(this, e);
            }
        }

       public bool isConnected() {
           if (tcpClient == null) return false;
           if (tcpClient.Connected) return true;
           return false;
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
                if (target != null && target.InvokeRequired)
                    target.Invoke(ConnectingSuccessed, new object[] { this, e });
                else
                    ConnectingSuccessed(this, e);
            }
        }


        public AubitNetwork(AubitNetwork.SocketStyle s)
        {
            this.sockStyle = s;
        }

        public void SendString(string s) {
            if (sockStyle==AubitNetwork.SocketStyle.SocketStyleLine||sockStyle==AubitNetwork.SocketStyle.SocketStyleEnvelope) {
                s = s + "\n";
            }
           byte[] msg = System.Text.Encoding.ASCII.GetBytes(s);
           try
           {
               stream.Write(msg, 0, msg.Length);
           }
           catch (Exception ex)
           {
               if (this.ConnectionDied != null)
               {
                   this.ConnectionDied(stream, new EventArgs());
               }

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
                if (target != null && target.InvokeRequired)
                    target.Invoke(DisconnectedFromServer, new object[] { this, e });
                else
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
                if (target != null && target.InvokeRequired)
                    target.Invoke(ReceivedFromServer, new object[] { this, e });
                else
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
                if (target != null && target.InvokeRequired)
                    target.Invoke(ServerDisconnected, new object[] { this, e });
                else
                    ServerDisconnected(this, e);
            }
        }
         

       private void bwReceiver_doWork(object sender , DoWorkEventArgs e)
        {
            bool inEnvelope=false;
            string cmd="";
            string Envelope="";
            e.Result = true;

            while (this.tcpClient.Connected)
            {
                int index;
                //Read the command's Type.
                byte[] buffer = new byte[256];

                try
                {
                    int readBytes = this.stream.Read(buffer, 0, buffer.Length);
                    if (readBytes == 0)
                        break;
                    cmd += System.Text.Encoding.ASCII.GetString(buffer, 0, readBytes);
                } catch (Exception ex) {
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
                                this.OnReceivedFromServer(new ReceivedEventArgs(this.tcpClient, c));
                            }

                            if (c.StartsWith("</ENVELOPE>"))
                            {
                                inEnvelope = false;
                                this.OnReceivedEnvelopeFromServer( new ReceivedEventArgs(this.tcpClient, Envelope));
                                Envelope = "";
                            }
                        }

                        if (cmd.Length > index)
                        {
                            cmd = cmd.Substring(index + 1);
                            if (cmd == "\n")
                            {
                                MessageBox.Show("OOps\n");
                                cmd = "";
                            }
                        }
                        index = cmd.IndexOf('\n');
                    }
                }
            }
            this.OnServerDisconnected(new ServerEventArgs(this.tcpClient));
            this.Disconnect();
        }


        public void setEnvelopeMode()
        {
            this.sockStyle = AubitNetwork.SocketStyle.SocketStyleEnvelope;
        }

        /// <summary>
        /// Disconnect the client from the server and returns true if the client had been disconnected from the server.
        /// </summary>
        /// <returns>True if the client had been disconnected from the server,otherwise false.</returns>
        public bool Disconnect()
        {
            if (this.tcpClient != null && this.tcpClient.Connected)
            {
                try
                {
                    //this.tcpClient.Shutdown(SocketShutdown.Both);
                    this.tcpClient.Close();
                    this.bwReceiver.CancelAsync();
                    this.OnDisconnectedFromServer(new EventArgs());
                    return true;
                }
                catch
                {
                    return false;
                }

            }
            else
                return true;
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

        public void NewConnection(string server, int port)
        {
            tcpClient = new TcpClient();
            ipAddress = Dns.GetHostEntry(server).AddressList[0];
            try
            {
                tcpClient.Connect(ipAddress, port);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }

            if (bwReceiver != null)
            {
                if (bwReceiver.IsBusy)
                {
                    bwReceiver.CancelAsync();
                }
                bwReceiver = null;
            }

            if (tcpClient.Connected)
            {
                stream = tcpClient.GetStream();
                this.bwReceiver = new BackgroundWorker();
            
                bwReceiver.DoWork += new DoWorkEventHandler(bwReceiver_doWork);
                bwReceiver.WorkerSupportsCancellation = true;
                bwReceiver.RunWorkerCompleted += new RunWorkerCompletedEventHandler(bwReceiver_RunWorkerCompleted);
                bwReceiver.RunWorkerAsync();

            }
            else
            {
                stream = null;
            }
        }
    }
}
