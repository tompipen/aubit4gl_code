using System;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Net;
using System.IO;
using System.Net.Sockets;

namespace AubitDesktop
{
    public partial class mainfrm : Form
    {
        private TcpListener server = null;
        private ArrayList threads = new ArrayList();
        private ArrayList AppWindows = new ArrayList();
        private string LocalAddress = "";
        private bool AllowEdit;
        private string AutoRun = "";
        private string Port;
        private bool StartMinimised;
        frmMainAppWindow AppWin;
        //ArrayList Shortcuts = new ArrayList();


        public mainfrm(bool xAllowEdit, string xAutorun, string port, bool startMinimised, bool ListenMode)
        {
            IPEndPoint lp;
            this.AllowEdit = xAllowEdit;
            InitializeComponent();
            this.AutoRun = xAutorun;
            this.Port = port;
            this.StartMinimised = startMinimised;
            this.server = new TcpListener(IPAddress.Any, Convert.ToInt32(Port));
            if (this.AllowEdit == false  )
            {
                btnShortcutAdd.Visible = false;
                btnDuplicate.Visible = false;
                btnShortcutEdit.Visible = false;
                btnShortcutRemove.Visible = false;
                btnShortcutAdd.Visible = false;
                cbAllowExec.Enabled = false;
                cbReceiveFile.Enabled = false;
                cbSendFile.Enabled = false;
                tbInterruptKey.ReadOnly =true;
            }

            if (ListenMode)
            {
                enableListeningModeToolStripMenuItem.Checked = true;
                try
                {
                    this.server.Start();
                }
                catch (Exception )
                {
                    MessageBox.Show("Unable to start socket listener, is another instance already running?", "Aubit Desktop");
                    this.Close();
                    return;
                    //Application.Exit();
                }
            }
            else
            {
                enableListeningModeToolStripMenuItem.Checked = false;
            }

            lp = (System.Net.IPEndPoint)server.LocalEndpoint;

            UseDNS();
            if (this.StartMinimised)
            {
                this.WindowState = FormWindowState.Minimized;
            }

            timer1.Enabled = true;

            //PrograLoadShortcuts();
            ShowShortcuts();


            if (Program.AppSettings.allowExec == true)
            {
                cbAllowExec.Checked = true;
            }
            else
            {
                cbAllowExec.Checked = false;
            }

            if (Program.AppSettings.allowReceiveFile == true)
            {
                cbReceiveFile.Checked = true;
            }
            else
            {
               cbReceiveFile.Checked = false;
            }

            if (Program.AppSettings.allowSendFile == true)
            {
                cbSendFile.Checked = true;
            }
            else
            {
                cbSendFile.Checked = false;
            }
            if (Program.AppSettings.interruptKey != null)
            {
                tbInterruptKey.Text = Program.AppSettings.interruptKey;
                showInterruptKeycode();
            }
            else
            {
                tbInterruptKey.Text = "Control-C";
                showInterruptKeycode();
            }
            nbYScale.Value = Program.AppSettings.yscale;
            nbXScale.Value = Program.AppSettings.xscale;

        }

        private void showInterruptKeycode()
        {
            lblKeyCode.Text = FGLUtils.getKeyCodeFromKeyName(tbInterruptKey.Text);
        }


        public void UseDNS()
        {
            string hostName = Dns.GetHostName();
            Console.WriteLine("Host Name = " + hostName);
            IPHostEntry local = Dns.GetHostEntry(hostName);
            foreach (IPAddress ipaddress in local.AddressList)
            {
                lstIPAddress.Items.Add(ipaddress.ToString());
                if (LocalAddress == "")
                {
                    LocalAddress = ipaddress.ToString();
                    lstIPAddress.SelectedIndex = 0;
                }



                //Console.WriteLine("IPAddress = " + ipaddress.ToString());
            }
        }




        private void ShowShortcuts()
        {
            lstShortcuts.Items.Clear();
            foreach (AubitDesktop.Xml.Shortcut s in Program.AppSettings.Shortcuts)
            {
                   lstShortcuts.Items.Add(s.Title);   
            }
        }



        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void btnShortcutAdd_Click(object sender, EventArgs e)
        {
            frmShortcut s = new frmShortcut(null);
            s.ShowDialog();
            
            if (s.shortcut != null)
            {
                //AubitDesktop.Xml.Shortcuts Sc;
                Program.AppSettings.Shortcuts.Add(s.shortcut);
                Program.SaveSettings();
                ShowShortcuts();
            }
            s.Close();
        }

