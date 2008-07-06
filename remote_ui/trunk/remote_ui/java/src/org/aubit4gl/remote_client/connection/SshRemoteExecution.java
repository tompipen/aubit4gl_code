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

package org.aubit4gl.remote_client.connection;

import java.io.IOException;
import java.io.InputStream;
import java.util.logging.Logger;

import com.jcraft.jsch.Channel;
import com.jcraft.jsch.ChannelExec;
import com.jcraft.jsch.JSch;
import com.jcraft.jsch.JSchException;
import com.jcraft.jsch.Session;
import com.jcraft.jsch.UserInfo;

/**
 * Execution of the remote 4gl program using ssh.
 * In the current model we just execute the remote program and wait for its 
 * connection using a normal socket.
 * 
 * In the future we can use this same socket to send and receive the SML commands.
 * With little effort I think it can be done with the stdout mode.
 * 
 * @author Sérgio Ferreira
 *
 */
public class SshRemoteExecution {
	Logger logger = Logger.getLogger(this.getClass().getName());
	String remoteHost;
	String command = null;
	String privateKeyFile;
	String userName;
	private String password;
	UserInfo userInfo;
	int port = 22;

	protected Session session;
	private Channel channel;
	private JSch jsch = null;

	/**
	 * A socket that connects with ssh to a remote host that have a sshd working.
	 * 
	 * @param host
	 */
	public SshRemoteExecution(String _remoteHost, String _userName, String _password,String command_) 
	{
		remoteHost = _remoteHost;
		userName = _userName;
		password = _password;
		command = command_;
	}

	/**
	 * Execute the 4gl command on the remote server.
	 * 
	 * @throws FGLUIException The connection was not properly established 
	 */
	public void execute() throws FGLUIException {
		connectWithUserAndPassword();
		remoteExecute();
	}

	/**
	 * Connect to the 4gl server with ssh
	 */
	private void connectWithUserAndPassword() throws FGLUIException {
		jsch=new JSch();
		try {
			session = jsch.getSession(userName, remoteHost, port);
		} catch (JSchException e) {
			throw new FGLUIException("Cannot get session to host " +
					remoteHost + ":" + port + " : " +
					e.getMessage());
		}

		UserInfo ui=new UserInfo() {
			public String getPassphrase() {               
				return password;
			}

			public String getPassword() {
				return password;
			}

			public boolean promptPassphrase(String arg0) {
				return true;
			}

			public boolean promptPassword(String arg0) {
				return true;
			}

			public boolean promptYesNo(String arg0) {
				return true;
			}

			public void showMessage(String arg0) {
			}
		};
		session.setUserInfo(ui);
		try {
			session.connect();
		} catch (JSchException e) {
			throw new FGLUIException("Cannot connect to host " +
					remoteHost + ":" + port + " : " +
					e.getMessage());
		}
	}

	/**
	 * Execute the remote command.
	 */
	private void remoteExecute() throws FGLUIException {
		try {
			channel=session.openChannel("exec");
		} catch (JSchException e) {
			throw new FGLUIException("Cannot open channel to host " +
					remoteHost + ":" + port + " : " +
					e.getMessage());
		}

		((ChannelExec)channel).setCommand(command);
		channel.setInputStream(null);
		InputStream in = null;
		try {
			in=channel.getInputStream();
		} catch (IOException e) {
			throw new FGLUIException("Cannot get input stream  to host " +
					remoteHost + ":" + port + " : " +
					e.getMessage());
		}

		try {
			channel.connect();
		} catch (JSchException e) {
			throw new FGLUIException("Cannot execute " +
					command + "@" + remoteHost + ":" + port + " : " +
					e.getMessage());
		}

		// For debug only - If error ocurr should go to some place
		// TODO : Fix this piece of code
		/*
		try {
		byte[] tmp=new byte[1024];
		while(true){
			while(in.available()>0){
				int i=in.read(tmp, 0, 1024);
				if(i<0)break;
				System.out.print(new String(tmp, 0, i));
			}
			if(channel.isClosed()){
				System.out.println("exit-status: "+channel.getExitStatus());
				break;
			}
			try{Thread.sleep(1000);}catch(Exception ee){}
		}
		} catch(Exception e) {
			System.out.println("An exception has ocurred");
		}
		*/
		
	}

	/**
	 * Close the ssh connection to the 4gl program
	 * TODO : Understand if I can close it and get the program working
	 */
	public void close() {
		channel.disconnect();
		session.disconnect();
	}
}
