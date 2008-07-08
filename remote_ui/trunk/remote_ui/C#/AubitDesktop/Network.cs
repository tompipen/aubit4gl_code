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
using System.Windows.Forms;
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
        private TcpClient tcpClient;

        private ssh sshExec;

        private System.IO.Stream sshStreamRead;
        private System.IO.Stream sshStreamWrite;

        private IPAddress ipAddress;
        private NetworkStream tcpStream;
        private BackgroundWorker bwReceiver;
        private bool useSSH=false;
  
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
                if (target != null && target.InvokeRequired)
                    target.Invoke(ConnectingFailed, new object[] { this, e });
                else
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
                if (target != null && target.InvokeRequired)
                    target.Invoke(ConnectingSuccessed, new object[] { this, e });
                else
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











        public void NewConnection(string server, int port,string username, string password,string application)
        {
            if (useSSH)
            {
                NewConnectionSSH(server, port, username, password,application);
            }
            else
            {
                NewConnectionTCP(server, port);
            }
        }


        public AubitNetwork(AubitNetwork.SocketStyle s)
        {
            this.sockStyle = s;
        }

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
            catch (Exception ex)
            {
                if (this.ConnectionDied != null)
                {
                    this.ConnectionDied(null, new EventArgs());
                }

            }
        }

        private void streamWrite(byte[] msg, int p, int p_3)
        {
            if (useSSH)
            {
                sshStreamWrite.Write(msg, p, p_3);
            }
            else
            {
                tcpStream.Write(msg, p, p_3);
            }
        }


       private void bwReceiver_doWork(object sender , DoWorkEventArgs e)
        {
            bool inEnvelope=false;
            string cmd="";
            string Envelope="";
            e.Result = true;

            while (this.isConnected())
            {
                int index;
                //Read the command's Type.
                byte[] buffer = new byte[256];

                try
                {
                    int readBytes = streamRead(buffer, 0, buffer.Length);
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
                                this.OnReceivedFromServer(new ReceivedEventArgs(null, c));
                            }

                            if (c.StartsWith("</ENVELOPE>"))
                            {
                                inEnvelope = false;
                                this.OnReceivedEnvelopeFromServer( new ReceivedEventArgs(null, Envelope));
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

        private int streamRead(byte[] buffer, int p, int p_3)
        {
            if (useSSH)
            {
                return sshStreamRead.Read(buffer, p, p_3);
            }
            else
            {
                return tcpStream.Read(buffer, p, p_3);
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
            if (useSSH)
            {
                return Disconnect_SSH();
            }
            else
            {
                return Disconnect_TCP();
            }
        }




        public bool isConnected()
        {
            if (useSSH)
            {
                return sshExec.isConnected();
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
            {
                return true;
            }
        } 

        public void NewConnectionTCP(string server, int port)
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
                tcpStream = tcpClient.GetStream();
                this.bwReceiver = new BackgroundWorker();
            
                bwReceiver.DoWork += new DoWorkEventHandler(bwReceiver_doWork);
                bwReceiver.WorkerSupportsCancellation = true;
                bwReceiver.RunWorkerCompleted += new RunWorkerCompletedEventHandler(bwReceiver_RunWorkerCompleted);
                bwReceiver.RunWorkerAsync();

            }
            else
            {
                tcpStream = null;
            }
        }
        #endregion

        #region SSH specific routines
        public void NewConnectionSSH(string server, int port, string username, string password,string application)
        {
            if (port == 3490) port = 22;

            sshExec = new ssh(server, username,password,application, port);
            

            try
            {
                sshExec.execute();
            }
            catch (Exception e)
            {
                MessageBox.Show(e.ToString());
            }

            setEnvelopeMode();
            sshStreamWrite = sshExec.sIn;
            sshStreamRead = sshExec.sOut;
            //sshExec.RunCommand(application);

            this.bwReceiver = new BackgroundWorker();

            bwReceiver.DoWork += new DoWorkEventHandler(bwReceiver_doWork);
            bwReceiver.WorkerSupportsCancellation = true;
            bwReceiver.RunWorkerCompleted += new RunWorkerCompletedEventHandler(bwReceiver_RunWorkerCompleted);
            bwReceiver.RunWorkerAsync();
            

            /*
            sshShell = new JSch(); 
            

            sshSession=sshShell.getSession(username,server);
            
            // if we're still using the default port - switch to the default ssh port instead..
            
            sshSession.setPort(port);
            

            if (password != null) sshSession.setPassword(password);

            try
            {
                sshSession.connect();
            } catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return;
            }
            
            Channel channel=sshSession.openChannel("exec");
            ChannelExec e; 
            e=(ChannelExec)channel;
            e.setCommand(application);
            channel.connect();
            


            if (bwReceiver != null)
            {
                if (bwReceiver.IsBusy)
                {
                    bwReceiver.CancelAsync();
                }
                bwReceiver = null;
            }

            if (channel.isConnected())
            {
                sshStreamRead = channel.getOutputStream();
                sshStreamWrite = channel.getInputStream();
                this.bwReceiver = new BackgroundWorker();

                bwReceiver.DoWork += new DoWorkEventHandler(bwReceiver_doWork);
                bwReceiver.WorkerSupportsCancellation = true;
                bwReceiver.RunWorkerCompleted += new RunWorkerCompletedEventHandler(bwReceiver_RunWorkerCompleted);
                bwReceiver.RunWorkerAsync();
                sshSession.run();
                
            }
            else
            {
                sshStreamRead = null;
                sshStreamWrite = null;
            }
             * */

        }

        private bool Disconnect_SSH()
        {


            if (this.sshExec != null && this.sshExec.isConnected())
            {
                try
                {
                    //this.tcpClient.Shutdown(SocketShutdown.Both);
                    this.sshExec.Disconnect();
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
            {
                return true;
            }
        } 
#endregion
    }
}
