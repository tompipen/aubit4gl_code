namespace AubitDesktop
{
    partial class AubitMessageBox
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

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.buttonBox = new Gizmox.WebGUI.Forms.FlowLayoutPanel();
            this.lbltext = new Gizmox.WebGUI.Forms.Label();
            this.lblPb = new Gizmox.WebGUI.Forms.Label();
            this.SuspendLayout();
            // 
            // buttonBox
            // 
            this.buttonBox.AutoSize = true;
            this.buttonBox.Dock = Gizmox.WebGUI.Forms.DockStyle.Bottom;
            this.buttonBox.Location = new System.Drawing.Point(0, 116);
            this.buttonBox.Name = "buttonBox";
            this.buttonBox.Size = new System.Drawing.Size(241, 0);
            this.buttonBox.TabIndex = 5;
            // 
            // lbltext
            // 
            this.lbltext.AutoSize = true;
            this.lbltext.Dock = Gizmox.WebGUI.Forms.DockStyle.Fill;
            this.lbltext.Location = new System.Drawing.Point(0, 0);
            this.lbltext.Name = "lbltext";
            this.lbltext.Size = new System.Drawing.Size(35, 13);
            this.lbltext.TabIndex = 8;
            this.lbltext.Text = "label1";
            this.lbltext.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblPb
            // 
            this.lblPb.AutoSize = true;
            this.lblPb.Dock = Gizmox.WebGUI.Forms.DockStyle.Right;
            this.lblPb.Location = new System.Drawing.Point(241, 0);
            this.lblPb.Name = "lblPb";
            this.lblPb.Size = new System.Drawing.Size(0, 13);
            this.lblPb.TabIndex = 9;
            // 
            // AubitMessageBox
            // 
            this.AutoSize = true;
            this.ClientSize = new System.Drawing.Size(241, 116);
            this.Controls.Add(this.lblPb);
            this.Controls.Add(this.lbltext);
            this.Controls.Add(this.buttonBox);
            this.Name = "AubitMessageBox";
            this.Text = "AubitMessageBox";
            this.Load += new System.EventHandler(this.AubitMessageBox_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private Gizmox.WebGUI.Forms.FlowLayoutPanel buttonBox;
        private Gizmox.WebGUI.Forms.Label lbltext;
        private Gizmox.WebGUI.Forms.Label lblPb;

    }
}
