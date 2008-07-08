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


namespace AubitDesktop
{
    /// <summary>
    /// A user info for getting user data
    /// </summary>
    public class MyUserInfo : UserInfo
    {
        /// <summary>
        /// Holds the user password
        /// </summary>
        private String passwd;

        public MyUserInfo(string password)
        {
            passwd = password;
        }
        /// <summary>
        /// Returns the user password
        /// </summary>
        public String getPassword() { 
            return passwd; 
        }
        public void setPassword(string p) { 
            passwd = p; 
        }

        /// <summary>
        /// Prompt the user for a Yes/No input
        /// </summary>
        public bool promptYesNo(String str)
        {
            return true;
        }

        /// <summary>
        /// Returns the user passphrase (passwd for the private key file)
        /// </summary>
        public String getPassphrase() { 
            return passwd; 
        }

        /// <summary>
        /// Prompt the user for a passphrase (passwd for the private key file)
        /// </summary>
        public bool promptPassphrase(String message) { 
            return true; 
        }

        /// <summary>
        /// Prompt the user for a password
        /// </summary>\
        public bool promptPassword(String message)
        {
            return true;
        }

        /// <summary>
        /// Shows a message to the user
        /// </summary>
        public void showMessage(String message)
        {
            System.Windows.Forms.MessageBox.Show(message);
        }
    }



    class ssh
    {
        string remoteHost;
        string command = null;
        string privateKeyFile;
        string userName;
        private string password;
        UserInfo userInfo;
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
            try
            {
                session = jsch.getSession(userName, remoteHost, port);
            }
            catch (JSchException e)
            {
                throw new ApplicationException("Cannot get session to host " +
                        remoteHost + ":" + port + " : " +
                        e.toString());
            }

            
            Hashtable config = new Hashtable();
            //config.Add("StrictHostKeyChecking", "no");
            //System.Windows.Forms.MessageBox.Show(session.getConfig("StrictHostKeyChecking"));
            //session.setConfig(config);
           
            session.setUserInfo(new MyUserInfo(password));
            //session.setPassword(password);
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
        }


        
        /**
 * Execute the remote command.
 */
        private void remoteExecute()
        {
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
            channel.setInputStream(null);
            //System.IO.Stream inStream = null;
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



        }

        public bool isConnected()
        {
            if (session == null) return false;
            return session.isConnected();
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


