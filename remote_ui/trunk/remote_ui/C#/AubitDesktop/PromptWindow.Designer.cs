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
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.promptLabel = new System.Windows.Forms.Label();
            this.promptTextBox = new System.Windows.Forms.TextBox();
            this.tableLayoutPanel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.AutoSize = true;
            this.tableLayoutPanel1.ColumnCount = 2;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.tableLayoutPanel1.Controls.Add(this.promptLabel, 0, 0);
            this.tableLayoutPanel1.Controls.Add(this.promptTextBox, 1, 0);
            this.tableLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel1.Location = new System.Drawing.Point(0, 0);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 1;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel1.Size = new System.Drawing.Size(191, 29);
            this.tableLayoutPanel1.TabIndex = 0;
            // 
            // promptLabel
            // 
            this.promptLabel.AutoSize = true;
            this.promptLabel.Dock = System.Windows.Forms.DockStyle.Left;
            this.promptLabel.Location = new System.Drawing.Point(3, 0);
            this.promptLabel.Name = "promptLabel";
            this.promptLabel.Size = new System.Drawing.Size(35, 29);
            this.promptLabel.TabIndex = 0;
            this.promptLabel.Text = "label1";
            this.promptLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // promptTextBox
            // 
            this.promptTextBox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.promptTextBox.Location = new System.Drawing.Point(44, 3);
            this.promptTextBox.Name = "promptTextBox";
            this.promptTextBox.Size = new System.Drawing.Size(531, 20);
            this.promptTextBox.TabIndex = 1;
            this.promptTextBox.TextChanged += new System.EventHandler(this.promptTextBox_TextChanged);
            this.promptTextBox.KeyUp += new System.Windows.Forms.KeyEventHandler(this.promptTextBox_KeyUp);
            this.promptTextBox.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.promptTextBox_KeyPress);
            // 
            // PromptWindow
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(191, 29);
            this.Controls.Add(this.tableLayoutPanel1);
            this.Name = "PromptWindow";
            this.Text = "Prompt";
            this.Load += new System.EventHandler(this.PromptWindow_Load);
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.PromptWindow_FormClosed);
            this.tableLayoutPanel1.ResumeLayout(false);
            this.tableLayoutPanel1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.Label promptLabel;
        private System.Windows.Forms.TextBox promptTextBox;
    }
}