namespace AubitDesktop
{
    partial class ScratchPad
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
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.trackBar1 = new System.Windows.Forms.TrackBar();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.webBrowser1 = new System.Windows.Forms.WebBrowser();
            this.flowLayoutPanel1 = new System.Windows.Forms.FlowLayoutPanel();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.textBox4 = new System.Windows.Forms.TextBox();
            this.fglTextFieldWidget1 = new AubitDesktop.FGLTextFieldWidget();
            this.fglTextFieldWidget2 = new AubitDesktop.FGLTextFieldWidget();
            this.fglTextFieldWidget3 = new AubitDesktop.FGLTextFieldWidget();
            this.fglTextFieldWidget4 = new AubitDesktop.FGLTextFieldWidget();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.tableLayoutPanel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar1)).BeginInit();
            this.flowLayoutPanel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // dataGridView1
            // 
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.EditMode = System.Windows.Forms.DataGridViewEditMode.EditProgrammatically;
            this.dataGridView1.Location = new System.Drawing.Point(26, 12);
            this.dataGridView1.MultiSelect = false;
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.ReadOnly = true;
            this.dataGridView1.RowHeadersVisible = false;
            this.dataGridView1.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dataGridView1.Size = new System.Drawing.Size(243, 155);
            this.dataGridView1.TabIndex = 4;
            // 
            // statusStrip1
            // 
            this.statusStrip1.Location = new System.Drawing.Point(0, 557);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(681, 22);
            this.statusStrip1.TabIndex = 5;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.ColumnCount = 2;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.Controls.Add(this.fglTextFieldWidget1, 0, 0);
            this.tableLayoutPanel1.Controls.Add(this.fglTextFieldWidget2, 1, 0);
            this.tableLayoutPanel1.Controls.Add(this.fglTextFieldWidget3, 0, 1);
            this.tableLayoutPanel1.Controls.Add(this.fglTextFieldWidget4, 1, 1);
            this.tableLayoutPanel1.Location = new System.Drawing.Point(294, 12);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 2;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(200, 100);
            this.tableLayoutPanel1.TabIndex = 6;
            // 
            // trackBar1
            // 
            this.trackBar1.Location = new System.Drawing.Point(500, 12);
            this.trackBar1.Name = "trackBar1";
            this.trackBar1.Orientation = System.Windows.Forms.Orientation.Vertical;
            this.trackBar1.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.trackBar1.RightToLeftLayout = true;
            this.trackBar1.Size = new System.Drawing.Size(42, 100);
            this.trackBar1.TabIndex = 7;
            this.trackBar1.TickStyle = System.Windows.Forms.TickStyle.None;
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(272, 178);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(100, 20);
            this.textBox1.TabIndex = 8;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(423, 212);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 9;
            this.button1.Text = "button1";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // webBrowser1
            // 
            this.webBrowser1.Location = new System.Drawing.Point(69, 284);
            this.webBrowser1.MinimumSize = new System.Drawing.Size(20, 20);
            this.webBrowser1.Name = "webBrowser1";
            this.webBrowser1.Size = new System.Drawing.Size(510, 250);
            this.webBrowser1.TabIndex = 10;
            this.webBrowser1.Url = new System.Uri("http://www.google.com", System.UriKind.Absolute);
            // 
            // flowLayoutPanel1
            // 
            this.flowLayoutPanel1.AutoSize = true;
            this.flowLayoutPanel1.Controls.Add(this.textBox2);
            this.flowLayoutPanel1.Controls.Add(this.textBox3);
            this.flowLayoutPanel1.Controls.Add(this.textBox4);
            this.flowLayoutPanel1.FlowDirection = System.Windows.Forms.FlowDirection.TopDown;
            this.flowLayoutPanel1.Location = new System.Drawing.Point(26, 206);
            this.flowLayoutPanel1.Name = "flowLayoutPanel1";
            this.flowLayoutPanel1.Size = new System.Drawing.Size(180, 170);
            this.flowLayoutPanel1.TabIndex = 11;
            this.flowLayoutPanel1.WrapContents = false;
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(3, 3);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(100, 20);
            this.textBox2.TabIndex = 0;
            // 
            // textBox3
            // 
            this.textBox3.Location = new System.Drawing.Point(3, 29);
            this.textBox3.Name = "textBox3";
            this.textBox3.Size = new System.Drawing.Size(100, 20);
            this.textBox3.TabIndex = 1;
            // 
            // textBox4
            // 
            this.textBox4.Location = new System.Drawing.Point(3, 55);
            this.textBox4.Name = "textBox4";
            this.textBox4.Size = new System.Drawing.Size(100, 20);
            this.textBox4.TabIndex = 2;
            // 
            // fglTextFieldWidget1
            // 
            this.fglTextFieldWidget1.afterFieldID = null;
            this.fglTextFieldWidget1.AutoNext = false;
            this.fglTextFieldWidget1.beforeFieldID = null;
            this.fglTextFieldWidget1.datatype_length = 0;
            this.fglTextFieldWidget1.Downshift = false;
            this.fglTextFieldWidget1.FieldTextChanged = true;
            this.fglTextFieldWidget1.fieldValidationFailed = null;
            this.fglTextFieldWidget1.format = null;
            this.fglTextFieldWidget1.Location = new System.Drawing.Point(3, 3);
            this.fglTextFieldWidget1.MaxLength = 32767;
            this.fglTextFieldWidget1.Name = "fglTextFieldWidget1";
            this.fglTextFieldWidget1.NoEntry = false;
            this.fglTextFieldWidget1.onActionID = null;
            this.fglTextFieldWidget1.onGotFocus = null;
            this.fglTextFieldWidget1.onUIEvent = null;
            this.fglTextFieldWidget1.Required = false;
            this.fglTextFieldWidget1.Size = new System.Drawing.Size(75, 23);
            this.fglTextFieldWidget1.TabIndex = 0;
            this.fglTextFieldWidget1.Text = "fglTextFieldWidget1";
            this.fglTextFieldWidget1.Upshift = false;
            // 
            // fglTextFieldWidget2
            // 
            this.fglTextFieldWidget2.afterFieldID = null;
            this.fglTextFieldWidget2.AutoNext = false;
            this.fglTextFieldWidget2.beforeFieldID = null;
            this.fglTextFieldWidget2.datatype_length = 0;
            this.fglTextFieldWidget2.Downshift = false;
            this.fglTextFieldWidget2.FieldTextChanged = true;
            this.fglTextFieldWidget2.fieldValidationFailed = null;
            this.fglTextFieldWidget2.format = null;
            this.fglTextFieldWidget2.Location = new System.Drawing.Point(103, 3);
            this.fglTextFieldWidget2.MaxLength = 32767;
            this.fglTextFieldWidget2.Name = "fglTextFieldWidget2";
            this.fglTextFieldWidget2.NoEntry = false;
            this.fglTextFieldWidget2.onActionID = null;
            this.fglTextFieldWidget2.onGotFocus = null;
            this.fglTextFieldWidget2.onUIEvent = null;
            this.fglTextFieldWidget2.Required = false;
            this.fglTextFieldWidget2.Size = new System.Drawing.Size(75, 23);
            this.fglTextFieldWidget2.TabIndex = 1;
            this.fglTextFieldWidget2.Text = "fglTextFieldWidget2";
            this.fglTextFieldWidget2.Upshift = false;
            // 
            // fglTextFieldWidget3
            // 
            this.fglTextFieldWidget3.afterFieldID = null;
            this.fglTextFieldWidget3.AutoNext = false;
            this.fglTextFieldWidget3.beforeFieldID = null;
            this.fglTextFieldWidget3.datatype_length = 0;
            this.fglTextFieldWidget3.Downshift = false;
            this.fglTextFieldWidget3.FieldTextChanged = true;
            this.fglTextFieldWidget3.fieldValidationFailed = null;
            this.fglTextFieldWidget3.format = null;
            this.fglTextFieldWidget3.Location = new System.Drawing.Point(3, 53);
            this.fglTextFieldWidget3.MaxLength = 32767;
            this.fglTextFieldWidget3.Name = "fglTextFieldWidget3";
            this.fglTextFieldWidget3.NoEntry = false;
            this.fglTextFieldWidget3.onActionID = null;
            this.fglTextFieldWidget3.onGotFocus = null;
            this.fglTextFieldWidget3.onUIEvent = null;
            this.fglTextFieldWidget3.Required = false;
            this.fglTextFieldWidget3.Size = new System.Drawing.Size(75, 23);
            this.fglTextFieldWidget3.TabIndex = 2;
            this.fglTextFieldWidget3.Text = "fglTextFieldWidget3";
            this.fglTextFieldWidget3.Upshift = false;
            // 
            // fglTextFieldWidget4
            // 
            this.fglTextFieldWidget4.afterFieldID = null;
            this.fglTextFieldWidget4.AutoNext = false;
            this.fglTextFieldWidget4.beforeFieldID = null;
            this.fglTextFieldWidget4.datatype_length = 0;
            this.fglTextFieldWidget4.Downshift = false;
            this.fglTextFieldWidget4.FieldTextChanged = true;
            this.fglTextFieldWidget4.fieldValidationFailed = null;
            this.fglTextFieldWidget4.format = null;
            this.fglTextFieldWidget4.Location = new System.Drawing.Point(103, 53);
            this.fglTextFieldWidget4.MaxLength = 32767;
            this.fglTextFieldWidget4.Name = "fglTextFieldWidget4";
            this.fglTextFieldWidget4.NoEntry = false;
            this.fglTextFieldWidget4.onActionID = null;
            this.fglTextFieldWidget4.onGotFocus = null;
            this.fglTextFieldWidget4.onUIEvent = null;
            this.fglTextFieldWidget4.Required = false;
            this.fglTextFieldWidget4.Size = new System.Drawing.Size(75, 23);
            this.fglTextFieldWidget4.TabIndex = 3;
            this.fglTextFieldWidget4.Text = "fglTextFieldWidget4";
            this.fglTextFieldWidget4.Upshift = false;
            // 
            // ScratchPad
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(681, 579);
            this.Controls.Add(this.flowLayoutPanel1);
            this.Controls.Add(this.webBrowser1);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.trackBar1);
            this.Controls.Add(this.tableLayoutPanel1);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.dataGridView1);
            this.Name = "ScratchPad";
            this.Text = "ScratchPad";
            this.Load += new System.EventHandler(this.ScratchPad_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.tableLayoutPanel1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.trackBar1)).EndInit();
            this.flowLayoutPanel1.ResumeLayout(false);
            this.flowLayoutPanel1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private FGLTextFieldWidget fglTextFieldWidget1;
        private FGLTextFieldWidget fglTextFieldWidget2;
        private FGLTextFieldWidget fglTextFieldWidget3;
        private FGLTextFieldWidget fglTextFieldWidget4;
        private System.Windows.Forms.TrackBar trackBar1;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.WebBrowser webBrowser1;
        private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel1;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.TextBox textBox3;
        private System.Windows.Forms.TextBox textBox4;
    }
}