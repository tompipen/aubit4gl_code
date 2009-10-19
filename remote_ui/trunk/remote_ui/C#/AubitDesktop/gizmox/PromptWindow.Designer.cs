namespace AubitDesktop
{
    partial class PromptWindow
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
            this.tableLayoutPanel1 = new Gizmox.WebGUI.Forms.TableLayoutPanel();
            this.promptLabel = new Gizmox.WebGUI.Forms.Label();
            this.promptTextBox = new Gizmox.WebGUI.Forms.TextBox();
            this.tableLayoutPanel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.AutoSize = true;
            this.tableLayoutPanel1.ColumnCount = 2;
            this.tableLayoutPanel1.ColumnStyles.Add(new Gizmox.WebGUI.Forms.ColumnStyle());
            this.tableLayoutPanel1.ColumnStyles.Add(new Gizmox.WebGUI.Forms.ColumnStyle());
            this.tableLayoutPanel1.Controls.Add(this.promptLabel, 0, 0);
            this.tableLayoutPanel1.Controls.Add(this.promptTextBox, 1, 0);
            this.tableLayoutPanel1.Dock = Gizmox.WebGUI.Forms.DockStyle.Fill;
            this.tableLayoutPanel1.Location = new System.Drawing.Point(0, 0);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 1;
            this.tableLayoutPanel1.RowStyles.Add(new Gizmox.WebGUI.Forms.RowStyle());
            this.tableLayoutPanel1.Size = new System.Drawing.Size(191, 29);
            this.tableLayoutPanel1.TabIndex = 0;
            // 
            // promptLabel
            // 
            this.promptLabel.AutoSize = true;
            this.promptLabel.Dock = Gizmox.WebGUI.Forms.DockStyle.Left;
            this.promptLabel.Location = new System.Drawing.Point(3, 0);
            this.promptLabel.Name = "promptLabel";
            this.promptLabel.Size = new System.Drawing.Size(35, 29);
            this.promptLabel.TabIndex = 0;
            this.promptLabel.Text = "label1";
            this.promptLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // promptTextBox
            // 
            this.promptTextBox.Dock = Gizmox.WebGUI.Forms.DockStyle.Fill;
            this.promptTextBox.Location = new System.Drawing.Point(44, 3);
            this.promptTextBox.Name = "promptTextBox";
            this.promptTextBox.Size = new System.Drawing.Size(531, 20);
            this.promptTextBox.TabIndex = 1;
            this.promptTextBox.TextChanged += new System.EventHandler(this.promptTextBox_TextChanged);
            this.promptTextBox.KeyUp += new Gizmox.WebGUI.Forms.KeyEventHandler(this.promptTextBox_KeyUp);
            this.promptTextBox.KeyPress += new Gizmox.WebGUI.Forms.KeyPressEventHandler(this.promptTextBox_KeyPress);
            // 
            // PromptWindow
            // 
            this.ClientSize = new System.Drawing.Size(191, 29);
            this.Controls.Add(this.tableLayoutPanel1);
            this.Name = "PromptWindow";
            this.Text = "Prompt";
            this.Load += new System.EventHandler(this.PromptWindow_Load);
            this.tableLayoutPanel1.ResumeLayout(false);
            this.tableLayoutPanel1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private Gizmox.WebGUI.Forms.TableLayoutPanel tableLayoutPanel1;
        private Gizmox.WebGUI.Forms.Label promptLabel;
        private Gizmox.WebGUI.Forms.TextBox promptTextBox;
    }
}