        private void mainfrm_Move(object sender, EventArgs e)
        {
            
        }

        private void btnShortcutEdit_Click(object sender, EventArgs e)
        {
            if (lstShortcuts.SelectedIndex >= 0)
            {
                frmShortcut s = new frmShortcut(Program.AppSettings.Shortcuts[lstShortcuts.SelectedIndex]);
                s.ShowDialog();

                if (s.shortcut != null)
                {
    
                    Program.AppSettings.Shortcuts[lstShortcuts.SelectedIndex] = s.shortcut;
                    Program.SaveSettings();
                    ShowShortcuts();
                }
                s.Close();
            }
        }

        private void enableListeningModeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (enableListeningModeToolStripMenuItem.Checked)
            {
                enableListeningModeToolStripMenuItem.Checked = false;


            }
            else
            {
                enableListeningModeToolStripMenuItem.Checked = true;
            }


            if (this.server!=null)
            {
                if (enableListeningModeToolStripMenuItem.Checked)
                {
                    this.server.Start();
                }
                else
                {
                    this.server.Stop();
                }
            }

            Program.AppSettings.ListenMode = enableListeningModeToolStripMenuItem.Checked;
            Program.SaveSettings();
        }




        private void timer1_Tick(object sender, EventArgs e)
        {
            
            //bool updList = false;
            
            // Disable the time 
            timer1.Enabled = false;

            if (this.server == null || enableListeningModeToolStripMenuItem.Checked==false)
            {
                timer1.Enabled = true;
                return;
            }
            

            timer1.Enabled = false;
            if (this.server.Pending())
            {
                System.Net.IPEndPoint ep;
                //System.Net.IPEndPoint lp;
              
                TcpClient client = server.AcceptTcpClient();
                //nConnections++;
                //check_count();
                ep=(System.Net.IPEndPoint)client.Client.RemoteEndPoint;
                //Console.WriteLine(ep.Address.ToString());
                //updList = true;
                //connID++;
                AubitNetwork an;
                an = new AubitNetwork(AubitNetwork.SocketStyle.SocketStyleEnvelope,client);
                AppWin = new frmMainAppWindow(an);
                AppWin.Show();
            }
            timer1.Enabled = true;

        
        }

