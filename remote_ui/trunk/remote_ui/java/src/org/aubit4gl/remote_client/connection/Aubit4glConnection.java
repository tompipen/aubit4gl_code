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
import java.util.ArrayList;
import java.util.concurrent.LinkedBlockingQueue;

/**
 * Concrete implementation of aubit4gl of a connection from a 4gl 
 * UI client to a 4gl program.
 * 
 * @author Sérgio Ferreira
 *
 */
public class Aubit4glConnection implements Connection, Runnable {
	// The socket and both direction streams  
	// used to communicate with the 4gl program
	private Socket socket;
	private InputStream in;
	private OutputStream out;


	LinkedBlockingQueue<ClientUICommand> commandQueue = new LinkedBlockingQueue<ClientUICommand>();
	Thread receiveThread;
	private boolean remoteProgramEnded = false;

	// Buffer(s) for receiving XML instructions waiting for a </ENVELOPE>
	private byte[] b = new byte[10240];
	private StringBuffer receiveBuffer = new StringBuffer();

	/**
	 * Constructor called by the Driver wich makes the socket connection.
	 *  
	 * @param _socket The socket already opened and it is used to comunicate with 4gl.
	 * @throws FGLUIException Throwed if there is a probem getting the streams
	 */
	protected Aubit4glConnection(Socket _socket) throws FGLUIException {
		socket = _socket;
		try {
			in = socket.getInputStream();
		} catch (IOException e) {
			throw new FGLUIException("Cannot get input stream from 4gl : " +
					e.getMessage());
		}

		try {
			out = socket.getOutputStream();
		} catch (IOException e) {
			throw new FGLUIException("Cannot get output stream from 4gl : " +
					e.getMessage());
		}
		receiveThread = new Thread(this);
		receiveThread.start();
	}

	/**
	 * Disconnect from 4gl program
	 * 
	 * @throws FGLUIException  
	 */
	public void disconnect() throws FGLUIException {
		System.out.println("Disconnect called");
		try {
			in.close();
			out.close();
			socket.close();
		} catch (IOException e) {
			throw new FGLUIException("Cannot disconnect from server " + e.getMessage());
		}
	}

	/**
	 * Get the next command from the queue and return it
	 * to the presentation layer.
	 * 
	 * This is a blocking receive. If there is nothing in the pool 
	 * stays sleeping.
	 * 
	 * The queue is filled by a different thread with a SAX parser.
	 * 
	 * @return The client command that the 4gl program sended.
	 * @throws FGLUIException 
	 */
	public ClientUICommand receive() throws FGLUIException {

		ClientUICommand command;
		try {
			command = commandQueue.take();
		} catch (InterruptedException e) {
			throw new FGLUIException("Getting commands from queue interrupted : " + e.getMessage());
		}
		return command;
	}

	/**
	 * Send an UI response to the remote 4gl program.
	 * 
	 * @param uiResponse The answer to send to the 4gl program 
	 * @throws FGLUIException When an error ocurr in sending an error is generated
	 */
	public void send(UIResponse uiResponse) throws FGLUIException {
		try {
			out.write(uiResponse.getBytes());
			//out.flush();
		} catch (IOException e) {
			throw new FGLUIException("Cannot send a response to 4gl program : " + e.getMessage());
		}
	}

	/**
	 * Starting a new thread of Connection.
	 * The new thread should receive from the socket until 
	 * EOF is reached.
	 * Each command received is inserted on the command queue.
	 */
	public void run() {
		// Receive from the things from the socket to the SAX parser
		while ( ! endOfRemoteProgram() ) {

			try {
				int numBytes = in.read(b);

				if (  numBytes > 0 ) {
					receiveBuffer.append(new String(b,0,numBytes));
				} else if ( numBytes == -1 )
					remoteProgramEnded = true;
			} catch (IOException e) {
				// TODO : Don't know what to do in the middle of the thread
				e.printStackTrace();
				break;
			}

			try {
				consumeEnvelopes();
			} catch (FGLUIException e) {
				// TODO Don't know what to do here.
				e.printStackTrace();
			}
		}
	}

	/**
	 * Consume all envelopes that stil exist on the receive buffer 
	 * @throws FGLUIException 
	 */
	private void consumeEnvelopes() throws FGLUIException {
		while ( receiveBuffer.indexOf("</ENVELOPE>") > -1 )
			consumeEnvelope();
	}

	/**
	 * Consume an envelope command if it is availables in the string buffer 
	 * check what kind of command it have and insert them to the command queue.
	 * 
	 * @throws FGLUIException 
	 */
	private void consumeEnvelope() throws FGLUIException {
		// Nothing to consume
		if ( receiveBuffer.indexOf("</ENVELOPE>") == -1 )
			return;

		int startCommand = receiveBuffer.toString().trim().indexOf("<ENVELOPE");
		if ( startCommand == -1 )
			throw new FGLUIException("An envelope without start <ENVELOPE>");
		if ( startCommand > 1 )
			throw new FGLUIException("An <ENVELOPE> did not started at the begining : " + startCommand);
		int endCommand = receiveBuffer.indexOf("</ENVELOPE>") + 11;
		String commandBuffer = receiveBuffer.substring(startCommand, endCommand);
		ArrayList<ClientUICommand> cmds =  getUICommands(commandBuffer);
		commandQueue.addAll(cmds);
		receiveBuffer.delete(startCommand, endCommand);
	}

	/**
	 * Check if the remote 4gl program told that it was terminated or 
	 * the socket died.
	 * 
	 * TODO : If it ends without end should raise some exception
	 * @return True End of remote program ocurred.
	 */
	private boolean endOfRemoteProgram() {
		if ( socket.isClosed() ) {
			System.out.println("Socket is closed");
			return true;
		}

		return remoteProgramEnded;
	}

	/**
	 * Analize the XML string of the command and instantiate the 
	 * command that is comming inside of it.
	 * 
	 * It load(s) the XML on a dom and get it.
	 * 
	 * @param xmlCommand A XML representation of the command.
	 * 
	 * @return An object representation of the command.
	 * @throws FGLUIException 
	 */
	private ArrayList<ClientUICommand> getUICommands(String xmlCommand) throws FGLUIException {
		UICommandBuilder cmdBuilder = new UICommandBuilder(xmlCommand);
		return cmdBuilder.getCommands();
	}

}
