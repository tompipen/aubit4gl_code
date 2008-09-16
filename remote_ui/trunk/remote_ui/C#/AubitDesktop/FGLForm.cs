/*
 *  Copyright (c) 2008 The Aubit Development Team. 
 *  All rights reserved. See CREDITS file.
 *  
 *  
 *  This file is part of Aubit 4gl.
 *
 *  Aubit 4gl is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as 
 *  published by the Free Software Foundation.
 *
 *  Aubit 4gl is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Aubit 4gl.  If not, see <http://www.gnu.org/licenses/>.
 */

using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.Drawing;
using System.Windows.Forms;
using System.Xml.Serialization;
using System.Xml;
using System.IO;

namespace AubitDesktop
{

    class FGLForm
    {
        private List<FGLWidget> fields;
        //private List<Label> labels;
        private List<FGLScreenRecord> ScreenRecords;
        
        public int maxcol;
        public int maxline;
        //int n = 0;
        Panel thisFormsPanel;
        private ToolTip tooltips;

        

        public Control control
        {
            get
            {
                return (Control)thisFormsPanel;
            }
        }


        public FGLForm()
        {
            this.fields = null;
            thisFormsPanel = null;
        }


        #region XML Form handling

        void addLayoutToParentForXmlForm(Control parent, object child)
        {

            string detectedType;
            detectedType = child.GetType().ToString();
            //this.thisFormsPanel.Controls.Add(fld.WindowsWidget);

            switch (detectedType)
            {
                #region VBOX
                case "AubitDesktop.Xml.XMLForm.VBox":
                    {
                        AubitDesktop.Xml.XMLForm.VBox p;
                        p = (AubitDesktop.Xml.XMLForm.VBox)child;

                        FlowLayoutPanel thisLayoutControlsPanel;
                        p = (AubitDesktop.Xml.XMLForm.VBox)child;

                        thisLayoutControlsPanel = new FlowLayoutPanel();
                        thisLayoutControlsPanel.Visible = true;
                        thisLayoutControlsPanel.Top = 0;
                        thisLayoutControlsPanel.Left = 0;
                        thisLayoutControlsPanel.AutoSize = true;
                        thisLayoutControlsPanel.FlowDirection = FlowDirection.TopDown;
                        parent.Controls.Add(thisLayoutControlsPanel);

                        foreach (object a in p.Items)
                        {
                            addLayoutToParentForXmlForm(thisLayoutControlsPanel, a);
                        }

                    }
                    break;
                #endregion
                #region HBOX
                case "AubitDesktop.Xml.XMLForm.HBox":
                    {
                        AubitDesktop.Xml.XMLForm.HBox p;
                        p = (AubitDesktop.Xml.XMLForm.HBox)child;
                        FlowLayoutPanel thisLayoutControlsPanel;
                        

                        thisLayoutControlsPanel = new FlowLayoutPanel();
                        thisLayoutControlsPanel.Visible = true;
                        thisLayoutControlsPanel.Top = 0;
                        thisLayoutControlsPanel.Left = 0;
                        thisLayoutControlsPanel.AutoSize = true;
                        thisLayoutControlsPanel.FlowDirection = FlowDirection.LeftToRight;
                        parent.Controls.Add(thisLayoutControlsPanel);

                        foreach (object a in p.Items)
                        {
                            addLayoutToParentForXmlForm(thisLayoutControlsPanel, a);
                        }
                    }
                    break;
                #endregion
                #region Table
                case "AubitDesktop.Xml.XMLForm.Table":
                    {
                        AubitDesktop.Xml.XMLForm.Table p;
                        p = (AubitDesktop.Xml.XMLForm.Table)child;
                    }
                    break;
                #endregion
                #region Grid
                case "AubitDesktop.Xml.XMLForm.Grid":
                    {
                        AubitDesktop.Xml.XMLForm.Grid p;
                        int height;
                        int width;
                        p = (AubitDesktop.Xml.XMLForm.Grid)child;
                        Panel thisScreensPanel;
                        

                        thisScreensPanel = new Panel();
                        thisScreensPanel.Visible = true;
                        thisScreensPanel.Top = 0;
                        thisScreensPanel.Left = 0;

                        height = GuiLayout.get_gui_h(Convert.ToInt32(p.height));
                        width = GuiLayout.get_gui_w(Convert.ToInt32(p.width));

                        thisScreensPanel.AutoSize = false;
                        thisScreensPanel.Height = GuiLayout.get_gui_h(height+1);
                        thisScreensPanel.Width = GuiLayout.get_gui_w(width+1);

                 //       thisScreensPanel.BackColor = Color.Purple;
                        

                        foreach (object a in p.Items)
                        {
                            addLayoutToParentForXmlForm(thisScreensPanel, a);
                        }
                        parent.Controls.Add(thisScreensPanel);
                    }
                    break;
                #endregion
                #region Page
                case "AubitDesktop.Xml.XMLForm.Page":
                    {
                        AubitDesktop.Xml.XMLForm.Page p;
                        p = (AubitDesktop.Xml.XMLForm.Page)child;
                        foreach (object a in p.Items)
                        {
                            addLayoutToParentForXmlForm(parent, a);
                        }
                    }
                    break;
                #endregion            
                #region Folder
                case "AubitDesktop.Xml.XMLForm.Page[]":
                    {
                   //     int maxHeight = 0;
                   //     int maxWidth = 0;
                        AubitDesktop.Xml.XMLForm.Page[] p;
                        p = (AubitDesktop.Xml.XMLForm.Page[])child;



                        TabControl tb = new TabControl();
       
                        tb.Visible = true;
                        tb.Top = 0;
                        tb.Left = 0;

                        parent.Controls.Add(tb);
               
                        tb.Size = parent.Size;
                        tb.Dock = DockStyle.Fill;



                        




                        //tb.Dock = DockStyle.Fill;
                        for (int a = 0; a < p.Length; a++)
                        {
                            TabPage tp;
                            Panel tpp;
                            if (p[a].text != null) { tp = new TabPage(p[a].text); } else { tp = new TabPage("Page " + a); }

                            

                            // We're adding a panel into our tabpage with autosize on it
                            // we can then look up the size of that panel to 
                            // work out how large to make our tabcontrol...
                            tpp = new Panel();
                            tpp.SuspendLayout();
                            tpp.AutoSize = true;
                     
                  //          tpp.BorderStyle = BorderStyle.FixedSingle;
                             
                            
                            addLayoutToParentForXmlForm(tpp, p[a]);
                            
                            tpp.ResumeLayout(true);
                           
                            tpp.Show();
                            
                            //tpp.AutoScroll = true;
                        
                            tp.Controls.Add(tpp);
                            tb.TabPages.Add(tp);
                        }
                       
                   

                    }
                    break;
                                    #endregion          
                #region screen
                case "AubitDesktop.Xml.XMLForm.Screen":
                    {
                        // This is a 'converted' xml form still
                        // based on an old screen layout...
                        AubitDesktop.Xml.XMLForm.Screen p;
                        Panel thisScreensPanel;
                        p = (AubitDesktop.Xml.XMLForm.Screen)child;

                        thisScreensPanel = new Panel();
                        thisScreensPanel.Visible = true;
                        thisScreensPanel.Top = 0;
                        thisScreensPanel.Left = 0;
                        thisScreensPanel.AutoSize = true;
                        parent.Controls.Add(thisScreensPanel);

                        foreach (object a in p.Items)
                        {
                            addLayoutToParentForXmlForm(thisScreensPanel, a);
                        }
                    }
                    break;
                #endregion
                #region FormField
                case "AubitDesktop.Xml.XMLForm.FormField":
                    {
                        AubitDesktop.Xml.XMLForm.FormField ff;
                        ff = (AubitDesktop.Xml.XMLForm.FormField)child;
                        FGLWidget fld = makeXMLFieldWidget(ff, 0 /* not in a matrix - so subscript is 0 */);
                        if (fld != null)
                        {
                            parent.Controls.Add(fld.WindowsWidget);
                        }
                    }
                    break;
                #endregion
                #region HLine
                case "AubitDesktop.Xml.XMLForm.HLine":
                    {
                        AubitDesktop.Xml.XMLForm.HLine hl;
                        hl = (AubitDesktop.Xml.XMLForm.HLine)child;
                        // We'll fake a like by using a panel with a border...
                        Panel p_for_line;
                        p_for_line = new Panel();
                        p_for_line.Top = GuiLayout.get_gui_y(Convert.ToInt32(hl.posY));
                        p_for_line.Left = GuiLayout.get_gui_x(Convert.ToInt32(hl.posX));
                        p_for_line.Height = 4;
                        p_for_line.Width = GuiLayout.get_gui_w(Convert.ToInt32(hl.gridWidth) + 1) - 1;
                        p_for_line.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
                        parent.Controls.Add(p_for_line);
                    }
                    break;
                #endregion
                #region Label
                case "AubitDesktop.Xml.XMLForm.Label":
                    {
                        AubitDesktop.Xml.XMLForm.Label lb;
                        lb = (AubitDesktop.Xml.XMLForm.Label)child;
                        Label l;
                        l = new Label();
                        if (isJustLines(lb.text))
                        {
                            // We'll fake a line by using a panel with a border...
                            Panel p_for_line;
                            p_for_line = new Panel();
                            p_for_line.Top = GuiLayout.get_gui_y(Convert.ToInt32(lb.posY));
                            p_for_line.Left = GuiLayout.get_gui_x(Convert.ToInt32(lb.posX));
                            p_for_line.Height = 4;
                            p_for_line.Width = GuiLayout.get_gui_w(lb.text.Length + 1) - 1;
                            p_for_line.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
                            parent.Controls.Add(p_for_line);
                        }
                        else
                        {
                            l.Text = lb.text;
                            l.AutoSize = true;
                            l.Top = GuiLayout.get_gui_y(Convert.ToInt32(lb.posY));
                            l.Left = GuiLayout.get_gui_x(Convert.ToInt32(lb.posX));
                            l.Height = 1;
                            l.Width = 1;
                            //labels.Add(l);
                            parent.Controls.Add(l);
                        }
                    }
                    break;
                #endregion
                #region Matrix
                case "AubitDesktop.Xml.XMLForm.Matrix":
                    {
                        AubitDesktop.Xml.XMLForm.Matrix ma;
                        AubitDesktop.Xml.XMLForm.TextEdit te;
                        ma = (AubitDesktop.Xml.XMLForm.Matrix)child;
                        Type t;
                        t = ma.Items[0].GetType();
                        if (t.ToString() == "AubitDesktop.Xml.XMLForm.TextEdit")
                        {
                            FGLWidget fld;
                            te = (AubitDesktop.Xml.XMLForm.TextEdit)ma.Items[0];
                            te.height = ma.pageSize;
                            // This isn't really a Matrix, its a multiline
                            // text edit field...
                            AubitDesktop.Xml.XMLForm.FormField ff = createFormFieldFromMatrix(ma, 0);

                            fld = makeXMLFieldWidget(ff, 0);
                            if (fld != null)
                            {
                                parent.Controls.Add(fld.WindowsWidget);
                            }
                        }
                        else
                        {
                            for (int i = 0; i < Convert.ToInt32(ma.pageSize); i++)
                            {
                                for (int itm = 0; itm < ma.Items.Length; itm++)
                                {
                                    FGLWidget fld;
                                    // All our constructors use a FormField
                                    // but we've got a 'Matrix' - so lets create a new
                                    // FormField we can use for this....
                                    
                                    AubitDesktop.Xml.XMLForm.FormField ff=createFormFieldFromMatrix(ma, itm);

                                    fld = makeXMLFieldWidget(ff, i);
                                    if (fld != null)
                                    {
                                        parent.Controls.Add(fld.WindowsWidget);
                                    }

                                    //ma.Items[a];
                                }
                            }
                        }
                    }
                    break;
                #endregion
                default:
                    throw new ApplicationException("Invalid object to add to parent for xmlform");
            }
        }

