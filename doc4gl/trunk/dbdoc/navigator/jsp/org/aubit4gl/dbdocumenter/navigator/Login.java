
//package pt.moredata.fgldocumenter.browser;
package org.aubit4gl.dbdocumenter.navigator;

/**
 * <BR>Gestão de login em JSP 
 * <BR>Integra com as API(s) ddata, nomeadamente no que se refere à utilização do(s)
 * data source(s)
 * <BR>É possivel e até provável que esta classe não seja necessária
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
	 * Permite ao utilizador autenticar se o seu login e password são válidos
	 * para acesso à base de dados
	 */
	public boolean authenticate()
	{
	  return true;
	}
}
