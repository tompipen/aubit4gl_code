package pt.moredata.fgldocumenter.browser;

/*
 * MainPanel.java
 *
 * Created on November 7, 2001, 5:47 PM
 */

/**
 * This is a candidate to be removed.
 *
 * @author  sergio
 */
public class MainPanel extends javax.swing.JPanel {

    /** Creates new form MainPanel */
    public MainPanel() {
        initComponents();
    }

    /** This method is called from within the constructor to
     * initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is
     * always regenerated by the Form Editor.
     */
    private void initComponents() {//GEN-BEGIN:initComponents
        jSplitPane1 = new javax.swing.JSplitPane();
        jSplitPane2 = new javax.swing.JSplitPane();

        setLayout(new java.awt.BorderLayout());

        jSplitPane1.setOrientation(javax.swing.JSplitPane.VERTICAL_SPLIT);
        jSplitPane1.setToolTipText("null");
        jSplitPane1.setContinuousLayout(true);
        jSplitPane1.setAutoscrolls(true);
        jSplitPane1.setLeftComponent(jSplitPane2);

        add(jSplitPane1, java.awt.BorderLayout.CENTER);

    }//GEN-END:initComponents


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JSplitPane jSplitPane2;
    private javax.swing.JSplitPane jSplitPane1;
    // End of variables declaration//GEN-END:variables

}