        private void lstShortcuts_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (lstShortcuts.SelectedIndex >= 0)
            {
                this.AcceptButton = this.btnShortcutExecute;
            }
            else
            {
                this.AcceptButton = null;
            }
        }

        private AubitDesktop.Xml.Protocol getProtocol(string code)
        {
            for (int a = 0; a < Program.AppSettings.Protocols.Length; a++)
            {
                if (Program.AppSettings.Protocols[a].Code == code)
                {
                    return Program.AppSettings.Protocols[a];
                }
            }
            return null;
        }

        private void btnShortcutExecute_Click(object sender, EventArgs e)
        {
            AubitNetwork connection;
            string userName;
            string passWord;
            AubitDesktop.Xml.Shortcut s;
            if (lstShortcuts.SelectedIndex<0) {
                MessageBox.Show("No shortcut selected");
                return;
            }
            s = Program.AppSettings.Shortcuts[lstShortcuts.SelectedIndex];

            userName = s.User;
            passWord = s.Password;
            if (s.PromptForPassword)
            {
                frmLogin flogin;
                flogin = new frmLogin();
                flogin.Username = userName;
                flogin.Password = passWord;
                if (flogin.ShowDialog(this)==DialogResult.OK) {
                    userName = flogin.Username;
                    passWord = flogin.Password;
                } else {
                    return;
                }
                flogin.Dispose();
                 

            }
            connection = createNetworkConnection(s.Server, userName, passWord, s.Application,s.Port,getProtocol(s.Protocol));

            if (connection == null) return;
             
        }


        private AubitNetwork createNetworkConnection(string server, string username, string password, string app, string port, AubitDesktop.Xml.Protocol protocol)
        {
            string cmd;
            string param;
            //frmMainAppWindow appWindow;
            
            if (app.Contains(" ")) {
                cmd=app.Substring(0,app.IndexOf(' ')-1);
                param=app.Substring(app.IndexOf(' ')+1);
            } else {
                cmd=app;
                param="";
            }

            param= param.Replace("<APPLICATION>", app);
            cmd = cmd.Replace("<APPLICATION>", app);
            param  = param.Replace("<USER>", username);
            param = param.Replace("<PASSWORD>", password);
            param = param.Replace("<SERVER>", server);
            
            param = param.Replace("<IP>", LocalAddress);

            AubitNetwork networkConnection = new AubitNetwork(AubitNetwork.SocketStyle.SocketStyleLine);

            networkConnection.application = app;

            if (protocol.ListenMode && this.enableListeningModeToolStripMenuItem.Checked==false) {
                MessageBox.Show("This protocol requires the client to be in 'Listening' mode - but that is currently disabled","Can't start shortcut",MessageBoxButtons.OK,MessageBoxIcon.Hand);
                return null;
            }
            try
            {

                if (protocol.ListenMode == false)
                {
                    // If we dont need listen mode - we need to open the connection already...
                    this.AppWin = new frmMainAppWindow(networkConnection);
                    this.AppWin.Show();
                }
 


            if (protocol.Command.ToLower() == "internal")
            {

            
                switch (protocol.Code)
                {
                    case "SSH": // Calls back
                        networkConnection.NewConnection(server, port, username, password, app, "SSH",this.AppWin);
                        if (networkConnection.isConnected())
                        {
                            // It managed it!
                            networkConnection.Disconnect();
                        }
                        else
                        {
                            MessageBox.Show("Unable to start remote application");
                        }
                        return null;
                        

                    case "SSHT":                        
                        networkConnection.NewConnection(server, port, username, password, app, "SSHT",this.AppWin);
                        if (networkConnection.isConnected())
                        {
                            AppWin.Show();
                        }
                        break;

                    case "RSH": // Calls back
                        MessageBox.Show("Not implemented yet...");
                        break;

                    case "PROXY": 
                        networkConnection.NewConnection(server, port, username, password, app, "PROXY", AppWin);

                        break;

                    case "LOCAL": // Calls back
                        System.Diagnostics.Process.Start(cmd,param);
                        return null;
                }
            }

            
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }

            if (!networkConnection.isConnected())
            {
                return null;
            }
            else
            {
                return networkConnection;
            }
        }

        private void lstShortcuts_DoubleClick(object sender, EventArgs e)
        {
            this.btnShortcutExecute.PerformClick();
        }

        private void mainfrm_Load(object sender, EventArgs e)
        {
            
            Program.setWindowPosition(this.GetType().ToString(), this);
        }



        private void mainfrm_FormClosed(object sender, FormClosedEventArgs e)
        {
            Program.saveWindowPosition(this.GetType().ToString(), this);
            Program.SaveSettings();
            
            Application.Exit();
        }

        private void tbInterruptKey_TextChanged(object sender, EventArgs e)
        {
            lblKeyCode.Text = FGLUtils.getKeyCodeFromKeyName(tbInterruptKey.Text);
        }

        private void btnDuplicate_Click(object sender, EventArgs e)
        {
            if (lstShortcuts.SelectedIndex != -1)
            {
                AubitDesktop.Xml.Shortcut s;
AubitDesktop.Xml.Shortcut snew;
                s=Program.AppSettings.Shortcuts[lstShortcuts.SelectedIndex];
                snew = new AubitDesktop.Xml.Shortcut();
                snew.Application=s.Application;
                snew.Password=s.Password;
                snew.Port=s.Port;
                snew.PromptForPassword=s.PromptForPassword;
                snew.Protocol=s.Protocol;
                snew.Server=s.Server;
                snew.Title=s.Title.Trim()+ "(Copy)";
                snew.User=s.User;


                Program.AppSettings.Shortcuts.Add(snew);
                ShowShortcuts();
                
            }
        }

        private void cbAllowExec_CheckedChanged(object sender, EventArgs e)
        {
            Program.AppSettings.allowExec = cbAllowExec.Checked;
            Program.SaveSettings();
        }

        private void cbSendFile_CheckedChanged(object sender, EventArgs e)
        {
            Program.AppSettings.allowSendFile = cbSendFile.Checked;
            Program.SaveSettings();
        }

        private void cbReceiveFile_CheckedChanged(object sender, EventArgs e)
        {
            Program.AppSettings.allowReceiveFile = this.cbReceiveFile.Checked;
            Program.SaveSettings();
        }

        private void nbYScale_ValueChanged(object sender, EventArgs e)
        {
            Program.AppSettings.yscale = (int)nbYScale.Value;
            Program.SaveSettings();
        }

        private void nbXScale_ValueChanged(object sender, EventArgs e)
        {
            Program.AppSettings.xscale = (int)nbXScale.Value;
            Program.SaveSettings();
        }
    }
}