        private static AubitDesktop.Xml.XMLForm.FormField createFormFieldFromMatrix(AubitDesktop.Xml.XMLForm.Matrix ma, int itm)
        {
            AubitDesktop.Xml.XMLForm.FormField ff = new AubitDesktop.Xml.XMLForm.FormField();
            ff.colName = ma.colName;
            ff.defaultValue = ma.defaultValue;
            ff.include = ma.include;
            ff.fieldId = ma.fieldId;
            ff.name = ma.name;
            ff.noEntry = ma.noEntry;
            ff.notNull = ma.notNull;
            ff.required = ma.required;
            ff.sqlTabName = ma.sqlTabName;
            ff.sqlType = ma.sqlType;
            ff.Items = new object[1];
            ff.Items[0] = ma.Items[itm];
            return ff;
        }





        
        /// <summary>
        /// create a 'widget' - this is used when its a 'widget' from an XML form - but not a specific widget
        /// This routine should work out and call the correct 'widget specific' widget constructor..
        /// </summary>
        /// <param name="ffx"></param>
        /// <param name="widget"></param>
        public FGLWidget makegenericFGLWidgetForXmlForm(AubitDesktop.Xml.XMLForm.FormField ffx, AubitDesktop.Xml.XMLForm.Widget widget,int index)
        {
 

            switch (widget.Type.ToUpper())
            {
                case "PIXMAP":

                    {
                        AubitDesktop.Xml.XMLForm.Image b = new AubitDesktop.Xml.XMLForm.Image();
                        b.action = widget.action;
                        //b.comments = widget.comments;
                        b.gridWidth = widget.gridWidth;
                        b.posX = widget.posX;
                        b.posY = widget.posY;
                        //b.text = "";
                        b.width = widget.width;
                        return new FGLPixmapFieldWidget(ffx, b, widget.config,index);
                    }
                    

                case "BUTTON":
                    {
                        AubitDesktop.Xml.XMLForm.ButtonEdit b = new AubitDesktop.Xml.XMLForm.ButtonEdit();
                        b.action = widget.action;
                        //b.comments = widget.comments;
                        b.gridWidth = widget.gridWidth;
                        b.posX = widget.posX;
                        b.posY = widget.posY;
                        //b.text = "";
                        b.width = widget.width;
                        return new FGLButtonFieldWidget(ffx, b,widget.config,index);
                    }


                case "LABEL":
                    {
                        AubitDesktop.Xml.XMLForm.Label b = new AubitDesktop.Xml.XMLForm.Label();
                        b.action = widget.action;
                        
                        b.gridWidth = widget.gridWidth;
                        b.posX = widget.posX;
                        b.posY = widget.posY;
                        //b.text = "";
                        b.width = widget.width;
                        return new FGLLabelFieldWidget(ffx, b, widget.config,index);
                    }

                case "BROWSER":
                    {
                        AubitDesktop.Xml.XMLForm.Browser b = new AubitDesktop.Xml.XMLForm.Browser();
                       
                        b.comments = widget.comments;
                        b.gridWidth = widget.gridWidth;
                        b.posX = widget.posX;
                        b.posY = widget.posY;
                        b.text = "";
                        b.width = widget.width;
                        return new FGLBrowserFieldWidget(ffx, b,widget.config,index);
                    }
                    

                default:
                    MessageBox.Show("Unhandled widget type");
                    break;
            }

            throw new NotImplementedException("UNhandled widget " + widget.Type.ToUpper());
            
        }


