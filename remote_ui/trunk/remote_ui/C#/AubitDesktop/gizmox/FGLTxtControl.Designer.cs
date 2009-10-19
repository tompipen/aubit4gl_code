namespace AubitDesktop
{
    partial class FGLTxtControl
    {
        /// <summary> 
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary> 
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.textBox1 = new Gizmox.WebGUI.Forms.TextBox();
            this.label1 = new Gizmox.WebGUI.Forms.Label();
            this.SuspendLayout();
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(0, 0);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(100, 20);
            this.textBox1.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(3, 3);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(35, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "label1";
            // 
            // FGLTxtControl
            // 
            this.AutoSize = true;
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textBox1);
            this.Name = "FGLTxtControl";
            this.Size = new System.Drawing.Size(409, 55);
            this.Load += new System.EventHandler(this.FGLTxtControl_Load);
            this.Resize += new System.EventHandler(this.FGLTxtControl_Resize);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private Gizmox.WebGUI.Forms.TextBox textBox1;
        private Gizmox.WebGUI.Forms.Label label1;
    }
}
