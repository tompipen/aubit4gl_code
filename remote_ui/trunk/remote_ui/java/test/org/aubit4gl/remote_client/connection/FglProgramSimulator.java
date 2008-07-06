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
import java.io.OutputStream;
import java.net.Socket;
import java.util.concurrent.SynchronousQueue;

/**
 * Simulate a 4gl program sending command(s) to the remote thin UI client.
 * The intention is to use it on the unit testes for the UI client.
 * 
 * @author Sérgio Ferreira
 *
 */
public class FglProgramSimulator implements Runnable {
	private int portNumber = 1300;
	private Socket fglProg = null;
	//private InputStream fglIn;
	private OutputStream fglOut;
	private int waitingForUIClient;
	Thread fglThread;
	boolean connected = false;

	// Queue of command to send to the client.
	SynchronousQueue<ClientUICommand> commandQueue = new SynchronousQueue<ClientUICommand>();

	public FglProgramSimulator(int waitTime) {
		waitingForUIClient= waitTime;
		fglThread = new Thread(this);
		fglThread.start();
	}

	/**
	 * Execution of the thread. 
	 * The program waits some seconds until starting to send commands to the connection.
	 */
	public void run() {
		try {
			Thread.sleep(waitingForUIClient * 1000);
		} catch (InterruptedException e) {
			System.out.println("Interrupted sleep");
		}

		// Start the 4gl program simulator
		// and connect to the client UI
		try {
			fglProg = new Socket("localhost", portNumber);
		} catch (IOException e) {
			System.out.println("Cannot connect to the client: " + e.getMessage());
			return;
		}

		try {
			//fglIn = fglProg.getInputStream();
			fglOut = fglProg.getOutputStream();
		} catch (IOException e) {
			System.out.println("Cannot get input or output stream");
			return;
		}

		connected = true;
		// Sending commands to the remote client
		// TODO : I need a way to interrupt the thread
		while (true) {
			ClientUICommand cmd = null;
			try {
				cmd = commandQueue.take();
			} catch (InterruptedException e) {
				System.out.println("Someone asked to stop the program simulator");
			}
			try {
				String comm = envelopeMessage(cmd.getXml());
				fglOut.write(comm.getBytes());
			} catch (IOException e) {
				System.out.println("Error sending the command to the client " + e.getMessage());
			}
		}
	}
	
	/**
	 * Surrond a command inside an XML envelope
	 * @param xmlCommand
	 * @return
	 */
	private String envelopeMessage(String xmlCommand) {
		StringBuffer buff = new StringBuffer();
		
		buff.append("<ENVELOPE ID=\"2\">\n");
		buff.append("<COMMANDS>\n");
		buff.append(xmlCommand);
		buff.append("</COMMANDS>\n");
		buff.append("</ENVELOPE>\n");
		return buff.toString();
	}

	/**
	 * Add a UI command to the queue and the thread then dispach it to the client
	 * 
	 * @param cmd The command to be sended.
	 */
	public synchronized void addCommand(ClientUICommand cmd) {
		commandQueue.add(cmd);
	} 

	/**
	 * @return The status of the connection from the 4gl program to the UI command. 
	 */
	public synchronized boolean isConnected() {
		return connected;
	}
	
	public void disconnect() {
		
		try {
			fglOut.close();
			fglProg.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