        /// <summary>
        /// Creates a widget based on the XML form definition for that widget/field.
        /// </summary>
        /// <param name="ff">the formfield to use as the template</param>
        /// <param name="index">subscript if called from a matrix (zero based)</param>
        /// <returns></returns>
        private FGLWidget makeXMLFieldWidget(AubitDesktop.Xml.XMLForm.FormField ff,int index)
        {

            FGLWidget fld;
            string widgetType;
            fld = null;
            widgetType = ff.Items[0].GetType().ToString();

            switch (widgetType)
            {



                
                case "AubitDesktop.Xml.XMLForm.Widget":
                    fld = makegenericFGLWidgetForXmlForm(ff, (AubitDesktop.Xml.XMLForm.Widget)ff.Items[0],index);
                    break;

                case "AubitDesktop.Xml.XMLForm.DateEdit":
                    fld = new FGLDateFieldWidget(ff, (AubitDesktop.Xml.XMLForm.DateEdit)ff.Items[0],"",index);
                    break;

                case "AubitDesktop.Xml.XMLForm.TextEdit":
                    {
                        fld = new FGLTextFieldWidget(ff, (AubitDesktop.Xml.XMLForm.TextEdit)ff.Items[0],"",index);
                    }

                    break;

                case "AubitDesktop.Xml.XMLForm.ButtonEdit":
                    {
                        fld = new FGLTextFieldWidget(ff, (AubitDesktop.Xml.XMLForm.ButtonEdit)ff.Items[0], "", index);
                    }

                    break;


                case "AubitDesktop.Xml.XMLForm.Edit":
                    if (ff.sqlType != null && ff.sqlType == "DATE")  //&& thisAttrib.ATTRIB_FORMAT == null)
                    {
                        // Its a date
                        fld = new FGLDateFieldWidget(ff, (AubitDesktop.Xml.XMLForm.Edit)ff.Items[0],"",index);
                    }
                    else
                    {
                        fld = new FGLTextFieldWidget(ff, (AubitDesktop.Xml.XMLForm.Edit)ff.Items[0],index);
                    }
                    break;

                case "AubitDesktop.Xml.XMLForm.Image":
                    fld = new FGLPixmapFieldWidget(ff, (AubitDesktop.Xml.XMLForm.Image)ff.Items[0],"",index);
                    break;

                case "AubitDesktop.Xml.XMLForm.Browser":
                    fld = new FGLBrowserFieldWidget(ff, (AubitDesktop.Xml.XMLForm.Browser)ff.Items[0],"",index);
                    break;

                case "AubitDesktop.Xml.XMLForm.Button":
                    fld = new FGLButtonFieldWidget(ff, (AubitDesktop.Xml.XMLForm.ButtonEdit)ff.Items[0],"",index);
                    break;


               
                case "AubitDesktop.Xml.XMLForm.Label":
                    fld = new FGLLabelFieldWidget(ff, (AubitDesktop.Xml.XMLForm.Label)ff.Items[0], "",index);
                    break;
                case "AubitDesktop.Xml.XMLForm.RipLABEL":
                    fld = new FGLLabelFieldWidget(ff, (AubitDesktop.Xml.XMLForm.RipLABEL)ff.Items[0], "",index);
                    break;

                case "AubitDesktop.Xml.XMLForm.ComboBox":
                case "AubitDesktop.Xml.XMLForm.ProgressBar":
                

                default:
                    MessageBox.Show("Unhandled widget type : " + widgetType);
                    break;
            }

            if (fld == null)
            {
                // Shit - we didn't manage to create one.
                // We'll assume we've already seen a message box telling us...

            }
            else
            {

                // Set the context type
                fld.ContextType = FGLContextType.ContextNone; // We're not using this field in any context...


                fields.Add(fld);
                fld.setToolTip(tooltips, fld.comment);
                
            }

            return fld;
            
        }

