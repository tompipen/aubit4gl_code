namespace AubitDesktop
{
    partial class wfAbout
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
            this.label1 = new Gizmox.WebGUI.Forms.Label();
            this.linkLabel1 = new Gizmox.WebGUI.Forms.LinkLabel();
            this.linkLabel2 = new Gizmox.WebGUI.Forms.LinkLabel();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(60, 50);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(296, 23);
            this.label1.TabIndex = 0;
            this.label1.Text = "Aubit4GL Web Interface";
            // 
            // linkLabel1
            // 
            this.linkLabel1.AutoSize = true;
            this.linkLabel1.Location = new System.Drawing.Point(42, 104);
            this.linkLabel1.Name = "linkLabel1";
            this.linkLabel1.Size = new System.Drawing.Size(167, 23);
            this.linkLabel1.TabIndex = 2;
            this.linkLabel1.Text = "Uses Visual Web Gui technology";
            this.linkLabel1.Url = "http://www.visualwebgui.com/";
            // 
            // linkLabel2
            // 
            this.linkLabel2.AutoSize = true;
            this.linkLabel2.Location = new System.Drawing.Point(48, 77);
            this.linkLabel2.Name = "linkLabel2";
            this.linkLabel2.Size = new System.Drawing.Size(160, 23);
            this.linkLabel2.TabIndex = 3;
            this.linkLabel2.Text = "(c) 2009 Aubit Computing Ltd";
            this.linkLabel2.Url = "http://www.aubit.com";
            // 
            // wfAbout
            // 
            this.Controls.Add(this.linkLabel2);
            this.Controls.Add(this.linkLabel1);
            this.Controls.Add(this.label1);
            this.Size = new System.Drawing.Size(243, 166);
            this.Text = "About";
            this.ResumeLayout(false);

        }

        #endregion

        private Gizmox.WebGUI.Forms.Label label1;
        private Gizmox.WebGUI.Forms.LinkLabel linkLabel1;
        private Gizmox.WebGUI.Forms.LinkLabel linkLabel2;


    }
}