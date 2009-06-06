using System;
using System.Collections.Generic;
using System.Text;

namespace AubitDesktop.Xml.XMLForm
{

        /// <remarks/>
        public class Widget
        {

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string Type;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string action;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string autoNext;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string comments;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string config;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string gridWidth;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string posX;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string posY;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string shift;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string width;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string format;

            

        }

        /// <remarks/>
        public class DateEdit
        {

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string comments;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string config;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string gridWidth;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string posX;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string posY;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string width;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string format;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string action;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string autoNext;

        }

        /// <remarks/>
        [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
        public class Form
        {

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string delimiters;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string height;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string name;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string sqlDbName;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string width;

            /// <remarks/>
            [System.Xml.Serialization.XmlElementAttribute("Folder", Type = typeof(Page[]))]
            [System.Xml.Serialization.XmlElementAttribute("Grid", Type = typeof(Grid))]
            [System.Xml.Serialization.XmlElementAttribute("RecordView", Type = typeof(RecordView))]
            [System.Xml.Serialization.XmlElementAttribute("Screen", Type = typeof(Screen))]
            [System.Xml.Serialization.XmlElementAttribute("Table", Type = typeof(Table))]
            [System.Xml.Serialization.XmlElementAttribute("VBox", Type = typeof(VBox))]
            [System.Xml.Serialization.XmlElementAttribute("HBox", Type = typeof(HBox))]
            public object[] XmlFormItems;
        }

        /// <remarks/>
        public class Page
        {

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string text;

            /// <remarks/>
            [System.Xml.Serialization.XmlElementAttribute("Folder", Type = typeof(Page[]))]
            [System.Xml.Serialization.XmlElementAttribute("Grid", Type = typeof(Grid))]
            [System.Xml.Serialization.XmlElementAttribute("Table", Type = typeof(Table))]
            [System.Xml.Serialization.XmlElementAttribute("Screen", Type = typeof(Screen))]
            [System.Xml.Serialization.XmlElementAttribute("VBox", Type = typeof(VBox))]
            [System.Xml.Serialization.XmlElementAttribute("HBox", Type = typeof(HBox))]
            public object[] Items;
        }

        /// <remarks/>
        public class VBox
        {
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public bool border;
            [System.Xml.Serialization.XmlElementAttribute("Folder", Type = typeof(Page[]))]
            [System.Xml.Serialization.XmlElementAttribute("Grid", Type = typeof(Grid))]
            [System.Xml.Serialization.XmlElementAttribute("Table", Type = typeof(Table))]
            [System.Xml.Serialization.XmlElementAttribute("Screen", Type = typeof(Screen))]
            [System.Xml.Serialization.XmlElementAttribute("VBox", Type = typeof(VBox))]
            [System.Xml.Serialization.XmlElementAttribute("HBox", Type = typeof(HBox))]
            public object[] Items;
        }

        /// <remarks/>
        public class HBox
        {
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public bool border;

            [System.Xml.Serialization.XmlElementAttribute("Folder", Type = typeof(Page[]))]
            [System.Xml.Serialization.XmlElementAttribute("Grid", Type = typeof(Grid))]
            [System.Xml.Serialization.XmlElementAttribute("Table", Type = typeof(Table))]
            [System.Xml.Serialization.XmlElementAttribute("Screen", Type = typeof(Screen))]
            [System.Xml.Serialization.XmlElementAttribute("VBox", Type = typeof(VBox))]
            [System.Xml.Serialization.XmlElementAttribute("HBox", Type = typeof(HBox))]
            public object[] Items;
        }

        /// <remarks/>
        public class Grid
        {

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string height;

            [System.Xml.Serialization.XmlAttributeAttribute()]
            public bool border;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string width;
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public int autoSize;

            /// <remarks/>
            [System.Xml.Serialization.XmlElementAttribute("FormField", Type = typeof(FormField))]
            [System.Xml.Serialization.XmlElementAttribute("HLine", Type = typeof(HLine))]
            [System.Xml.Serialization.XmlElementAttribute("Label", Type = typeof(Label))]
            [System.Xml.Serialization.XmlElementAttribute("Matrix", Type = typeof(Matrix))]
            public object[] Items;
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
        public class FormField
        {

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string colName;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string fieldId;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string hidden;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string defaultValue;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string include;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string name;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string noEntry;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string notNull;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string required;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string sqlTabName;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string sqlType;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string tabIndex;

            /// <remarks/>
            [System.Xml.Serialization.XmlElementAttribute("ButtonEdit", Type = typeof(ButtonEdit))]
            [System.Xml.Serialization.XmlElementAttribute("Button", Type = typeof(Button))]
            [System.Xml.Serialization.XmlElementAttribute("ComboBox", Type = typeof(ComboBox))]
            [System.Xml.Serialization.XmlElementAttribute("CheckBox", Type = typeof(CheckBox))]
            [System.Xml.Serialization.XmlElementAttribute("DateEdit", Type = typeof(DateEdit))]
            [System.Xml.Serialization.XmlElementAttribute("Edit", Type = typeof(Edit))]
            [System.Xml.Serialization.XmlElementAttribute("Image", Type = typeof(Image))]
            [System.Xml.Serialization.XmlElementAttribute("Label", Type = typeof(Label))]
            [System.Xml.Serialization.XmlElementAttribute("ProgressBar", Type = typeof(ProgressBar))]
            [System.Xml.Serialization.XmlElementAttribute("RipLABEL", Type = typeof(RipLABEL))]
            [System.Xml.Serialization.XmlElementAttribute("TextEdit", Type = typeof(TextEdit))]
            [System.Xml.Serialization.XmlElementAttribute("Widget", Type = typeof(Widget))]
            [System.Xml.Serialization.XmlElementAttribute("Browser", Type = typeof(Browser))]
            public object[] Items;
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
        public class ButtonEdit
        {
            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string config;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string comments;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string action;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string autoNext;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string gridWidth;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string image;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string posX;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string posY;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string scroll;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string shift;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string width;


            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string format;


            
        }


        /// <remarks/>
        [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
        public class Button
        {
            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string config;
            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string comments;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string action;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string autoNext;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string gridWidth;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string image;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string posX;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string posY;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string scroll;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string shift;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string width;


            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string format;
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
        public class CheckBox
        {
            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string config;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string gridWidth;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string posX;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string posY;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string width;

            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string comments;


            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string action;
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string valueChecked;
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string valueUnchecked;
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string text;
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
        public class ComboBox
        {
            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string config;

            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string comments;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string gridWidth;


            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string shift;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string posX;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string posY;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string width;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string format;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string autoNext;
            
                        /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string action;
            /// <remarks/>
            [System.Xml.Serialization.XmlElementAttribute()]
            public Item[] Item;
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
        public class Item
        {

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string name;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string text;
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
        public class Edit
        {

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string autoNext;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string comments;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string config;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string fontPitch;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string gridWidth;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string picture;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string posX;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string posY;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string scroll;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string shift;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string width;


            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string format;

                        /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string action;
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
        public class Image
        {

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string config;
            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string autoScale;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string gridWidth;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string pixelHeight;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string pixelWidth;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string posX;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string posY;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string width;
            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string format;

                        /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string action;
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
        public class Label
        {
            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string config;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string gridWidth;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string posX;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string posY;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string text;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string width;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string format;

                        /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string action;
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
        public class Browser
        {

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string comments;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string gridWidth;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string posX;

                        /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string posY;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string pixelHeight;

                        /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string pixelWidth;

            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string config;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string text;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string width;
            
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
        public class ProgressBar
        {
            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string config;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string gridWidth;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string posX;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string posY;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string valueMax;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string valueMin;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string width;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string format;

                        /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string action;
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
        public class RipLABEL
        {
            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string config;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string gridWidth;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string posX;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string posY;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string width;
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
        public class TextEdit
        {

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string autoNext;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string comments;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string fontPitch;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string gridWidth;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string height;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string posX;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string posY;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string scroll;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string scrollBars;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string shift;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string stretch;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string style;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string wantReturns;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string wantTabs;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string width;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string format;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string action;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string config;
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
        public class HLine
        {

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string gridWidth;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string posX;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string posY;
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
        public class Matrix
        {

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string colName;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string fieldId;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string name;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string noEntry;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string notNull;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string pageSize;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string required;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string sqlTabName;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string sqlType;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string tabIndex;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string defaultValue;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string include;

            [System.Xml.Serialization.XmlAttributeAttribute()]
            public int stepX;

            [System.Xml.Serialization.XmlAttributeAttribute()]
            public int columnCount;

            /// <remarks/>
            [System.Xml.Serialization.XmlElementAttribute("ButtonEdit", Type = typeof(ButtonEdit))]
            [System.Xml.Serialization.XmlElementAttribute("Button", Type = typeof(Button))]
            [System.Xml.Serialization.XmlElementAttribute("ComboBox", Type = typeof(ComboBox))]
            [System.Xml.Serialization.XmlElementAttribute("CheckBox", Type = typeof(CheckBox))]
            [System.Xml.Serialization.XmlElementAttribute("DateEdit", Type = typeof(DateEdit))]
            [System.Xml.Serialization.XmlElementAttribute("Edit", Type = typeof(Edit))]
            [System.Xml.Serialization.XmlElementAttribute("Image", Type = typeof(Image))]
            [System.Xml.Serialization.XmlElementAttribute("Label", Type = typeof(Label))]
            [System.Xml.Serialization.XmlElementAttribute("ProgressBar", Type = typeof(ProgressBar))]
            [System.Xml.Serialization.XmlElementAttribute("RipLABEL", Type = typeof(RipLABEL))]
            [System.Xml.Serialization.XmlElementAttribute("TextEdit", Type = typeof(TextEdit))]
            [System.Xml.Serialization.XmlElementAttribute("Browser", Type = typeof(Browser))]
            [System.Xml.Serialization.XmlElementAttribute("Widget", Type = typeof(Widget))]





            public object[] Items;
        }

        /// <remarks/>
        public class Table
        {

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string pageSize;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string tabName;

            /// <remarks/>
            [System.Xml.Serialization.XmlElementAttribute()]
            public TableColumn[] TableColumn;
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
        public class TableColumn
        {

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string colName;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string fieldId;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string hidden;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string include;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string name;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string noEntry;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string required;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string sqlTabName;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string sqlType;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string tabIndex;

            /// <remarks/>
            [System.Xml.Serialization.XmlElementAttribute("ButtonEdit", Type = typeof(ButtonEdit))]
            [System.Xml.Serialization.XmlElementAttribute("Button", Type = typeof(Button))]
            [System.Xml.Serialization.XmlElementAttribute("ComboBox", Type = typeof(ComboBox))]
            [System.Xml.Serialization.XmlElementAttribute("CheckBox", Type = typeof(CheckBox))]
            [System.Xml.Serialization.XmlElementAttribute("DateEdit", Type = typeof(DateEdit))]
            [System.Xml.Serialization.XmlElementAttribute("Edit", Type = typeof(Edit))]
            [System.Xml.Serialization.XmlElementAttribute("Image", Type = typeof(Image))]
            [System.Xml.Serialization.XmlElementAttribute("Label", Type = typeof(Label))]
            [System.Xml.Serialization.XmlElementAttribute("ProgressBar", Type = typeof(ProgressBar))]
            [System.Xml.Serialization.XmlElementAttribute("RipLABEL", Type = typeof(RipLABEL))]
            [System.Xml.Serialization.XmlElementAttribute("TextEdit", Type = typeof(TextEdit))]
            [System.Xml.Serialization.XmlElementAttribute("Browser", Type = typeof(Browser))]
            [System.Xml.Serialization.XmlElementAttribute("Widget", Type = typeof(Widget))]
            public object[] Items;
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
        public class RecordView
        {

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string tabName;

            /// <remarks/>
            [System.Xml.Serialization.XmlElementAttribute()]
            public Link[] Link;
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
        public class Link
        {

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string colName;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string fieldIdRef;
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = true)]
        public class Screen
        {

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string height;

            /// <remarks/>
            [System.Xml.Serialization.XmlAttributeAttribute()]
            public string width;

            /// <remarks/>
            [System.Xml.Serialization.XmlElementAttribute("FormField", Type = typeof(FormField))]
            [System.Xml.Serialization.XmlElementAttribute("HLine", Type = typeof(HLine))]
            [System.Xml.Serialization.XmlElementAttribute("Label", Type = typeof(Label))]
            [System.Xml.Serialization.XmlElementAttribute("Matrix", Type = typeof(Matrix))]
            public object[] Items;
        }




}