        public FGLForm(XMLFORM f)
        {

            fields = new List<FGLWidget>();

            

            AubitDesktop.Xml.XMLForm.Form theForm;
            System.Type t;
            string data;
            XmlSerializer ser;
            t = typeof(AubitDesktop.Xml.XMLForm.Form);
            if (f.Text == null)
            {
                MessageBox.Show("XML form was not passed to frontend");
                return;
            }
            if (f.Text.Length == 0)
            {
                MessageBox.Show("XML form was passed to frontend but was empty");
                return;
            }
            ser = new XmlSerializer(t);
            
            data = System.Text.ASCIIEncoding.ASCII.GetString(Convert.FromBase64String(f.Text));
            TextReader txtr = new StringReader(data);
            try
            {
                theForm = (AubitDesktop.Xml.XMLForm.Form)ser.Deserialize(txtr);
            }
            catch (Exception e)
            {
                MessageBox.Show("Unable to process XML file:" + e.ToString());
                return;
            }

            this.maxcol = Convert.ToInt32(theForm.width);
            this.maxline = Convert.ToInt32(theForm.height);
            tooltips = new ToolTip();
            tooltips.ShowAlways = true;

            fields = new List<FGLWidget>();
            thisFormsPanel = new Panel();
            thisFormsPanel.Visible = true;
            thisFormsPanel.AutoSize = true;
            thisFormsPanel.Dock = DockStyle.Fill;

            ScreenRecords = new List<FGLScreenRecord>();
            foreach (object o in theForm.XmlFormItems)
            {
                string type;

                type=o.GetType().ToString();
                switch (type) 
                {
                    case "AubitDesktop.Xml.XMLForm.RecordView":
                        {
                            FGLScreenRecord r;
                            AubitDesktop.Xml.XMLForm.RecordView sr;
                            sr = (AubitDesktop.Xml.XMLForm.RecordView)o;
                            if (sr.Link == null) continue;
                            r = new FGLScreenRecord(sr.tabName);
                            foreach (AubitDesktop.Xml.XMLForm.Link l in sr.Link)
                            {
                                r.AddAttribute(l);
                            }
                            ScreenRecords.Add(r);
                        }
                        break;

                    case "AubitDesktop.Xml.XMLForm.VBox":
                    case "AubitDesktop.Xml.XMLForm.HBox":
                    case "AubitDesktop.Xml.XMLForm.Table":
                    case "AubitDesktop.Xml.XMLForm.Grid":
                    case "AubitDesktop.Xml.XMLForm.Page[]": /* Really a Folder... */
                    case "AubitDesktop.Xml.XMLForm.Page":
                    case "AubitDesktop.Xml.XMLForm.Screen":
                        addLayoutToParentForXmlForm( thisFormsPanel, o);
                        break;

                    default:
                        throw new ApplicationException("Invalid object to add to parent for xmlform (top level)");
                }

                // MessageBox.Show(data, "Not implemented yet");
            }
        }
        #endregion



