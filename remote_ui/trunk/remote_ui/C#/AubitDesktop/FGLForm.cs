﻿/*
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




        void addLayoutToParent(string type , Control parent, object child)
        {
            

            //this.thisFormsPanel.Controls.Add(fld.WindowsWidget);

                switch (type)
                {
                    case "AubitDesktop.Xml.XMLForm.VBox":
                        {
                            AubitDesktop.Xml.XMLForm.VBox p;
                            p = (AubitDesktop.Xml.XMLForm.VBox)child;
                            
                        }
                        break;
                    case "AubitDesktop.Xml.XMLForm.HBox":
                        {
                            AubitDesktop.Xml.XMLForm.HBox p;
                            p = (AubitDesktop.Xml.XMLForm.HBox)child;
                        }
                        break;
                    case "AubitDesktop.Xml.XMLForm.Table":
                        {
                            AubitDesktop.Xml.XMLForm.Table p;
                            p = (AubitDesktop.Xml.XMLForm.Table)child;
                        }
                        break;
                    case "AubitDesktop.Xml.XMLForm.Grid":
                        {
                            AubitDesktop.Xml.XMLForm.Grid p;
                            p = (AubitDesktop.Xml.XMLForm.Grid)child;
                        }
                        break;
                    
                    case "AubitDesktop.Xml.XMLForm.Page":
                        {
                            AubitDesktop.Xml.XMLForm.Page p;
                            p = (AubitDesktop.Xml.XMLForm.Page)child;
                        }
                        break;

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
                                switch (a.GetType().ToString()) {
                                    case "AubitDesktop.Xml.XMLForm.FormField":
                                        {
                                            AubitDesktop.Xml.XMLForm.FormField ff;
                                            ff = (AubitDesktop.Xml.XMLForm.FormField)a;
                                            FGLWidget fld = makeXMLFieldWidget(ff);
                                            if (fld!=null)
                                            {
                                                thisScreensPanel.Controls.Add(fld.WindowsWidget);
                                            }
                                        }
                                        break;


                                    case "AubitDesktop.Xml.XMLForm.HLine":
                                        {
                                            AubitDesktop.Xml.XMLForm.HLine hl;
                                            hl = (AubitDesktop.Xml.XMLForm.HLine)a;
                                            // We'll fake a like by using a panel with a border...
                                            Panel p_for_line;
                                            p_for_line = new Panel();
                                            p_for_line.Top = GuiLayout.get_gui_y(Convert.ToInt32(hl.posY));
                                            p_for_line.Left = GuiLayout.get_gui_x(Convert.ToInt32(hl.posX));
                                            p_for_line.Height = 4;
                                            p_for_line.Width = GuiLayout.get_gui_w(Convert.ToInt32(hl.gridWidth) + 1) - 1;
                                            p_for_line.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
                                            thisScreensPanel.Controls.Add(p_for_line);
                                        }
                                        break;

                                    case "AubitDesktop.Xml.XMLForm.Label":
                                        {
                                            AubitDesktop.Xml.XMLForm.Label lb;
                                            lb = (AubitDesktop.Xml.XMLForm.Label)a;
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
                                                thisScreensPanel.Controls.Add(p_for_line);
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
                                                thisScreensPanel.Controls.Add(l);
                                            }
                                        }
                                        break;


                                    case "AubitDesktop.Xml.XMLForm.Matrix":
                                        {
                                            AubitDesktop.Xml.XMLForm.Matrix ma;
                                            ma = (AubitDesktop.Xml.XMLForm.Matrix)a;
                                            throw new NotImplementedException("Matrix not implemented");
                                        }
                                        break;
                                }
                            }
                        }
                        break;

                    default:
                        throw new ApplicationException("Invalid object to add to parent for xmlform");
                }
        }



        
        /// <summary>
        /// create a 'widget' - this is used when its a 'widget' from an XML form - but not a specific widget
        /// This routine should work out and call the correct 'widget specific' widget constructor..
        /// </summary>
        /// <param name="ffx"></param>
        /// <param name="widget"></param>
        public FGLWidget makegenericFGLWidget(AubitDesktop.Xml.XMLForm.FormField ffx, AubitDesktop.Xml.XMLForm.Widget widget)
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
                        return new FGLPixmapFieldWidget(ffx, b, widget.config);
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
                        return new FGLButtonFieldWidget(ffx, b,widget.config);
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
                        return new FGLBrowserFieldWidget(ffx, b,widget.config);
                    }
                    

                default:
                    MessageBox.Show("Unhandled widget type");
                    break;
            }

            throw new NotImplementedException("UNhandled widget " + widget.Type.ToUpper());
            
        }


        private FGLWidget makeXMLFieldWidget(AubitDesktop.Xml.XMLForm.FormField ff)
        {

            FGLWidget fld;
            string widgetType;
            fld = null;
            widgetType = ff.Items[0].GetType().ToString();

            switch (widgetType)
            {



                
                case "AubitDesktop.Xml.XMLForm.Widget":
                    fld = makegenericFGLWidget(ff, (AubitDesktop.Xml.XMLForm.Widget)ff.Items[0]);
                    break;

                case "AubitDesktop.Xml.XMLForm.DateEdit":
                    fld = new FGLDateFieldWidget(ff, (AubitDesktop.Xml.XMLForm.DateEdit)ff.Items[0],"");
                    break;

                case "AubitDesktop.Xml.XMLForm.TextEdit":
                    {
                        
                        fld = new FGLTextFieldWidget(ff, (AubitDesktop.Xml.XMLForm.TextEdit)ff.Items[0],"");
                    }

                    break;


                case "AubitDesktop.Xml.XMLForm.Edit":
                    if (ff.sqlType != null && ff.sqlType == "DATE")  //&& thisAttrib.ATTRIB_FORMAT == null)
                    {
                        // Its a date
                        fld = new FGLDateFieldWidget(ff, (AubitDesktop.Xml.XMLForm.Edit)ff.Items[0],"");
                    }
                    else
                    {
                        fld = new FGLTextFieldWidget(ff, (AubitDesktop.Xml.XMLForm.Edit)ff.Items[0]);
                    }
                    break;

                case "AubitDesktop.Xml.XMLForm.Image":
                    fld = new FGLPixmapFieldWidget(ff, (AubitDesktop.Xml.XMLForm.Image)ff.Items[0],"");
                    break;

                case "AubitDesktop.Xml.XMLForm.Browser":
                    fld = new FGLBrowserFieldWidget(ff, (AubitDesktop.Xml.XMLForm.Browser)ff.Items[0],"");
                    break;

                case "AubitDesktop.Xml.XMLForm.ButtonEdit":
                    fld = new FGLButtonFieldWidget(ff, (AubitDesktop.Xml.XMLForm.ButtonEdit)ff.Items[0],"");
                    break;


                case "AubitDesktop.Xml.XMLForm.ComboBox":
                case "AubitDesktop.Xml.XMLForm.Label":
                case "AubitDesktop.Xml.XMLForm.RipLABEL":
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
                    case "AubitDesktop.Xml.XMLForm.Folder":
                    case "AubitDesktop.Xml.XMLForm.Page":
                    case "AubitDesktop.Xml.XMLForm.Screen":
                        addLayoutToParent(type, (Control)thisFormsPanel, o);
                        break;

                    default:
                        throw new ApplicationException("Invalid object to add to parent for xmlform (top level)");
                }

                // MessageBox.Show(data, "Not implemented yet");
            }
        }


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

        private bool isJustLines(string p)
        {
            string underlines;
            string minuses;
            
            underlines = new string('_', p.Length);
            minuses = new string('-', p.Length);
            if (p == underlines || p == minuses) return true;
            return false;
        }

        private FGLWidget makeFieldWidget(ATTRIB thisAttrib,  FORMFIELD formfld)
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
                        fld = new FGLTextFieldWidget(thisAttrib, Convert.ToInt32(formfld.ROW), Convert.ToInt32(formfld.COLUMN), Convert.ToInt32(formfld.ROWS), Convert.ToInt32(formfld.COLS), formfld.WIDGET, formfld.CONFIG, Convert.ToInt32(formfld.ID), formfld.TABCOL, formfld.ACTION, Convert.ToInt32(formfld.ATTRIBUTE_NO), formfld.INC);
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

            foreach (FGLWidget fld in fields)
            {
                bool found = false;
                string foundNameShort="<notSet>";
                string foundNameLong = "<notSet>";
                string foundNameUse = "<notSet>";
                Hashtable fieldCounts;
                fieldCounts = new Hashtable();

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
                    if (cnt == dim || always_dim_match==false)
                    {
                        foundFields.Add(new FGLFoundField(foundNameUse, foundNameShort, foundNameLong, fld));
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


        internal void setNextField(string NextField)
        {
            throw new NotImplementedException();
        }
        

        internal List<FGLFoundField> FindAction(string actionName)
        {
            List<FGLFoundField> l;
            l = new List<FGLFoundField>();
            foreach (FGLWidget fld in fields)
            {
                if (fld.Action == actionName)
                {
                    FGLFoundField f = new FGLFoundField(fld.ColumnName, fld.ColumnName, fld.ColumnName, fld);
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
                    foreach (FGLFoundField fld in flds)
                    {
                        fldlist.Add(fld);
                    }
                }
            }
            return fldlist;
            
        }
    }
}
