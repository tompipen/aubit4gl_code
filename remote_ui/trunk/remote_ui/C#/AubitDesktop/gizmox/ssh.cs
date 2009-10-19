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
using Tamir.SharpSsh.jsch;
using Tamir.SharpSsh;
using System.Text;
using System.Collections;
using Gizmox.WebGUI.Forms;


namespace AubitDesktop
{


    public class MyUserInfo : UserInfo, UIKeyboardInteractive
    {
        string password = "";


        public void setPassword(string val)
        {
            password = val;
        }

        public String getPassphrase()
        {
            return password;
        }

        public String getPassword()
        {
            return password;
        }

        public bool promptPassphrase(String arg0)
        {
            return true;
        }

        public bool promptPassword(String arg0)
        {
            return true;
        }

        public bool promptYesNo(String arg0)
        {
            return true;
        }

        public void showMessage(String arg0)
        {
            Program.Show(arg0);
        }

        #region UIKeyboardInteractive Members

        public string[] promptKeyboardInteractive(string destination, string name, string instruction, string[] prompt, bool[] echo)
        {
            return new string[] { password };
            
        }

        #endregion
    }



    class ssh
    {
        string remoteHost;
        string command = null;
        string userName;
        private string password;
        //UserInfo userInfo;
        int port = 22;
        protected Session session;
        private Channel channel;
        private JSch jsch = null;
        public System.IO.Stream sIn;
        public System.IO.Stream sOut;

        public ssh(string  _remoteHost, string _userName, string _password, string command_,int _port)
        {
            remoteHost = _remoteHost;
            userName = _userName;
            password = _password;
            command = command_;
            port = _port;
        }

        public void execute()
        {
            connectWithUserAndPassword();
            remoteExecute();
        }

        private void connectWithUserAndPassword()
        {


            jsch = new JSch();
            jsch.setKnownHosts("hostsfile");
            try
            {
                session = jsch.getSession(userName, remoteHost);
            }
            catch (JSchException e)
            {
                throw new ApplicationException("Cannot get session to host " +
                        remoteHost + ":" + port + " : " +
                        e.toString());
            }

            MyUserInfo ui = new MyUserInfo();
            ui.setPassword(this.password); 
           
            session.setUserInfo(ui);
            session.connect();

            //session.setPassword(password);           

            //System.Collections.Hashtable config = new Hashtable();
            //config.Add("StrictHostKeyChecking", "no");
            //Gizmox.WebGUI.Forms.Program.Show(session.getConfig("StrictHostKeyChecking"));
            //session.setConfig(config);
           
            //session.setUserInfo(new MyUserInfo(password));

            /*
            try
            {
                session.connect();
            }
            catch (JSchException e)
            {
               
                throw new ApplicationException("Cannot connect to host " +
                        remoteHost + ":" + port + " : " +
                        e.toString());
                
            }
        */
        }


        
        /**
 * Execute the remote command.
 */
        private void remoteExecute()
        {
            System.IO.Stream server;
            System.Diagnostics.Debug.WriteLine("RemoteExecute");
            try
            {
                channel = session.openChannel("exec");
            }
            catch (Exception e)
            {
                throw new ApplicationException("Cannot open channel to host " +
                        remoteHost + ":" + port + " : " +
                        e.ToString());
            }

            ((ChannelExec)channel).setCommand(command);
            //channel.setInputStream(null);
            /*
            try
            {
                sIn = channel.getInputStream();
                sOut = channel.getOutputStream();
            }
            catch (Exception e)
            {
                throw new ApplicationException("Cannot get input stream  to host " +
                        remoteHost + ":" + port + " : " +
                        e.ToString());
            }

             */
            server =   new Tamir.Streams.CombinedStream(channel.getInputStream(), channel.getOutputStream());

            try
            {
                channel.connect();
            }
            catch (Exception e)
            {
                throw new ApplicationException("Cannot execute " +
                        command + "@" + remoteHost + ":" + port + " : " +
                        e.ToString());
            }


            sIn = server;
            sOut = server;


        }

        public bool isConnected()
        {

            bool sessionConnected = false;
            bool channelConnected = false;

            if (session != null) { sessionConnected = session.isConnected(); }
            if (channel != null) { channelConnected = channel.isConnected(); }
            System.Diagnostics.Debug.WriteLine("SC=" + sessionConnected + " CC=" + channelConnected);
          //  Program.Show("SC="+sessionConnected+" CC="+channelConnected);
            return sessionConnected;
        }

        /**
         * Close the ssh connection to the 4gl program
         * TODO : Understand if I can close it and get the program working
         */
        public void Disconnect()
        {
            channel.disconnect();
            session.disconnect();
        }
    }


}