        #region standard form handling
        /// <summary>
        /// Create a form from a normal Aubit4GL form (not an XML form)
        /// </summary>
        /// <param name="f"></param>
        public FGLForm(FORM f)
        {
            //labels = new List<Label>();
            fields = new List<FGLWidget>();
            thisFormsPanel = new Panel();
            thisFormsPanel.Visible = true;
            this.thisFormsPanel.Top = 15;
            this.thisFormsPanel.Left = 5;
            tooltips = new ToolTip();
            tooltips.ShowAlways = true;
            

            this.maxcol = Convert.ToInt32(f.SCREENS.MAXCOL);
            this.maxline = Convert.ToInt32(f.SCREENS.MAXLINE);

            this.thisFormsPanel.Width = GuiLayout.get_gui_x(Convert.ToInt32(f.SCREENS.MAXCOL));
            this.thisFormsPanel.Height = GuiLayout.get_gui_y(Convert.ToInt32(f.SCREENS.MAXLINE));
            this.thisFormsPanel.AutoSize = true;
            // this.BorderStyle = BorderStyle.FixedSingle;

            ScreenRecords = new List<FGLScreenRecord>();
            foreach (SCREENRECORD sr in f.SCREENRECORDS)
            {
                FGLScreenRecord r;
                if (sr.ATTRIBUTE == null) continue;
                r = new FGLScreenRecord(sr.NAME, Convert.ToInt32(sr.SIZE));
                foreach (ATTRIBUTE a in sr.ATTRIBUTE)
                {
                    r.AddAttribute(a);
                }
                ScreenRecords.Add(r);
            }
            #region Process Screen Layout elements
            foreach (object o in f.SCREENS.SCREENLAYOUT)
            {
                ATTRIB thisAttrib;

                if (o is FORMLABEL)
                {
                    FORMLABEL flabel = (FORMLABEL)o;
                    Label l;
                    l = new Label();
                    if (isJustLines(flabel.Text))
                    {
                        Panel p;
                        p = new Panel();
                        p.Top = GuiLayout.get_gui_y(Convert.ToInt32(flabel.ROW));
                        p.Left = GuiLayout.get_gui_x(Convert.ToInt32(flabel.COLUMN));
                        p.Height = 4;
                        p.Width = GuiLayout.get_gui_w(flabel.Text.Length + 1)-1;
                        p.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
                        this.thisFormsPanel.Controls.Add(p);
                    }
                    else
                    {
                        l.Text = flabel.Text;
                        l.AutoSize = true;
                        l.Top = GuiLayout.get_gui_y(Convert.ToInt32(flabel.ROW));
                        l.Left = GuiLayout.get_gui_x(Convert.ToInt32(flabel.COLUMN));
                        l.Height = 1;
                        l.Width = 1;
                        //labels.Add(l);
                        this.thisFormsPanel.Controls.Add(l);
                    }
                    continue;
                }

                if (o is FORMFIELD)
                {
                    FGLWidget fld;

                    FORMFIELD formfld = (FORMFIELD)o;
                    thisAttrib = f.ATTRIBUTES[Convert.ToInt32(formfld.ATTRIBUTE_NO)];
                    fld = makeFieldWidget(thisAttrib, formfld);
                }

            }
            #endregion 
        }

