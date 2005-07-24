
//package pt.moredata.fgldocumenter.browser;
package org.aubit4gl.dbdocumenter.navigator;

/**
 * <BR>Gest�o de login em JSP 
 * <BR>Integra com as API(s) ddata, nomeadamente no que se refere � utiliza��o do(s)
 * data source(s)
 * <BR>� possivel e at� prov�vel que esta classe n�o seja necess�ria
 */

class Login 
{
  private String userName = "";
  private String password = "";

	public Login() { }

	public void setUserName(String _userName)
	{
	  userName = _userName;
	}

	public void setPassword(String _password)
	{
	  password = _password;
	}

	/**
	 * Permite ao utilizador autenticar se o seu login e password s�o v�lidos
	 * para acesso � base de dados
	 */
	public boolean authenticate()
	{
	  return true;
	}
}
