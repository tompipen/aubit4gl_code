package pt.moredata.fgldocumenter.browser;

/**
 * Define a forma como cada módulo é documentado
 * <BR>Estas opções deverão ser parametrizáveis e de alguma forma guardadas de
 * forma persistente.
 */

class ModuleDocumentOptions {
    private boolean showModuleSummary;
    
    /**
     * Getter of the property thart indicate if we shpuld show the module summary
     */
    public boolean getShowModuleSummary() {
        return showModuleSummary;
    }
}
