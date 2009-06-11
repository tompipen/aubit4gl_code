using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace AubitDesktop
{
    public partial class frmFieldOverlay : Form
    {


        public int attributeNo
        {
            set
            {
                tbAttributeNo.Text = value.ToString();
            }
            get
            {
                return Convert.ToInt32(tbAttributeNo.Text);
            }
        }

        public decimal widgetLeft
        {
            set
            {
                if (nbLeft.Value != value)
                {
                    nbLeft.Value = value;
                }
            }
            get
            {
                return nbLeft.Value;
            }
        }

        public decimal widgetWidth
        {
            set
            {
                if (nbWidth.Value != value)
                {
                    nbWidth.Value = value;
                }
            }
            get
            {
                return nbWidth.Value;
            }
        }

        public decimal widgetHeight
        {
            set
            {
                if (nbHeight.Value != value)
                {
                    nbHeight.Value = value;
                }
            }
            get
            {
                return nbHeight.Value;
            }
        }

        public decimal widgetTop
        {
            set
            {
                if (nbTop.Value != value)
                {
                    nbTop.Value = value;
                }
            }
            get
            {
                return nbTop.Value;
            }
        }

        public string Widget
        {
            set
            {
                cbWidget.Text = value;
            }
            get
            {
                return cbWidget.Text;
            }
        }
        //public ATTRIB Attributes;


        public string action
        {
            set
            {
                tbAction.Text = value;
            }
            get
            {
                return tbAction.Text;
            }
        }

        public string createdMacro;
        public string validateMacro;

        public frmFieldOverlay()
        {
            InitializeComponent();
        }

        private void nbTop_ValueChanged(object sender, EventArgs e)
        {
            
        }

        private void nbLeft_ValueChanged(object sender, EventArgs e)
        {
            
        }

        private void nbHeight_ValueChanged(object sender, EventArgs e)
        {
           
        }

        private void nbWidth_ValueChanged(object sender, EventArgs e)
        {
           
        }
    }
}