namespace AubitDesktop
{
    partial class wfFileDownloader
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
            this.lblTarget = new Gizmox.WebGUI.Forms.Label();
            this.lblFilename = new Gizmox.WebGUI.Forms.Label();
            this.SuspendLayout();
            // 
            // lblTarget
            // 
            this.lblTarget.Location = new System.Drawing.Point(46, 25);
            this.lblTarget.Name = "lblTarget";
            this.lblTarget.Size = new System.Drawing.Size(216, 23);
            this.lblTarget.TabIndex = 0;
            this.lblTarget.Text = "lblTarget";
            // 
            // lblFilename
            // 
            this.lblFilename.Location = new System.Drawing.Point(46, 48);
            this.lblFilename.Name = "lblFilename";
            this.lblFilename.Size = new System.Drawing.Size(100, 23);
            this.lblFilename.TabIndex = 1;
            this.lblFilename.Text = "lblFilename";
            // 
            // wfFileDownloader
            // 
            this.Controls.Add(this.lblFilename);
            this.Controls.Add(this.lblTarget);
            this.Size = new System.Drawing.Size(298, 149);
            this.Text = "wfFileDownloader";
            this.ResumeLayout(false);

        }

        #endregion

        private Gizmox.WebGUI.Forms.Label lblTarget;
        private Gizmox.WebGUI.Forms.Label lblFilename;


    }
}