        private FGLWidget makeFieldWidget(ATTRIB thisAttrib, FORMFIELD formfld)
        {
            FGLWidget fld;
            fld = null;
            switch (formfld.WIDGET.ToUpper())
            {
                case "": // Default widget is a text box field...
                case "TEXT":
                    if ((Convert.ToInt32(thisAttrib.DATATYPE) & 255) == 7 && thisAttrib.ATTRIB_FORMAT == null)
                    {
                        // Its a date
                        fld = new FGLDateFieldWidget(thisAttrib, Convert.ToInt32(formfld.ROW), Convert.ToInt32(formfld.COLUMN), Convert.ToInt32(formfld.ROWS), Convert.ToInt32(formfld.COLS), formfld.WIDGET, formfld.CONFIG, Convert.ToInt32(formfld.ID), formfld.TABCOL, formfld.ACTION, Convert.ToInt32(formfld.ATTRIBUTE_NO), formfld.INC);
                    }
                    else
                    {
                        fld = new FGLTextFieldWidget(thisAttrib, Convert.ToInt32(formfld.ROW), Convert.ToInt32(formfld.COLUMN), Convert.ToInt32(formfld.ROWS), Convert.ToInt32(formfld.COLS), formfld.WIDGET, formfld.CONFIG, Convert.ToInt32(formfld.ID), formfld.TABCOL, formfld.ACTION, Convert.ToInt32(formfld.ATTRIBUTE_NO), formfld.INC,false);
                    }
                    break;

                case "PIXMAP":
                    fld = new FGLPixmapFieldWidget(thisAttrib, Convert.ToInt32(formfld.ROW), Convert.ToInt32(formfld.COLUMN), Convert.ToInt32(formfld.ROWS), Convert.ToInt32(formfld.COLS), formfld.WIDGET, formfld.CONFIG, Convert.ToInt32(formfld.ID), formfld.TABCOL, formfld.ACTION, Convert.ToInt32(formfld.ATTRIBUTE_NO), formfld.INC);
                    break;
                case "BROWSER":
                    fld = new FGLBrowserFieldWidget(thisAttrib, Convert.ToInt32(formfld.ROW), Convert.ToInt32(formfld.COLUMN), Convert.ToInt32(formfld.ROWS), Convert.ToInt32(formfld.COLS), formfld.WIDGET, formfld.CONFIG, Convert.ToInt32(formfld.ID), formfld.TABCOL, formfld.ACTION, Convert.ToInt32(formfld.ATTRIBUTE_NO), formfld.INC);
                    break;
                case "BUTTON":
                    fld = new FGLButtonFieldWidget(thisAttrib, Convert.ToInt32(formfld.ROW), Convert.ToInt32(formfld.COLUMN), Convert.ToInt32(formfld.ROWS), Convert.ToInt32(formfld.COLS), formfld.WIDGET, formfld.CONFIG, Convert.ToInt32(formfld.ID), formfld.TABCOL, formfld.ACTION, Convert.ToInt32(formfld.ATTRIBUTE_NO), formfld.INC);
                    break;
                case "LABEL":
                    fld = new FGLLabelFieldWidget(thisAttrib, Convert.ToInt32(formfld.ROW), Convert.ToInt32(formfld.COLUMN), Convert.ToInt32(formfld.ROWS), Convert.ToInt32(formfld.COLS), formfld.WIDGET, formfld.CONFIG, Convert.ToInt32(formfld.ID), formfld.TABCOL, formfld.ACTION, Convert.ToInt32(formfld.ATTRIBUTE_NO), formfld.INC);
                    break;

                default:
                    MessageBox.Show("Unhandled widget type : " + formfld.WIDGET);
                    break;
            }

            if (fld == null)
            {
                // Shit - we didn't manage to create one.
                // We'll assume we've already seen a message box telling us...

            }
            else
            {

                // Set the context type
                fld.ContextType = FGLContextType.ContextNone; // We're not using this field in any context...


                fields.Add(fld);
                fld.setToolTip(tooltips, fld.comment);
                this.thisFormsPanel.Controls.Add(fld.WindowsWidget);
            }

            return fld;
        }
#endregion

