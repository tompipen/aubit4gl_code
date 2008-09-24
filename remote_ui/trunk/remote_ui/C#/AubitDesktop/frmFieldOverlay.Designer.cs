namespace AubitDesktop
{
    partial class frmFieldOverlay
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
            this.tbTabname = new System.Windows.Forms.TextBox();
            this.tbColname = new System.Windows.Forms.TextBox();
            this.tbAttributeNo = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.nbTop = new System.Windows.Forms.NumericUpDown();
            this.nbLeft = new System.Windows.Forms.NumericUpDown();
            this.nbWidth = new System.Windows.Forms.NumericUpDown();
            this.nbHeight = new System.Windows.Forms.NumericUpDown();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.label8 = new System.Windows.Forms.Label();
            this.tbAction = new System.Windows.Forms.TextBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.cbNoentry = new System.Windows.Forms.CheckBox();
            this.cbRequired = new System.Windows.Forms.CheckBox();
            this.tbConfig = new System.Windows.Forms.TextBox();
            this.label12 = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.cbWidget = new System.Windows.Forms.ComboBox();
            this.label10 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.cbDownshift = new System.Windows.Forms.CheckBox();
            this.cbUpshift = new System.Windows.Forms.CheckBox();
            this.btnCancel = new System.Windows.Forms.Button();
            this.btnOk = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.nbTop)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.nbLeft)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.nbWidth)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.nbHeight)).BeginInit();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // tbTabname
            // 
            this.tbTabname.Location = new System.Drawing.Point(73, 27);
            this.tbTabname.Name = "tbTabname";
            this.tbTabname.Size = new System.Drawing.Size(100, 20);
            this.tbTabname.TabIndex = 0;
            // 
            // tbColname
            // 
            this.tbColname.Location = new System.Drawing.Point(73, 53);
            this.tbColname.Name = "tbColname";
            this.tbColname.Size = new System.Drawing.Size(100, 20);
            this.tbColname.TabIndex = 1;
            // 
            // tbAttributeNo
            // 
            this.tbAttributeNo.Location = new System.Drawing.Point(73, 79);
            this.tbAttributeNo.Name = "tbAttributeNo";
            this.tbAttributeNo.Size = new System.Drawing.Size(100, 20);
            this.tbAttributeNo.TabIndex = 2;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(4, 30);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(34, 13);
            this.label1.TabIndex = 3;
            this.label1.Text = "Table";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(4, 56);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(42, 13);
            this.label2.TabIndex = 4;
            this.label2.Text = "Column";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(4, 82);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(63, 13);
            this.label3.TabIndex = 5;
            this.label3.Text = "Attribute No";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(208, 30);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(26, 13);
            this.label4.TabIndex = 6;
            this.label4.Text = "Top";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(201, 82);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(38, 13);
            this.label5.TabIndex = 7;
            this.label5.Text = "Height";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(204, 111);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(35, 13);
            this.label6.TabIndex = 8;
            this.label6.Text = "Width";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(209, 56);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(25, 13);
            this.label7.TabIndex = 9;
            this.label7.Text = "Left";
            // 
            // nbTop
            // 
            this.nbTop.Location = new System.Drawing.Point(245, 28);
            this.nbTop.Name = "nbTop";
            this.nbTop.Size = new System.Drawing.Size(70, 20);
            this.nbTop.TabIndex = 10;
            this.nbTop.ValueChanged += new System.EventHandler(this.nbTop_ValueChanged);
            // 
            // nbLeft
            // 
            this.nbLeft.Location = new System.Drawing.Point(245, 53);
            this.nbLeft.Name = "nbLeft";
            this.nbLeft.Size = new System.Drawing.Size(70, 20);
            this.nbLeft.TabIndex = 11;
            this.nbLeft.ValueChanged += new System.EventHandler(this.nbLeft_ValueChanged);
            // 
            // nbWidth
            // 
            this.nbWidth.Location = new System.Drawing.Point(245, 109);
            this.nbWidth.Name = "nbWidth";
            this.nbWidth.Size = new System.Drawing.Size(70, 20);
            this.nbWidth.TabIndex = 12;
            this.nbWidth.ValueChanged += new System.EventHandler(this.nbWidth_ValueChanged);
            // 
            // nbHeight
            // 
            this.nbHeight.Location = new System.Drawing.Point(245, 80);
            this.nbHeight.Name = "nbHeight";
            this.nbHeight.Size = new System.Drawing.Size(70, 20);
            this.nbHeight.TabIndex = 13;
            this.nbHeight.ValueChanged += new System.EventHandler(this.nbHeight_ValueChanged);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(7, 146);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(124, 23);
            this.button1.TabIndex = 14;
            this.button1.Text = "Edit Validation Macro";
            this.button1.UseVisualStyleBackColor = true;
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(191, 146);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(124, 23);
            this.button2.TabIndex = 15;
            this.button2.Text = "Edit Load Macro";
            this.button2.UseVisualStyleBackColor = true;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(4, 111);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(37, 13);
            this.label8.TabIndex = 16;
            this.label8.Text = "Action";
            // 
            // tbAction
            // 
            this.tbAction.Location = new System.Drawing.Point(73, 108);
            this.tbAction.Name = "tbAction";
            this.tbAction.Size = new System.Drawing.Size(100, 20);
            this.tbAction.TabIndex = 17;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.cbNoentry);
            this.groupBox1.Controls.Add(this.cbRequired);
            this.groupBox1.Controls.Add(this.tbConfig);
            this.groupBox1.Controls.Add(this.label12);
            this.groupBox1.Controls.Add(this.label11);
            this.groupBox1.Controls.Add(this.cbWidget);
            this.groupBox1.Controls.Add(this.label10);
            this.groupBox1.Controls.Add(this.label9);
            this.groupBox1.Controls.Add(this.textBox2);
            this.groupBox1.Controls.Add(this.textBox1);
            this.groupBox1.Controls.Add(this.cbDownshift);
            this.groupBox1.Controls.Add(this.cbUpshift);
            this.groupBox1.Location = new System.Drawing.Point(7, 187);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(308, 129);
            this.groupBox1.TabIndex = 18;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Attributes";
            // 
            // cbNoentry
            // 
            this.cbNoentry.AutoSize = true;
            this.cbNoentry.Location = new System.Drawing.Point(17, 88);
            this.cbNoentry.Name = "cbNoentry";
            this.cbNoentry.Size = new System.Drawing.Size(63, 17);
            this.cbNoentry.TabIndex = 11;
            this.cbNoentry.Text = "Noentry";
            this.cbNoentry.UseVisualStyleBackColor = true;
            // 
            // cbRequired
            // 
            this.cbRequired.AutoSize = true;
            this.cbRequired.Location = new System.Drawing.Point(17, 65);
            this.cbRequired.Name = "cbRequired";
            this.cbRequired.Size = new System.Drawing.Size(69, 17);
            this.cbRequired.TabIndex = 10;
            this.cbRequired.Text = "Required";
            this.cbRequired.UseVisualStyleBackColor = true;
            // 
            // tbConfig
            // 
            this.tbConfig.Location = new System.Drawing.Point(197, 96);
            this.tbConfig.Name = "tbConfig";
            this.tbConfig.Size = new System.Drawing.Size(100, 20);
            this.tbConfig.TabIndex = 9;
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(127, 99);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(37, 13);
            this.label12.TabIndex = 8;
            this.label12.Text = "Config";
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(127, 72);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(41, 13);
            this.label11.TabIndex = 7;
            this.label11.Text = "Widget";
            // 
            // cbWidget
            // 
            this.cbWidget.FormattingEnabled = true;
            this.cbWidget.Location = new System.Drawing.Point(197, 69);
            this.cbWidget.Name = "cbWidget";
            this.cbWidget.Size = new System.Drawing.Size(100, 21);
            this.cbWidget.TabIndex = 6;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(127, 46);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(56, 13);
            this.label10.TabIndex = 5;
            this.label10.Text = "Comments";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(127, 24);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(39, 13);
            this.label9.TabIndex = 4;
            this.label9.Text = "Format";
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(197, 43);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(100, 20);
            this.textBox2.TabIndex = 3;
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(197, 16);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(100, 20);
            this.textBox1.TabIndex = 2;
            // 
            // cbDownshift
            // 
            this.cbDownshift.AutoSize = true;
            this.cbDownshift.Location = new System.Drawing.Point(17, 42);
            this.cbDownshift.Name = "cbDownshift";
            this.cbDownshift.Size = new System.Drawing.Size(73, 17);
            this.cbDownshift.TabIndex = 1;
            this.cbDownshift.Text = "Downshift";
            this.cbDownshift.UseVisualStyleBackColor = true;
            // 
            // cbUpshift
            // 
            this.cbUpshift.AutoSize = true;
            this.cbUpshift.Location = new System.Drawing.Point(17, 19);
            this.cbUpshift.Name = "cbUpshift";
            this.cbUpshift.Size = new System.Drawing.Size(59, 17);
            this.cbUpshift.TabIndex = 0;
            this.cbUpshift.Text = "Upshift";
            this.cbUpshift.UseVisualStyleBackColor = true;
            // 
            // btnCancel
            // 
            this.btnCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnCancel.Location = new System.Drawing.Point(240, 322);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(75, 23);
            this.btnCancel.TabIndex = 19;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.UseVisualStyleBackColor = true;
            // 
            // btnOk
            // 
            this.btnOk.Location = new System.Drawing.Point(149, 322);
            this.btnOk.Name = "btnOk";
            this.btnOk.Size = new System.Drawing.Size(75, 23);
            this.btnOk.TabIndex = 20;
            this.btnOk.Text = "OK";
            this.btnOk.UseVisualStyleBackColor = true;
            // 
            // frmFieldOverlay
            // 
            this.AcceptButton = this.btnOk;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.CancelButton = this.btnCancel;
            this.ClientSize = new System.Drawing.Size(326, 356);
            this.Controls.Add(this.btnOk);
            this.Controls.Add(this.btnCancel);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.tbAction);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.nbHeight);
            this.Controls.Add(this.nbWidth);
            this.Controls.Add(this.nbLeft);
            this.Controls.Add(this.nbTop);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.tbAttributeNo);
            this.Controls.Add(this.tbColname);
            this.Controls.Add(this.tbTabname);
            this.Name = "frmFieldOverlay";
            this.Text = "Field Overlay";
            ((System.ComponentModel.ISupportInitialize)(this.nbTop)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.nbLeft)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.nbWidth)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.nbHeight)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox tbTabname;
        private System.Windows.Forms.TextBox tbColname;
        private System.Windows.Forms.TextBox tbAttributeNo;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.NumericUpDown nbTop;
        private System.Windows.Forms.NumericUpDown nbLeft;
        private System.Windows.Forms.NumericUpDown nbWidth;
        private System.Windows.Forms.NumericUpDown nbHeight;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.TextBox tbAction;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.CheckBox cbUpshift;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.CheckBox cbDownshift;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.ComboBox cbWidget;
        private System.Windows.Forms.TextBox tbConfig;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.CheckBox cbRequired;
        private System.Windows.Forms.CheckBox cbNoentry;
        private System.Windows.Forms.Button btnCancel;
        private System.Windows.Forms.Button btnOk;
    }
}