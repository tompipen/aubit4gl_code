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

package org.aubit4gl.remote_client.swing_ui.events;

import java.awt.Dimension;
import java.awt.Toolkit;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.HashMap;

import javax.swing.JFrame;

import org.aubit4gl.remote_client.connection.FGLUIException;
import org.aubit4gl.remote_client.connection.UIResponse;

/**
 * The main 4gl key listener.
 * All components should delegate the keys on this Listener.
 * It just make something when the user type a key that 4gl can handle on 
 * a specific moment of time.
 * 
 * The keys should have a string representation and I need a convertion method
 * from 4gl to string a from java events to string.
 * 
 * Examples : a, A, CONTROL-A, F11, TAB, BACK-TAB, ALT-F1, CONTROL-ALT-D
 * 
 * @author Sérgio Ferreira
 */
public class FglKeyListener implements KeyListener {
	HashMap<String,UIResponse> listeningKeys;
	
	private String lastKey;

	public void keyPressed(KeyEvent e) {
		// TODO Auto-generated method stub
		/*
		char ch = (char)e.getKeyCode();
		if ( e.isControlDown() && e.getKeyCode() != e.VK_CONTROL )
		  System.out.println(" Key pressed : " + e.getKeyCode() + " - " + e.getKeyChar() + " - " + ch );
		 */

		//System.out.println(keyString(e));
		/*
		if ( isListeningKey(keyString(e)) )
			try {
				answerToFgl(keyString(e));
			} catch (FGLUIException e1) {
				// TODO : This should be made in other way
				e1.printStackTrace();
			}
			*/
		//System.out.println("======== KEY PRESSED =======");
		keyString(e);
	}

	/**
	 * A string representation of the key(s) that was pressed by the user. 
	 * @param e The key event that was ocurred.
	 */
	private String keyString(KeyEvent e) {
		StringBuffer s = new StringBuffer();

		if ( e.isControlDown() && e.getKeyCode() != KeyEvent.VK_CONTROL )
			s.append("CONTROL-");
		if ( e.isAltDown() && e.getKeyCode() != KeyEvent.VK_ALT )
			s.append("ALT-");

		switch ( e.getKeyCode() ) {
		  case KeyEvent.VK_CONTROL:
		  case KeyEvent.VK_ALT:
		  case KeyEvent.VK_SHIFT:
		  case KeyEvent.VK_CAPS_LOCK:
			  break;
		  default:
			s.append((char)e.getKeyCode());
			  int sum = 0;
			  Toolkit t = Toolkit.getDefaultToolkit();
			  if ( ! e.isShiftDown() && ! t.getLockingKeyState(e.VK_CAPS_LOCK) )
				  sum = 32;
			char ch = (char) (e.getKeyCode() + sum);
			s.append(ch);
			s.append( " KEY CHAR : " + e.getKeyChar());
		    s.append( " KEY TEXT : " + e.getKeyText(e.getKeyCode()));
			s.append(" - " + e.getKeyCode());
			s.append(" key codE : " + Integer.toString(e.getKeyCode(), 10));
			System.out.println("Key recognized : <" + s + "> : " + e.getKeyChar() + " : " + e.getKeyText(e.getKeyCode()) );
		}

		return s.toString();
	}

	/**
	 * Check if a key is one of that should be handled.
	 * 
	 * @param key The key to be checked.
	 * @return True : The key should be handle. False, otherwise.
	 */
	private boolean isListeningKey(String key) {
		if ( listeningKeys == null ) {
			//System.out.println("Listening keys is null");
			return false;
		}
		if ( listeningKeys.containsKey(key)) {
			System.out.println("Is listening key");
			return true;
		}
		System.out.println("Is not listening key");
		return false;
	}

	/**
	 * Answer to 4gl with the command that is listening a specific key.
	 * The command is on an UIResponse object that know what to send to 4gl.
	 * 
	 * @param key The Key triggered
	 * @throws FGLUIException 
	 */
	private void answerToFgl(String key) throws FGLUIException {
		// TODO : Answer to 4gl
		UIResponse response = listeningKeys.get(key);
		try {
			response.send();
		} catch (FGLUIException e) {
			throw new FGLUIException("Cannot answer to 4gl " + e.getMessage());
		}
	}

	public void keyReleased(KeyEvent e) {
		// TODO Auto-generated method stub
		//System.out.println(" Key released : " + e.getKeyCode());

	}

	public void keyTyped(KeyEvent e) {
		System.out.println("======== KEY TYPED =======");
		keyString(e);
		// TODO Auto-generated method stub
		/*
		if ( isListeningKey(keyString(e)) )
			try {
				answerToFgl(keyString(e));
			} catch (FGLUIException e1) {
				// TODO : This should be made in other way
				e1.printStackTrace();
			}
			*/
		//System.out.println(" Key typed : " + e.getKeyChar());

	}

	/**
	 * Just for test.
	 * TODO : Remove when ready
	 * @param args
	 */
	public static void main(String args[]) {
		JFrame f = new JFrame();
		f.setSize(new Dimension(500,200));
		FglKeyListener kl = new FglKeyListener();
		f.addKeyListener(kl);
		char c = 68; // + 32;
		int i = c;
		c = (char)i;
		System.out.println(" Char " + c);
		System.out.println(" Int " + i);
		f.setVisible(true);
	}

	public HashMap<String, UIResponse> getListeningKeys() {
		return listeningKeys;
	}

	/**
	 * Assign the list of the keys that the user interface is listening
	 * at this time.
	 * 
	 * @param listeningKeys An hash map with the keys
	 */
	public void setListeningKeys(HashMap<String, UIResponse> listeningKeys) {
		this.listeningKeys = listeningKeys;
		System.out.println("Listening keys assigned");
	}

}