        /// <summary>
        /// Returns true/false if the string is just a 'line' (ie - made up of a series of '_' or '-' characters)
        /// normally used for underlining fields on 4gl forms...
        /// </summary>
        /// <param name="p"></param>
        /// <returns></returns>
        private bool isJustLines(string p)
        {
            string underlines;
            string minuses;
            
            underlines = new string('_', p.Length);
            minuses = new string('-', p.Length);
            if (p == underlines || p == minuses) return true;
            return false;
        }


        /*
        void fld_onAction(object source, string ID, string TriggeredText)
        {
            throw new NotImplementedException();
        }

        void fld_fieldValidationFailed(object source, string failedText, out bool ignore)
        {
            throw new NotImplementedException();
        }

        void fld_focusChanged(object source, bool gainedFocus)
        {
            throw new NotImplementedException();
        }
        */

        internal void setNextField(string NextField)
        {
            throw new NotImplementedException();
        }
         






        #region FindField routines
        private List<FGLFoundField> FindField(string name, bool always_dim_match)
        {
            //IFGLField f;
            int attributeNo = -1;
            string tabName = "";
            string colName = "";
            List<FGLFoundField> foundFields;
            int dim = 1;
            int cnt = 0;
            List<int> Attributes;
            foundFields=new List<FGLFoundField>();
            Attributes = new List<int>();

            if (name.Contains("."))
            {
                string[] names;
                names = name.Split('.');

                tabName = names[0];
                colName = names[1];
            }
            else
            {
                tabName = "";
                colName = name;
            }

            if (colName.Contains("["))
            {
                //string tokens;
                dim = Convert.ToInt32(colName.Substring(colName.IndexOf("[") + 1, colName.Length - 2));
                colName = colName.Substring(0, colName.IndexOf("[") - 1);
            }

            if (tabName != "")
            {
                foreach (FGLScreenRecord sr in ScreenRecords)
                {
                    if (sr.name == tabName)
                    {
                        // We've found our record - now find our attribute..
                        if (colName != "*") { 
                                attributeNo = sr.FindAttributeNo(colName);
                                Attributes.Add(attributeNo);
                        } else {
                            Attributes.AddRange(sr.AttributeNoList());
                        }
                        break;
                    }
                }
            }


            Hashtable fieldCounts;
            fieldCounts = new Hashtable();


            foreach (FGLWidget fld in fields)
            {
                bool found = false;
                string foundNameShort="<notSet>";
                string foundNameLong = "<notSet>";
                string foundNameUse = "<notSet>";
                

                if (tabName=="") // We're not using table names
                {
                    if (fld.ColumnName == colName)
                    {
                        foundNameUse = colName;
                        foundNameShort = colName;
                        foundNameLong = fld.TableName + "." + fld.ColumnName;
                        found=true;
                    }
                }
                else
                { // We are using table names - so our attribute number has already been found...
                    if (Attributes.Contains(fld.attributeNo )) 
                    {
                        foundNameLong = tabName+"."+fld.ColumnName;
                        foundNameUse = tabName + "." + fld.ColumnName;
                        foundNameShort =  fld.ColumnName;
                        found=true;
                    }
                }

                if (found)
                {
                    if (fieldCounts.ContainsKey(foundNameUse))
                    {
                        cnt =(int) fieldCounts[foundNameUse];
                    }
                    else
                    {
                        cnt = 0;
                    }
                    cnt++;
                    if (cnt == dim || always_dim_match==true)
                    {
                        foundFields.Add(new FGLFoundField(foundNameUse, foundNameShort, foundNameLong, fld,cnt));
                    }
                    fieldCounts[foundNameUse] = cnt;
                }
            }


            if (foundFields.Count == 0)
            {
                MessageBox.Show("FindField failed");
            }

            return foundFields;
        }


