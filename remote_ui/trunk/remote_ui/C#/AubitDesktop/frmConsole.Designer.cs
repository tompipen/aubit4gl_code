namespace AubitDesktop
{
    partial class frmConsole
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
            this.txtConsoleText = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // txtConsoleText
            // 
            this.txtConsoleText.Dock = System.Windows.Forms.DockStyle.Fill;
            this.txtConsoleText.Enabled = false;
            this.txtConsoleText.Location = new System.Drawing.Point(0, 0);
            this.txtConsoleText.Multiline = true;
            this.txtConsoleText.Name = "txtConsoleText";
            this.txtConsoleText.Size = new System.Drawing.Size(785, 398);
            this.txtConsoleText.TabIndex = 0;
            // 
            // frmConsole
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(785, 398);
            this.Controls.Add(this.txtConsoleText);
            this.Name = "frmConsole";
            this.Text = "Console";
            this.Load += new System.EventHandler(this.frmConsole_Load);
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.frmConsole_FormClosed);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txtConsoleText;
    }
}