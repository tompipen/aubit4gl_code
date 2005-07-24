
//package pt.moredata.fgldocumenter.browser;
package org.aubit4gl.dbdocumenter.navigator;

/**
 * Define a forma como cada tabela � documentada
 * <BR>Estas op��es dever�o ser parametriz�veis e de alguma forma guardadas de 
 * forma persistente.
 */

class TableDocumentOptions
{
  private boolean showTableSummary;

	public boolean getShowTableSummary()
	{
	  return showTableSummary;
	}
}