        public List<FGLFoundField> FindFields(FIELD[] FIELDLIST)
        {
            List<FGLFoundField> fldlist;
            fldlist = new List<FGLFoundField>();

            foreach (FIELD f in FIELDLIST)
            {
                List<FGLFoundField> flds;
                flds = FindField(f.NAME, false);
                if (flds != null)
                {
                    foreach (FGLFoundField fld in flds)
                    {
                        fldlist.Add(fld);
                    }
                }
            }
            return fldlist;
        }


        public List<FGLFoundField> FindFields(string[] FIELDLIST)
        {
            List<FGLFoundField> fldlist;
            fldlist = new List<FGLFoundField>();

            foreach (string f in FIELDLIST)
            {
                List<FGLFoundField> flds;
                flds = FindField(f, false);
                if (flds != null)
                {
                    foreach (FGLFoundField fld in flds)
                    {
                        fldlist.Add(fld);
                    }
                }
            }
            return fldlist;
        }
#endregion


        public void DisplayTo(DISPLAYTO d)
        {
            List<FGLFoundField> fldlist;
                
            fldlist = FindFields(d.FIELDLIST);
            
            if (d.VALUES.Length!=fldlist.Count) {
                MessageBox.Show("Wrong number of fields");
            } else {
                for (int a=0;a<d.VALUES.Length;a++) {
                    if (fldlist[a].fglField.format != null)
                    {
                        string s="";
                        try
                        {
                            s = FGLUsing.A4GL_func_using(fldlist[a].fglField.format, d.VALUES[a].Text, fldlist[a].fglField.datatype);
                        }
                        catch (Exception )
                        {
                            // Does nothing..
                        }
                        fldlist[a].fglField.Text = s;
                    }
                    else
                    {
                        fldlist[a].fglField.Text = d.VALUES[a].Text;
                    }
                }
            }
        }

        // Enable all widgets with associated 'ACTIONS'..
        public void EnableActionWidgets()
        {
            MessageBox.Show("Enable Action widgets");
        }

        public void SetContext(FGLContextType contextType)
        {
            this.thisFormsPanel.SuspendLayout();
            // Set *all* fields...
            foreach (FGLWidget i in fields)
            {
                i.ContextType = contextType;
            }
            this.thisFormsPanel.ResumeLayout();
            
        }


        public void SetContext(FGLContextType contextType, List<FGLWidget> pfields)
        {
            
            this.thisFormsPanel.SuspendLayout();
            // We'll only set the active fields...
            foreach (FGLWidget i in this.fields)
            {
                if (pfields.Contains(i))
                {
                    
                    i.ContextType = contextType;
                    
                }
                else
                {
                    i.ContextType = FGLContextType.ContextNone;
                }
            }
            this.thisFormsPanel.ResumeLayout();
        }

        public void Dispose()
        {
            this.thisFormsPanel.Dispose();
        }


        

        internal List<FGLFoundField> FindAction(string actionName)
        {
            List<FGLFoundField> l;
            l = new List<FGLFoundField>();
            foreach (FGLWidget fld in fields)
            {
                if (fld.Action == actionName)
                {
                    FGLFoundField f = new FGLFoundField(fld.ColumnName, fld.ColumnName, fld.ColumnName, fld,1);
                    l.Add(f);
                }
            }
            return l;
        }

        internal List<FGLFoundField> FindFieldArray(FIELD[] fieldlist)
        {
            
            List<FGLFoundField> fldlist;
            fldlist = new List<FGLFoundField>();

            foreach (FIELD ff in fieldlist)
            {
                string f;
                f = ff.NAME;
                List<FGLFoundField> flds;
                flds = FindField(f, true);
                if (flds != null)
                {
                    // fldlist could be unsorted - we need to get subscripts 1 followed by subscripts 2 etc etc...

                    // Firstly then - work out how high we need to go...
                    int maxdim=-1;
                    foreach (FGLFoundField fld in flds)
                    {
                        if (fld.subscript > maxdim) maxdim = fld.subscript;
                    }

                    // Now - interate over that and add all fields at that level...
                    for (int dim=1;dim<=maxdim;dim++) {
                        foreach (FGLFoundField fld in flds)
                        {
                            if (fld.subscript == dim)
                            {
                                fldlist.Add(fld);
                            }
                        }
                    }

                }
            }
            


            return fldlist;
            
        }
    }
}
