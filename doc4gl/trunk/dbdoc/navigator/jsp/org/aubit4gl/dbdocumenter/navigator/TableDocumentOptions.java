
//package pt.moredata.fgldocumenter.browser;
package org.aubit4gl.dbdocumenter.navigator;

/**
 * Define a forma como cada tabela é documentada
 * <BR>Estas opções deverão ser parametrizáveis e de alguma forma guardadas de 
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
