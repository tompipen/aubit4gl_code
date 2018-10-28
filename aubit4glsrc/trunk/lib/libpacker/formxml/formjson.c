

#include "a4gl_libaubit4gl.h"
#include "a4gl_API_packer_lib.h"
#include "formjson.h"
#include "../../libui/ui_json/libjson.h"


static char *get_sql_dtype ( int dtype);
static char * xml_escape (char *s);
static char * find_label (int x, int y);
static int isCharType(int n) ;
FILE *ofile;
/*
void write_xml_form(FILE *ofile, char *fname, struct_form *f) ;
void print_label_attr(struct_form *f, int metric_no, int attr_no,int oldstyle,char*why) ;
void print_buttonedit_attr(struct_form *f, int metric_no, int attr_no,int oldstyle,char*why) ;
void print_dateedit_attr(struct_form *f, int metric_no, int attr_no,int oldstyle,char*why) ;
void print_textedit_attr(struct_form *f, int metric_no, int attr_no,int oldstyle,char*why) ;
void print_entry (struct_form *f, int metric_no, int attr_no,char *why) ;
void print_unknown_widget_attr(struct_form *f, char *widget, int metric_no, int attr_no,int oldstyle,char *why) ;
void dump_layout(struct_form *f, struct s_layout *layout) ;
void print_image_attr(struct_form *f, int metric_no, int attr_no,int oldstyle,char *why) ;
void print_combobox_attr(struct_form *f, int metric_no, int attr_no,int oldstyle,char *why) ;
void print_progressbar_attr(struct_form *f, int metric_no, int attr_no,int oldstyle,char *why) ;
void dump_screen (struct_form * f, int scr, enum e_scrmodes scrmode,char *extra);
*/

/*
enum e_scrmodes {
	SCRMODE_GRID,
	SCRMODE_SCREEN
};
*/
//#include "formxml.h"



char screen[400][400];

struct s_field
{
  int y;
  int x;
  int w;
  char *label;
  int field_start;

};

struct s_field *screen_convert_fields = 0;
int nfields = 0;



void print_checkbox_attr(struct_form *f, int metric_no, int attr_no,int oldstyle,char *why) ;
void print_radio_attr(struct_form *f, int metric_no, int attr_no,int oldstyle,char *why) ;

int printed_attributes[1000];
static int tabIndex;
static int fieldNo ;
//int attributeFieldIDRef[1000];

int nprintedattributes;


int initialize_xmlpacker() {
	tabIndex=0;
	fieldNo=0;
	nprintedattributes=0;
	return 1;
}



int hasPrintedAttribute(int n) {
int a;
	for (a=0;a<nprintedattributes;a++) {
		if (printed_attributes[a]==n) return 1;
	}
	return 0;
}

void addPrintedAttribute(int n) {
	if (hasPrintedAttribute(n)) return;

	nprintedattributes++;
	printed_attributes[nprintedattributes-1]=n;
}

int getNumberOfScreens(struct_form *f) {
	int a;
	int scr_no=-1;
	for (a=0;a<f->metrics.metrics_len;a++) {
		if (f->metrics.metrics_val[a].scr>scr_no) {
			scr_no=f->metrics.metrics_val[a].scr;
		}
	}
	return scr_no;
}


// Get the screen dimentioned for the specified screen...
void get_screen_size_dims(struct_form *f, int scr, int *width , int *height) {
int mw=0;
int mh=0;
int a;
        for (a=0;a<f->metrics.metrics_len;a++) {
		if (f->metrics.metrics_val[a].scr!=scr)  continue;
		if (f->metrics.metrics_val[a].y>mh) { mh=f->metrics.metrics_val[a].y; }
		if ((f->metrics.metrics_val[a].x+ f->metrics.metrics_val[a].w)>mw) { mw=f->metrics.metrics_val[a].x+ f->metrics.metrics_val[a].w; }

        }
	*width=mw;
	*height=mh+1;

}


// Check if a label is just a horizontal line..
int isline(char *s) {
int a;
for (a=0;a<strlen(s);a++) {
	if (s[a]!='-') return 0;
}
return 1;
}



char *conv_to_xml_include(char *s) {
static char buff[2000];
char *ptr;
strcpy(buff,s);
while (1) {
	ptr=strchr(buff,'\n');
	if (ptr==0) break;
	*ptr='|';
}
while (1) {
	ptr=strchr(buff,'\t');
	if (ptr==0) break;
	*ptr=':';
}


//@FIXME - a NULL in the include is printed as NULL 
return buff;

}


// Check if a field uses a specified metric
int is_metric(struct_form *f, int field_no, int metric_no) {
int b;
      for (b = 0; b < f->fields.fields_val[field_no].metric.metric_len; b++)
        {
		if (f->fields.fields_val[field_no].metric.metric_val[b]==metric_no) {
				return 1;
		} 
        }
	return 0;
}


void get_attribs(struct_form *f, int attr_no, char *buff,int mode,int metric_no) {
struct struct_scr_field *fprop;
char smbuff[200];
strcpy(buff, "");
int formonly;

fprop=&f->attributes.attributes_val[attr_no];

        if (strcmp(f->attributes.attributes_val[attr_no].tabname,"formonly")==0) {
		formonly=1;
	} else {
		formonly=0;
	}

if (mode==0) { // FormField 
        if (formonly) {

            if (isCharType(f->attributes.attributes_val[attr_no].datatype)) {
               if (f->attributes.attributes_val[attr_no].dtype_size==0) {
                     f->attributes.attributes_val[attr_no].dtype_size=f->metrics.metrics_val[metric_no].w;
               }
            }
            }
		      sprintf(smbuff,",\"sqlType\":\"%s\"", get_sql_dtype(f->attributes.attributes_val[attr_no].datatype+
               (f->attributes.attributes_val[attr_no].dtype_size<<16)));
		      strcat(buff,smbuff);
	if (A4GL_has_bool_attribute(fprop, FA_B_NOENTRY)) { strcat(buff, ",\"noEntry\":true"); }
	if (A4GL_has_bool_attribute(fprop, FA_B_REQUIRED)) { strcat(buff, ",\"required\":true"); }
	if (A4GL_has_bool_attribute(fprop, FA_B_HIDDEN) || A4GL_has_bool_attribute(fprop, FA_B_INVISIBLE) ) { strcat(buff, ",\"hidden\"=true"); }
	if (A4GL_has_bool_attribute(fprop, FA_B_HIDDEN) ) { strcat(buff, ",\"noshow\"=true"); }
	if (A4GL_has_str_attribute(fprop, FA_S_INCLUDE)) { 
			sprintf(smbuff, ",\"include\":\"%s\"", xml_escape(conv_to_xml_include(A4GL_get_str_attribute (fprop, FA_S_INCLUDE)))); 
			strcat(buff,smbuff);}
	
	if (f->attributes.attributes_val[attr_no].not_null) {
	 	strcat(buff, ",\"notNull\":true"); 
	}
	if (A4GL_has_str_attribute(fprop, FA_S_DEFAULT)) { sprintf(smbuff, ",\"defaultValue\":\"%s\"", xml_escape(A4GL_get_str_attribute (fprop, FA_S_DEFAULT))); strcat(buff,smbuff);}
	if (A4GL_has_str_attribute(fprop, FA_S_TEXT)) { sprintf(smbuff, ",\"text\":\"%s\"", xml_escape(A4GL_get_str_attribute (fprop, FA_S_TEXT))); strcat(buff,smbuff);}
	if (A4GL_has_str_attribute(fprop, FA_S_HEADER)) { sprintf(smbuff, ",\"header\":\"%s\"", xml_escape(A4GL_get_str_attribute (fprop, FA_S_HEADER))); strcat(buff,smbuff);}

}

if (mode==1) { // the label/button/field itself
	if (A4GL_has_bool_attribute(fprop, FA_B_UPSHIFT)) { strcat(buff, ",\"shift\":\"up\""); }
	else {
		if (A4GL_has_bool_attribute(fprop, FA_B_DOWNSHIFT)) { strcat(buff, ",\"shift\":\"down\""); }
	}
	if (A4GL_has_bool_attribute(fprop, FA_B_AUTONEXT)) { strcat(buff, ",\"autoNext\":true"); }
	if (A4GL_has_str_attribute(fprop, FA_S_ACTION)) { sprintf(smbuff, ",\"action\":\"%s\"", xml_escape(A4GL_get_str_attribute (fprop, FA_S_ACTION))); strcat(buff,smbuff);}
	if (A4GL_has_str_attribute(fprop, FA_S_IMAGE)) { sprintf(smbuff, ",\"image\":\"%s\"", xml_escape(A4GL_get_str_attribute (fprop, FA_S_IMAGE))); strcat(buff,smbuff);}
	if (A4GL_has_str_attribute(fprop, FA_S_JUSTIFY)) { sprintf(smbuff, ",\"justify\":\"%s\"", xml_escape(A4GL_get_str_attribute (fprop, FA_S_JUSTIFY))); strcat(buff,smbuff);}
	if (A4GL_has_str_attribute(fprop, FA_S_STYLE)) { sprintf(smbuff, ",\"style\":\"%s\"", xml_escape(A4GL_get_str_attribute (fprop, FA_S_STYLE))); strcat(buff,smbuff);}
	if (A4GL_has_str_attribute(fprop, FA_S_COMMENTS)) { sprintf(smbuff, ",\"comments\":\"%s\"", xml_escape(A4GL_get_str_attribute (fprop, FA_S_COMMENTS))); strcat(buff,smbuff);}
	if (A4GL_has_str_attribute(fprop, FA_S_PICTURE)) { sprintf(smbuff, ",\"picture\":\"%s\"", xml_escape(A4GL_get_str_attribute (fprop, FA_S_PICTURE))); strcat(buff,smbuff);}
	if (A4GL_has_str_attribute(fprop, FA_S_CONFIG)) { sprintf(smbuff, ",\"config\":\"%s\"", xml_escape(A4GL_get_str_attribute (fprop, FA_S_CONFIG))); strcat(buff,smbuff);}
	if (A4GL_has_bool_attribute(fprop, FA_B_SCROLL)) { strcat(buff, ",\"scroll\":true"); }
	if (A4GL_has_bool_attribute(fprop, FA_B_WANTTABS)) { strcat(buff, ",\"wantTabs\":true"); }
	if (A4GL_has_bool_attribute(fprop, FA_B_WANTNORETURNS)) { strcat(buff, ",\"wantNoReturns\":true"); }
	if (A4GL_has_bool_attribute(fprop, FA_B_FONTPITCHFIXED)) { strcat(buff, ",\"fontPitch\":\"fixed\""); }
	if (A4GL_has_bool_attribute(fprop, FA_B_FONTPITCHVARIABLE)) { strcat(buff, ",\"fontPitch\":\"variable\""); }

	if (A4GL_has_bool_attribute(fprop, FA_B_SCROLLBARS_BOTH)) { strcat(buff, ",\"scrollBars\":\"both\""); }
	if (A4GL_has_bool_attribute(fprop, FA_B_SCROLLBARS_VERTICAL)) { strcat(buff, ",\"scrollBars\":\"vertical\""); }
	if (A4GL_has_bool_attribute(fprop, FA_B_SCROLLBARS_HORIZONAL)) { strcat(buff, ",\"scrollBars\":\"horizontal\""); }

	if (A4GL_has_bool_attribute(fprop, FA_B_STRETCH_Y)) { strcat(buff, ",\"stretch\":\"y\""); }
	if (A4GL_has_bool_attribute(fprop, FA_B_STRETCH_BOTH)) { strcat(buff, ",\"stretch\":\"both\""); }


	if (A4GL_has_bool_attribute(fprop, FA_B_AUTOSCALE)) { strcat(buff, ",\"autoScale\":true"); }
	if (A4GL_has_str_attribute(fprop, FA_S_PIXELWIDTH)) { sprintf(smbuff, ",\"pixelWidth\":\"%s\"", xml_escape(A4GL_get_str_attribute (fprop, FA_S_PIXELWIDTH))); strcat(buff,smbuff);}
	if (A4GL_has_str_attribute(fprop, FA_S_PIXELHEIGHT)) { sprintf(smbuff, ",\"pixelHeight\":\"%s\"", xml_escape(A4GL_get_str_attribute (fprop, FA_S_PIXELHEIGHT))); strcat(buff,smbuff);}

	if (A4GL_has_str_attribute(fprop, FA_S_FORMAT)) { sprintf(smbuff, ",\"format\":\"%s\"", xml_escape(A4GL_get_str_attribute (fprop, FA_S_FORMAT))); strcat(buff,smbuff);}


	if (A4GL_has_str_attribute(fprop, FA_S_VALUEMIN)) { sprintf(smbuff, ",\"valueMin\":\"%s\"", xml_escape(A4GL_get_str_attribute (fprop, FA_S_VALUEMIN))); strcat(buff,smbuff);}
	if (A4GL_has_str_attribute(fprop, FA_S_VALUEMAX)) { sprintf(smbuff, ",\"valueMax\":\"%s\"", xml_escape(A4GL_get_str_attribute (fprop, FA_S_VALUEMAX))); strcat(buff,smbuff);}

	if (A4GL_has_str_attribute(fprop, FA_S_VALUECHECKED)) { sprintf(smbuff, ",\"valueChecked\":\"%s\"", xml_escape(A4GL_get_str_attribute (fprop, FA_S_VALUECHECKED))); strcat(buff,smbuff);}
	if (A4GL_has_str_attribute(fprop, FA_S_VALUEUNCHECKED)) { sprintf(smbuff, ",\"valueUnchecked\":\"%s\"", xml_escape(A4GL_get_str_attribute (fprop, FA_S_VALUEUNCHECKED))); strcat(buff,smbuff);}
}


}




int isLabel(struct_form *f,int attr_no) {
char *s;
struct struct_scr_field *fprop;
fprop=&f->attributes.attributes_val[attr_no];
	if (!A4GL_has_str_attribute(fprop, FA_S_WIDGET) && !A4GL_has_str_attribute(fprop, FA_S_WIDGETTYPE)) return 0;
	if (A4GL_has_str_attribute(fprop, FA_S_WIDGET)) {
		s= A4GL_get_str_attribute (fprop, FA_S_WIDGET);
		if (A4GL_aubit_strcasecmp(s,"label")==0) return 1;
	}
	if (A4GL_has_str_attribute(fprop, FA_S_WIDGETTYPE)) {
		s= A4GL_get_str_attribute (fprop, FA_S_WIDGETTYPE);
		if (A4GL_aubit_strcasecmp(s,"label")==0) return 1;
	}
return 0;
}




void print_widget(struct_form *f, int metric_no, int attr_no,char *why) {
char *old_style_widget=0;
char *new_style_widget=0;
struct struct_scr_field *fprop;
fprop=&f->attributes.attributes_val[attr_no];

if (A4GL_has_str_attribute(fprop, FA_S_WIDGET)) {
	old_style_widget=A4GL_get_str_attribute (fprop, FA_S_WIDGET);
}

if (A4GL_has_str_attribute(fprop, FA_S_WIDGETTYPE)) {
	new_style_widget=A4GL_get_str_attribute (fprop, FA_S_WIDGETTYPE);
}




if (new_style_widget) {
	if (A4GL_aubit_strcasecmp(new_style_widget,"label")==0) {
		print_label_attr(f,metric_no,attr_no,0,why);
		return;
	}

	if (A4GL_aubit_strcasecmp(new_style_widget,"ButtonEdit")==0) {
		print_buttonedit_attr(f,metric_no,attr_no,0,why);
		return;
	}

	if (A4GL_aubit_strcasecmp(new_style_widget,"Button")==0) {
		print_button_attr(f,metric_no,attr_no,0,why);
		return;
	}

	if (A4GL_aubit_strcasecmp(new_style_widget,"Browser")==0) {
		print_browser_attr(f,metric_no,attr_no,0,why);
		return;
	}

	if (A4GL_aubit_strcasecmp(new_style_widget,"DateEdit")==0) {
		print_dateedit_attr(f,metric_no,attr_no,0,why);
		return;
	}
	if (A4GL_aubit_strcasecmp(new_style_widget,"Image")==0) {
		print_image_attr(f,metric_no,attr_no,0,why);
		return;
	}
	if (A4GL_aubit_strcasecmp(new_style_widget,"ComboBox")==0) {
		print_combobox_attr(f,metric_no,attr_no,0,why);
		return;
	}
	if (A4GL_aubit_strcasecmp(new_style_widget,"Radio")==0) {
		print_radio_attr(f,metric_no,attr_no,0,why);
		return;
	}
	if (A4GL_aubit_strcasecmp(new_style_widget,"CheckBox")==0) {
		print_checkbox_attr(f,metric_no,attr_no,0,why);
		return;
	}
	if (A4GL_aubit_strcasecmp(new_style_widget,"ProgressBar")==0) {
		print_progressbar_attr(f,metric_no,attr_no,0,why);
		return;
	}
	if (A4GL_aubit_strcasecmp(new_style_widget,"TextEdit")==0) {
		print_textedit_attr(f,metric_no,attr_no,0,why);
		return;
	}
	print_unknown_widget_attr(f,new_style_widget, metric_no,attr_no,0,why);
	return;

	//printf("Unhandled widget : %s\n", new_style_widget);
	//exit(2);
}


if (old_style_widget) {
	if (A4GL_aubit_strcasecmp(old_style_widget,"label")==0) {
		print_label_attr(f,metric_no,attr_no,1,why);
		return;
	}
	if (A4GL_aubit_strcasecmp(old_style_widget,"ButtonEdit")==0) {
		print_buttonedit_attr(f,metric_no,attr_no,1,why);
		return;
	}

	if (A4GL_aubit_strcasecmp(old_style_widget,"Browser")==0) {
		print_browser_attr(f,metric_no,attr_no,1,why);
		return;
	}

	if (A4GL_aubit_strcasecmp(old_style_widget,"Button")==0) {
		print_button_attr(f,metric_no,attr_no,1,why);
		return;
	}
	if (A4GL_aubit_strcasecmp(old_style_widget,"DateEdit")==0) {
		print_dateedit_attr(f,metric_no,attr_no,1,why);
		return;
	}
	if (A4GL_aubit_strcasecmp(old_style_widget,"Image")==0) {
		print_image_attr(f,metric_no,attr_no,1,why);
		return;
	}
	if (A4GL_aubit_strcasecmp(old_style_widget,"ComboBox")==0) {
		print_combobox_attr(f,metric_no,attr_no,1,why);
		return;
	}
	if (A4GL_aubit_strcasecmp(old_style_widget,"Radio")==0) {
		print_radio_attr(f,metric_no,attr_no,1,why);
		return;
	}
	if (A4GL_aubit_strcasecmp(old_style_widget,"ProgressBar")==0) {
		print_progressbar_attr(f,metric_no,attr_no,1,why);
		return;
	}
	if (A4GL_aubit_strcasecmp(old_style_widget,"TextEdit")==0) {
		print_textedit_attr(f,metric_no,attr_no,1,why);
		return;
	}
	print_unknown_widget_attr(f,old_style_widget, metric_no,attr_no,0,why);
	return;
	//printf("Unhandled widget : %s\n", old_style_widget);
	//exit(2);
}


print_entry(f,metric_no,attr_no,why);

}


void print_entry (struct_form *f, int metric_no, int attr_no,char *why) {
char buff[2000];
char posbuf[200];
	sprintf(posbuf,",\"posY\":%d,\"posX\":%d,\"gridWidth\":%d", f->metrics.metrics_val[metric_no].y, f->metrics.metrics_val[metric_no].x, f->metrics.metrics_val[metric_no].w);
	if (strcmp(why,"Table")==0) {
		strcpy(posbuf,""); // posX and posY are not used for tables...
	}

	if (A4GL_has_bool_attribute(&f->attributes.attributes_val[attr_no], FA_B_WORDWRAP)) {
		print_textedit_attr(f,metric_no,attr_no,2,why);
		return;
	}

	get_attribs(f, attr_no, buff,1,metric_no);

	fprintf(ofile, "  {\"type\":\"Edit\",\"width\":%d %s %s}\n",
                        f->metrics.metrics_val[metric_no].w,
			buff, posbuf);

}

// Prints a field thats defined as a buttonedit widgettype
void print_buttonedit_attr(struct_form *f, int metric_no, int attr_no,int oldstyle,char *why) {
//char *s;
char buff[2000];
char posbuf[200];
 get_attribs(f, attr_no, buff,1,metric_no);
	sprintf(posbuf,", \"posY\":%d, \"posX\":%d, \"gridWidth\":%d", f->metrics.metrics_val[metric_no].y, f->metrics.metrics_val[metric_no].x, f->metrics.metrics_val[metric_no].w);
	if (strcmp(why,"Table")==0) {
		strcpy(posbuf,""); // posX and posY are not used for tables...
	}


	if (oldstyle) {
			fprintf(ofile, "  {\"type\":\"ButtonEdit\" %s,\"width\":%d %s},\n", buff, f->metrics.metrics_val[metric_no].w, posbuf);

        } else {
			fprintf(ofile, "  {\"type\":\"ButtonEdit\" %s,\"width\":%d %s},\n", buff, f->metrics.metrics_val[metric_no].w, posbuf);
        }
	return ;
}

// Prints a field thats defined as a buttonedit widgettype
void print_button_attr(struct_form *f, int metric_no, int attr_no,int oldstyle,char *why) {
//char *s;
char buff[2000];
char posbuf[200];
 get_attribs(f, attr_no, buff,1,metric_no);
	sprintf(posbuf," posY:%d,posX:%d,gridWidth:%d", f->metrics.metrics_val[metric_no].y, f->metrics.metrics_val[metric_no].x, f->metrics.metrics_val[metric_no].w);
	if (strcmp(why,"Table")==0) {
		strcpy(posbuf,""); // posX and posY are not used for tables...
	}


	if (oldstyle) {
			fprintf(ofile, "  {\"type\":\"Button\" %s,\"width\":%d %s },\n", buff, f->metrics.metrics_val[metric_no].w, posbuf);

        } else {
			fprintf(ofile, "        {\"type\":\"Button\" %s, \"width\":%d %s},\n", buff, f->metrics.metrics_val[metric_no].w, posbuf);
        }
	return ;
}


// Prints a field thats defined as a buttonedit widgettype
void print_browser_attr(struct_form *f, int metric_no, int attr_no,int oldstyle,char *why) {
//char *s;
char buff[2000];
char posbuf[200];
 get_attribs(f, attr_no, buff,1,metric_no);
	sprintf(posbuf," \"posY\":%d,\"posX\":%d, \"gridWidth\":%d", f->metrics.metrics_val[metric_no].y, f->metrics.metrics_val[metric_no].x, f->metrics.metrics_val[metric_no].w);
	if (strcmp(why,"Table")==0) {
		strcpy(posbuf,""); // posX and posY are not used for tables...
	}


	if (oldstyle) {
			fprintf(ofile, "        {\"type\":\"Browser\" %s,\"width\":%d %s },\n", buff, f->metrics.metrics_val[metric_no].w, posbuf);

        } else {
			fprintf(ofile, "        {\"type\":\"Browser\" %s,\"width\":%d %s},\n", buff, f->metrics.metrics_val[metric_no].w, posbuf);
        }
	return ;
}




void print_checkbox_attr(struct_form *f, int metric_no, int attr_no,int oldstyle,char *why) {
//char *s;
char buff[2000];
char posbuf[200];

/*
struct_scr_field *fprop;
fprop=&f->attributes.attributes_val[attr_no];
*/

 get_attribs(f, attr_no, buff,1,metric_no);
	sprintf(posbuf," \"posY\":%d,\"posX\":%d, \"gridWidth\":%d", f->metrics.metrics_val[metric_no].y, f->metrics.metrics_val[metric_no].x, f->metrics.metrics_val[metric_no].w);
	if (strcmp(why,"Table")==0) {
		strcpy(posbuf,""); // posX and posY are not used for tables...
	}


	if (oldstyle) {
			fprintf(ofile, "        {\"type\":\"CheckBox\" %s,\"width\":%d %s },\n", buff, f->metrics.metrics_val[metric_no].w, posbuf);

        } else {
			fprintf(ofile, "        {\"type\":\"CheckBox\" %s,\"width\":%d %s },\n", buff, f->metrics.metrics_val[metric_no].w, posbuf);
        }
	return ;
}

void print_combobox_attr(struct_form *f, int metric_no, int attr_no,int oldstyle,char *why) {
//char *s;
char buff[2000];
char posbuf[200];

struct_scr_field *fprop;
fprop=&f->attributes.attributes_val[attr_no];
 get_attribs(f, attr_no, buff,1,metric_no);
	sprintf(posbuf," \"posY\":%d,\"posX\":%d, \"gridWidth\":%d", f->metrics.metrics_val[metric_no].y, f->metrics.metrics_val[metric_no].x, f->metrics.metrics_val[metric_no].w);
	if (strcmp(why,"Table")==0) {
		strcpy(posbuf,""); // posX and posY are not used for tables...
	}


	if (oldstyle) {
			fprintf(ofile, "        {\"type\":\"ComboBox\" %s,\"width\":%d %ss \n", buff, f->metrics.metrics_val[metric_no].w, posbuf);

        } else {
			fprintf(ofile, "        {\"type\":\"ComboBox\" %s,\"width\":%d %s \n", buff, f->metrics.metrics_val[metric_no].w, posbuf);
        }
	// print the items...
	if (A4GL_has_str_attribute(fprop, FA_S_ITEMS)) { 
			char *ptr;
		char *p2;
		fprintf(ofile,",\"items\":[");
		int printed=0;
			strcpy(buff, A4GL_get_str_attribute (fprop, FA_S_ITEMS));
			ptr=buff;
			while (ptr) {
				p2=strchr(ptr,'\n');
				if (p2) *p2=0;
				if (printed) fprintf(ofile,",\n");
				else fprintf(ofile,"\n");
				printed=1;
				fprintf(ofile, "          {\"name\":\"%s\",\"text\":\"%s\"}", ptr,ptr);
				if (p2==0) break;
				ptr=p2+1;
			}
		fprintf(ofile,"]");
	}
	fprintf(ofile, "  },\n");
	return ;
}

void print_radio_attr(struct_form *f, int metric_no, int attr_no,int oldstyle,char *why) {
//char *s;
char buff[2000];
char posbuf[200];

struct_scr_field *fprop;
fprop=&f->attributes.attributes_val[attr_no];
 get_attribs(f, attr_no, buff,1,metric_no);
	sprintf(posbuf," \"posY\":%d,\"posX\":%d, \"gridWidth\":%d", f->metrics.metrics_val[metric_no].y, f->metrics.metrics_val[metric_no].x, f->metrics.metrics_val[metric_no].w);
	if (strcmp(why,"Table")==0) {
		strcpy(posbuf,""); // posX and posY are not used for tables...
	}


	if (oldstyle) {
			fprintf(ofile, "        {\"type\":\"RipRADIO\" %s,\"width\":%d %s\n", buff, f->metrics.metrics_val[metric_no].w, posbuf);

        } else {
			fprintf(ofile, "        {\"type\":\"Radio\" %s,\"width\":%d %s\n", buff, f->metrics.metrics_val[metric_no].w, posbuf);
	// print the items...
	if (A4GL_has_str_attribute(fprop, FA_S_ITEMS)) { 
			char *ptr;
		char *p2;
			strcpy(buff, A4GL_get_str_attribute (fprop, FA_S_ITEMS));
			ptr=buff;
			fprintf(ofile,",\"items\":[");
			int printed=0;
			while (ptr) {
				if (printed) fprintf(ofile,",\n");
				else fprintf(ofile,"\n");
				printed=1;
				p2=strchr(ptr,'\n');
				if (p2) *p2=0;
				fprintf(ofile, "          {name:\"%s\" text:\"%s\"}", ptr,ptr);
				if (p2==0) break;
				ptr=p2+1;
			}
		fprintf(ofile,"]");
	}
	fprintf(ofile, " },\n");
        }
	return ;
}


void print_progressbar_attr(struct_form *f, int metric_no, int attr_no,int oldstyle,char *why) {
//char *s;
char buff[2000];
char posbuf[200];
 get_attribs(f, attr_no, buff,1,metric_no);
	sprintf(posbuf," \"posY\":%d,\"posX\":%d, \"gridWidth\":%d", f->metrics.metrics_val[metric_no].y, f->metrics.metrics_val[metric_no].x, f->metrics.metrics_val[metric_no].w);
	if (strcmp(why,"Table")==0) {
		strcpy(posbuf,""); // posX and posY are not used for tables...
	}


	if (oldstyle) {
			fprintf(ofile, "  <ProgressBar %s width=%d %s />\n", buff, f->metrics.metrics_val[metric_no].w, posbuf);

        } else {
			fprintf(ofile, "  <ProgressBar %s width=%d %s/>\n", buff, f->metrics.metrics_val[metric_no].w, posbuf);
        }
	return ;
}

// Prints a field thats defined as a image widgettype
void print_image_attr(struct_form *f, int metric_no, int attr_no,int oldstyle,char *why) {
//char *s;
char buff[2000];
char posbuf[200];

 get_attribs(f, attr_no, buff,1,metric_no);
	sprintf(posbuf," \"posY\":%d,\"posX\":%d, \"gridWidth\":%d", f->metrics.metrics_val[metric_no].y, f->metrics.metrics_val[metric_no].x, f->metrics.metrics_val[metric_no].w);
	if (strcmp(why,"Table")==0) {
		strcpy(posbuf,""); // posX and posY are not used for tables...
	}


	if (oldstyle) {
			fprintf(ofile, "  <Image %s width=%d %s />\n", buff, f->metrics.metrics_val[metric_no].w, posbuf);

        } else {
			fprintf(ofile, "  <Image %s width=%d %s/>\n", buff, f->metrics.metrics_val[metric_no].w, posbuf);
        }
	return ;
}

// Prints a field thats defined as a label widgettype
void print_unknown_widget_attr(struct_form *f, char *widget, int metric_no, int attr_no,int oldstyle,char *why) {
//char *s;
char buff[2000];
 get_attribs(f, attr_no, buff,1,metric_no);
char posbuf[200];
	sprintf(posbuf," \"posY\":%d,\"posX\":%d, \"gridWidth\":%d", f->metrics.metrics_val[metric_no].y, f->metrics.metrics_val[metric_no].x, f->metrics.metrics_val[metric_no].w);
	if (strcmp(why,"Table")==0) {
		strcpy(posbuf,""); // posX and posY are not used for tables...
	}


	if (oldstyle) {
			fprintf(ofile, "  <Widget Type=\"%s\" %s width=%d %s />\n",xml_escape(widget),  buff, f->metrics.metrics_val[metric_no].w, posbuf);

        } else {
			fprintf(ofile, "  <Widget Type=\"%s\" %s width=%d %s/>\n", xml_escape(widget), buff, f->metrics.metrics_val[metric_no].w, posbuf);
        }
	return ;
}





// Prints a field thats defined as a label widgettype
void print_dateedit_attr(struct_form *f, int metric_no, int attr_no,int oldstyle,char *why) {
//char *s;
char buff[2000];
char posbuf[200];
	sprintf(posbuf," \"posY\":%d,\"posX\":%d, \"gridWidth\":%d", f->metrics.metrics_val[metric_no].y, f->metrics.metrics_val[metric_no].x, f->metrics.metrics_val[metric_no].w);
	if (strcmp(why,"Table")==0) {
		strcpy(posbuf,""); // posX and posY are not used for tables...
	}
 get_attribs(f, attr_no, buff,1,metric_no);

	if (oldstyle) {
			fprintf(ofile, "  <DateEdit %s width=%d %s />\n", 
				buff,
			f->metrics.metrics_val[metric_no].w, posbuf
			);

        } else {
			fprintf(ofile, "  <DateEdit %s width=%d %s />\n", 
				buff,
				f->metrics.metrics_val[metric_no].w, posbuf
				);
        }
	return ;
}

// Prints a field thats defined as a label widgettype
void print_textedit_attr(struct_form *f, int metric_no, int attr_no,int oldstyle,char *why) {
//char *s;
char buff[2000];
char posbuf[200];
	sprintf(posbuf,",\"posY\":%d,\"posX\":%d, \"gridWidth\":%d", f->metrics.metrics_val[metric_no].y, f->metrics.metrics_val[metric_no].x, f->metrics.metrics_val[metric_no].w);
	if (strcmp(why,"Table")==0) {
		strcpy(posbuf,""); // posX and posY are not used for tables...
	}
//printf("Heigh=%d\n",  f->metrics.metrics_val[metric_no].h);
        get_attribs(f, attr_no, buff,1,metric_no);
 	if (strstr(buff, ",\"scroll\":")==0 && oldstyle!=2) { 
		// Seems to always have scroll=1
		strcat(buff,",\"scroll\":true");
	}
	if (f->metrics.metrics_val[metric_no].h!=1) {
		char smbuff[200];
		sprintf(smbuff,",\"height\"=%d", f->metrics.metrics_val[metric_no].h);
		strcat(buff,smbuff);
	}

	if (oldstyle) {
		if (oldstyle==2) {
			fprintf(ofile, "        {\"type\":\"TextEdit\" %s,\"width\":%d,\"scrollBars\":\"none\" %s }\n", buff, f->metrics.metrics_val[metric_no].w,posbuf);
		} else {
			fprintf(ofile, "        {\"type\":\"TextEdit\" %s,\"width\":%d %s }\n", buff, f->metrics.metrics_val[metric_no].w,posbuf);
		}

        } else {
			fprintf(ofile, "        {\"type\":\"TextEdit\" %s,\"width\":%d %s }\n", 
				buff,
				f->metrics.metrics_val[metric_no].w, posbuf);
        }
	return ;
}


// Prints a field thats defined as a label widgettype
void print_label_attr(struct_form *f, int metric_no, int attr_no,int oldstyle,char *why) {
//char *s;
char posbuf[200];
	sprintf(posbuf," \"posY\":%d,\"posX\":%d, \"gridWidth\":%d", f->metrics.metrics_val[metric_no].y, f->metrics.metrics_val[metric_no].x, f->metrics.metrics_val[metric_no].w);
	if (strcmp(why,"Table")==0) {
		strcpy(posbuf,""); // posX and posY are not used for tables...
	}

	if (oldstyle) {
			fprintf(ofile, "        {\"type\":\"RipLABEL\",width:%d %s }\n", 
			f->metrics.metrics_val[metric_no].w,posbuf);

        } else {
		/*
		struct_scr_field *fprop;
		fprop=&f->attributes.attributes_val[attr_no];
		*/
		char buff[2000];
		char smbuff[200];
 		get_attribs(f, attr_no, buff,1,metric_no);
		sprintf(smbuff," name:\"%s\"", f->attributes.attributes_val[attr_no].colname);
		strcat(buff,smbuff);
        	//if (A4GL_has_str_attribute(fprop, FA_S_TEXT)) { sprintf(smbuff, " text=\"%s\"", xml_escape(A4GL_get_str_attribute (fprop, FA_S_TEXT))); strcat(buff,smbuff);}

		fprintf(ofile, "        {\"type\":\"Label\" width:%d %s %s }\n", 
				f->metrics.metrics_val[metric_no].w,	buff,
				posbuf);
        }
	return ;
}



int isInScreenArray(struct_form *f, int attr_no,int *dim,char *scrname) {
int a;
int b;
for (a=0;a<f->records.records_len;a++) {
	if (f->records.records_val[a].dim<=1) continue; // Single dimensions we dont care about..
	for (b=0;b<f->records.records_val[a].attribs.attribs_len;b++) {
		if (f->records.records_val[a].attribs.attribs_val[b]==attr_no) {
				*dim=f->records.records_val[a].dim;
				if (scrname) {
				strcpy(scrname,f->records.records_val[a].name);
				}
				return 1;
		}
	}
}
return 0;
}



void printRecordView(struct_form *f) {
int a;
int b;

fprintf(ofile,"      ,\"Records\":[\n");
for (a=0;a<f->records.records_len;a++) {
	if (a>0) fprintf(ofile,",\n");
	
	fprintf(ofile,"           { \"tabName\":\"%s\", \"items\":[\n", f->records.records_val[a].name);
	for (b=0;b<f->records.records_val[a].attribs.attribs_len;b++) {
		int attr_no;
		attr_no=f->records.records_val[a].attribs.attribs_val[b];
		if (b>0) fprintf(ofile,",\n");
		fprintf(ofile,"              { \"colName\":\"%s\",\"fieldIdRef\":%d}", f->attributes.attributes_val[attr_no].colname,
				attr_no);
	}
	fprintf(ofile,"]}");
}
fprintf(ofile,"\n      ]\n");
}


int fieldOccursMultipleTimes(struct_form *f, int attr_no,int *dim) {
int field_no;
field_no= f->attributes.attributes_val[attr_no].field_no;
*dim=f->fields.fields_val[field_no].metric.metric_len;
return (f->fields.fields_val[field_no].metric.metric_len>1);
}

int fieldOccursHowManyTimes(struct_form *f, int attr_no,int *dim) {
int field_no;
field_no= f->attributes.attributes_val[attr_no].field_no;
*dim=f->fields.fields_val[field_no].metric.metric_len;
//A4GL_pause_execution();
return f->fields.fields_val[field_no].metric.metric_len;
}



static void size_matrix(struct_form *f,int attr_no,int *offset_x, int *fields_across) {
int field_no;
int metric;
int startx=-1;
int starty=-1;
//int maxx=-1;
//int maxy=-1;
int a;
//int fields_across;
int fields_down;


*offset_x=-1;
field_no=f->attributes.attributes_val[attr_no].field_no;
//metric=f->fields.fields_val[field_no].metric.metric_val[metric];
*fields_across=0;
fields_down=0;

	for (a=0;a<f->fields.fields_val[field_no].metric.metric_len;a++) {
		metric=f->fields.fields_val[field_no].metric.metric_val[a];	
		if (a==0) {
			fields_down=1;
			*fields_across=1;
			startx= f->metrics.metrics_val[metric].x;
			starty= f->metrics.metrics_val[metric].y;
			continue;
		}

		if (f->metrics.metrics_val[metric].y==starty) {
			// Its on the same line as the first field...
			*fields_across=(*fields_across)+1;
			if (*offset_x==-1) *offset_x=f->metrics.metrics_val[metric].x-startx;
		}
		if (f->metrics.metrics_val[metric].x==startx) {
			// Its on the same line as the first field...
			fields_down++;
		}
	}
	//printf("offset_x=%d ", offset_x);
	//printf("fields_across=%d fields_down=%d\n", fields_across, fields_down);
}

void
print_field_attribute (struct_form * f, int metric_no, int attr_no)
{
  char buff[2000];
  int dim=0;
  int dim1=0;
  int ismatrix;


  get_attribs (f, attr_no, buff, 0,metric_no);

  fieldNo=attr_no;
  if (isInScreenArray (f, attr_no, &dim1,NULL)) {
		ismatrix=1;
		dim=dim1;
  } else {
	if (fieldOccursMultipleTimes(f, attr_no,&dim1)) {
	//A4GL_pause_execution();
		ismatrix=1;
		dim=dim1;
		if (dim==0) {
			dim=fieldOccursHowManyTimes(f, attr_no,&dim1);
		}
	} else {
		ismatrix=0;
	}
 }
 if (ismatrix) 
    {
	int stepx;
	int column_count;
	int useTabIndex;
	struct struct_scr_field *fprop;
	if (hasPrintedAttribute(attr_no)) return;
	addPrintedAttribute(attr_no);
  	tabIndex++;
	size_matrix(f,attr_no,&stepx,&column_count);
	useTabIndex = tabIndex;
	fprop=&f->attributes.attributes_val[attr_no];
	if (A4GL_has_str_attribute(fprop, FA_S_TABINDEX)) {
		useTabIndex=atoi(A4GL_get_str_attribute(fprop, FA_S_TABINDEX));
	}

	if (stepx==-1) {
      		fprintf (ofile,
	       		"<Matrix pageSize=%d name:\"%s.%s\" colName=\"%s\" fieldId=%d sqlTabName=\"%s\" %s tabIndex=%d >\n", dim,
	       		f->attributes.attributes_val[attr_no].tabname, f->attributes.attributes_val[attr_no].colname,
	       		f->attributes.attributes_val[attr_no].colname, fieldNo, f->attributes.attributes_val[attr_no].tabname, buff,
	       		useTabIndex);
	} else {
      		fprintf (ofile,
	       		"<Matrix pageSize=%d name=\"%s.%s\" colName=\"%s\" fieldId=%d sqlTabName=\"%s\" %s tabIndex=%d stepX=%d columnCount=%d >\n", dim,
	       		f->attributes.attributes_val[attr_no].tabname, f->attributes.attributes_val[attr_no].colname,
	       		f->attributes.attributes_val[attr_no].colname, fieldNo, f->attributes.attributes_val[attr_no].tabname, buff,
	       		useTabIndex, stepx, column_count);

	}
	//  stepX="11" columnCount="7"

      print_widget (f, metric_no, attr_no,"Matrix");

      fprintf (ofile, "</Matrix>\n");
    }
  else
    {
	int isLabel=0;
	int useTabIndex;
	struct struct_scr_field *fprop;
	char *new_style_widget=0;
	char *new_style_widget_text=0;
	fprop=&f->attributes.attributes_val[attr_no];
	if (hasPrintedAttribute(attr_no)) return;
	addPrintedAttribute(attr_no);

  	tabIndex++;
	useTabIndex = tabIndex;

	if (A4GL_has_str_attribute(fprop, FA_S_TABINDEX)) {
		useTabIndex=atoi(A4GL_get_str_attribute(fprop, FA_S_TABINDEX));
	}
	
	if (A4GL_has_str_attribute(fprop, FA_S_WIDGETTYPE)) {
        	new_style_widget=A4GL_get_str_attribute (fprop, FA_S_WIDGETTYPE);
        	new_style_widget_text=A4GL_get_str_attribute (fprop, FA_S_TEXT); //labels with predefined text are static
        	if (A4GL_aubit_strcasecmp(new_style_widget,"label")==0 && new_style_widget_text!=0) {
			isLabel=1;
		}
        }


      if (!isLabel) {
      fprintf (ofile, "      {\"type\":\"FormField\", \"name\":\"%s.%s\",\"colName\":\"%s\",\"fieldId\":%d,\"sqlTabName\":\"%s\" %s,\"tabIndex\":%d,\"widget\":\n",
	       f->attributes.attributes_val[attr_no].tabname,
	       f->attributes.attributes_val[attr_no].colname,
	       f->attributes.attributes_val[attr_no].colname,
	       fieldNo, f->attributes.attributes_val[attr_no].tabname, buff, useTabIndex);

	}

      print_widget (f, metric_no, attr_no,"FormField");

	if (!isLabel) {
      		fprintf (ofile, "}\n");
	}
    }
}


int get_attrno_for_metric(struct_form *f, int metric_no) {
int a;
//int found=0;

for (a=0;a<f->attributes.attributes_len;a++) {
	//if ( f->attributes.attributes_val[a].field_no==0) continue;
	if (is_metric(f, f->attributes.attributes_val[a].field_no, metric_no)) {
		return a;
	}

}
return -1;
}


void print_field(struct_form *f, int metric_no) {
int a;
int found=0;

for (a=0;a<f->attributes.attributes_len;a++) {
	//if ( f->attributes.attributes_val[a].field_no==0) continue;
	if (is_metric(f, f->attributes.attributes_val[a].field_no, metric_no)) {
		// We've found our attribute..
		print_field_attribute(f, metric_no, a);
		found++;
		break;
	}
}
if (!found) {
	// probably a continuation - like a WORDWRAP...
	//A4GL_pause_execution();
	//printf("Unable to find metric %d\n", metric_no);
	//exit(2);
	return;
}
}


void get_layout_attribs(struct s_layout *layout, char *buff) {
//int a;
char smbuff[200];
struct struct_scr_field fprop1;
struct struct_scr_field *fprop;

strcpy(buff,"");
if (layout->id && strlen(layout->id )) {
	sprintf(buff,"Id=\"%s\"",layout->id);
}
	if (layout->attrib==0) return;
	fprop=&fprop1;
	fprop1.bool_attribs.bool_attribs_len=layout->attrib->bool_attribs.bool_attribs_len;
	fprop1.bool_attribs.bool_attribs_val=layout->attrib->bool_attribs.bool_attribs_val;
	
	fprop1.str_attribs.str_attribs_len=layout->attrib->str_attribs.str_attribs_len;
	fprop1.str_attribs.str_attribs_val=layout->attrib->str_attribs.str_attribs_val;


	if (A4GL_has_bool_attribute(fprop, FA_B_AUTOSIZE)) { strcat(buff, ",\"autoSize\":true"); }
	if (A4GL_has_bool_attribute(fprop, FA_B_NOENTRY)) { strcat(buff, ",\"noEntry\":true"); }
	if (A4GL_has_bool_attribute(fprop, FA_B_REQUIRED)) { strcat(buff, ",\"required\":true"); }
	if (A4GL_has_bool_attribute(fprop, FA_B_HIDDEN) || A4GL_has_bool_attribute(fprop, FA_B_INVISIBLE)) { strcat(buff, ",\"hidden\":true"); }
	if (A4GL_has_bool_attribute(fprop, FA_B_HIDDEN) ) { strcat(buff, ",\"noshow\"=true"); }
	if (A4GL_has_bool_attribute(fprop, FA_B_BORDER)) { strcat(buff, ",\"border\":true"); }
	if (A4GL_has_bool_attribute(fprop, FA_B_UPSHIFT)) { strcat(buff, ",\"shift\":\"up\""); }
	else {
		if (A4GL_has_bool_attribute(fprop, FA_B_DOWNSHIFT)) { strcat(buff, ",\"shift\":\"down\""); }
	}
	if (A4GL_has_bool_attribute(fprop, FA_B_AUTONEXT)) { strcat(buff, ",\"autoNext\":true"); }
	if (A4GL_has_str_attribute(fprop, FA_S_ACTION)) { sprintf(smbuff, ",\"action\":\"%s\"", xml_escape(A4GL_get_str_attribute (fprop, FA_S_ACTION))); strcat(buff,smbuff);}
	if (A4GL_has_str_attribute(fprop, FA_S_JUSTIFY)) { sprintf(smbuff, ",\"justify\":\"%s\"", xml_escape(A4GL_get_str_attribute (fprop, FA_S_JUSTIFY))); strcat(buff,smbuff);}
	if (A4GL_has_str_attribute(fprop, FA_S_IMAGE)) { sprintf(smbuff, ",\"image\":\"%s\"", xml_escape(A4GL_get_str_attribute (fprop, FA_S_IMAGE))); strcat(buff,smbuff);}
	if (A4GL_has_str_attribute(fprop, FA_S_STYLE)) { sprintf(smbuff, ",\"style\":\"%s\"", xml_escape(A4GL_get_str_attribute (fprop, FA_S_STYLE))); strcat(buff,smbuff);}
	if (A4GL_has_str_attribute(fprop, FA_S_TEXT)) { sprintf(smbuff, ",\"text\":\"%s\"", xml_escape(A4GL_get_str_attribute (fprop, FA_S_TEXT))); strcat(buff,smbuff);}
	if (A4GL_has_str_attribute(fprop, FA_S_COMMENTS)) { sprintf(smbuff, ",\"comments\":\"%s\"", xml_escape(A4GL_get_str_attribute (fprop, FA_S_COMMENTS))); strcat(buff,smbuff);}
	if (A4GL_has_str_attribute(fprop, FA_S_PICTURE)) { sprintf(smbuff, ",\"picture\":\"%s\"", xml_escape(A4GL_get_str_attribute (fprop, FA_S_PICTURE))); strcat(buff,smbuff);}
	if (A4GL_has_str_attribute(fprop, FA_S_CONFIG)) { sprintf(smbuff, ",\"config\":\"%s\"", xml_escape(A4GL_get_str_attribute (fprop, FA_S_CONFIG))); strcat(buff,smbuff);}

	if (A4GL_has_str_attribute(fprop, FA_S_PIXELWIDTH)) { sprintf(smbuff, ",\"pixelWidth\":\"%s\"", xml_escape(A4GL_get_str_attribute (fprop, FA_S_PIXELWIDTH))); strcat(buff,smbuff);}
	if (A4GL_has_str_attribute(fprop, FA_S_PIXELHEIGHT)) { sprintf(smbuff, ",\"pixelHeight\":\"%s\"", xml_escape(A4GL_get_str_attribute (fprop, FA_S_PIXELHEIGHT))); strcat(buff,smbuff);}

	if (A4GL_has_bool_attribute(fprop, FA_B_SCROLL)) { strcat(buff, ",\"scroll\":true"); }
	if (A4GL_has_bool_attribute(fprop, FA_B_WANTTABS)) { strcat(buff, ",\"wantTabs\":true"); }
	if (A4GL_has_bool_attribute(fprop, FA_B_WANTNORETURNS)) { strcat(buff, ",\"wantNoReturns\":true"); }
	if (A4GL_has_bool_attribute(fprop, FA_B_FONTPITCHFIXED)) { strcat(buff, ",\"fontPitch\":\"fixed\""); }
	if (A4GL_has_bool_attribute(fprop, FA_B_FONTPITCHVARIABLE)) { strcat(buff, ",\"fontPitch\":\"variable\""); }

}

void dump_group(struct_form *f, struct s_layout *layout) {
	A4GL_assertion(1,"Not implemented dump_group (no examples)");
}


void dump_folder(struct_form *f, struct s_layout *layout) {
char buff[2000];
int a;
	get_layout_attribs(layout,buff);
	fprintf(ofile,"{\"type\":\"Folder\" %s, \"items\":[\n",buff);
	for (a=0;a<layout->children.children_len;a++) {
		if (a) fprintf(ofile,",");
		dump_layout(f, layout->children.children_val[a]);
	}
	fprintf(ofile,"]}\n");
}


void dump_page(struct_form *f, struct s_layout *layout) {
char buff[2000];
int a;
	get_layout_attribs(layout,buff);
	fprintf(ofile,"{\"type\":\"Page\" %s, \"items\":[\n",buff);
	for (a=0;a<layout->children.children_len;a++) {
		if (a) fprintf(ofile,",");
		dump_layout(f, layout->children.children_val[a]);
	}
	fprintf(ofile,"]}\n");
}

void dump_vbox(struct_form *f, struct s_layout *layout) {
char buff[2000];
int a;
	get_layout_attribs(layout,buff);
	fprintf(ofile,"{\"type\":\"VBox\" %s, \"items\":[ \n",buff);
	for (a=0;a<layout->children.children_len;a++) {
		if (a) fprintf(ofile,",");
		dump_layout(f, layout->children.children_val[a]);
	}
	fprintf(ofile,"]}\n");
}

void dump_hbox(struct_form *f, struct s_layout *layout) {
char buff[2000];
int a;
	get_layout_attribs(layout,buff);
	fprintf(ofile,"{\"type\":\"HBox\" %s, \"items\":[\n",buff);
	for (a=0;a<layout->children.children_len;a++) {
		if (a) fprintf(ofile,",");
		dump_layout(f, layout->children.children_val[a]);
	}
	fprintf(ofile,"]}\n");
}

void dump_grid(struct_form *f, struct s_layout *layout) {
char buff[2000];
//int a;
	
	get_layout_attribs(layout,buff);
	if (layout->children.children_len!=0) {
		A4GL_assertion(1,"not expecting children in a grid");
	}
	dump_screen (f, layout->screen_no, SCRMODE_GRID,buff);
}

void dump_table(struct_form *f, struct s_layout *layout) {
char buff[2000];
char buff_tabcol[2000];
int a;
int scr;
int dim=-1;
char scrname[200];
char topLine[512]; // string to store label texts

memset(topLine,' ',512);
topLine[511]=0;
	
	get_layout_attribs(layout,buff);

 	scr=layout->screen_no;
 	merge_labels(f, scr);
	if (layout->children.children_len!=0) {
		A4GL_assertion(1,"not expecting children in a table");
	}

  for (a = 0; a < f->metrics.metrics_len; a++) {
		int attr_no;
      		if (f->metrics.metrics_val[a].scr != scr) continue;
		if (strlen(f->metrics.metrics_val[a].label)) continue;
		attr_no=get_attrno_for_metric(f,a);
		if (isInScreenArray (f, attr_no, &dim,scrname)) {
			break;
		}
   }


   if (dim<=1) {
		if (dim<1) {
			fprintf(stderr, "Unable to get table size\n");
			exit(2);
		}  else {
			fprintf(stderr, "Warning : Table size appears to be '1' for %s\n",scrname);
			//exit(2);
		}
   }
		


    	fprintf (ofile, "{\"type\":\"Table\",\"pageSize\":%d,\"tabName\":\"%s\" %s,\"items\":[\n",dim, scrname,buff);


// Lets set up our 'topline' with any labels on line 0...
  for (a = 0; a < f->metrics.metrics_len; a++) {
      		if (f->metrics.metrics_val[a].scr != scr) continue;
		if (strlen(f->metrics.metrics_val[a].label)) {
				if (f->metrics.metrics_val[a].y==0) {
					// Only copy if its on the first line...
					strncpy(&topLine[f->metrics.metrics_val[a].x],f->metrics.metrics_val[a].label, strlen(f->metrics.metrics_val[a].label));
				}
		}
		continue;
  }

//A4GL_trim(topLine);
//printf("TopLine=%s\n",topLine);

int printed=0;
  for (a = 0; a < f->metrics.metrics_len; a++) {
		int attr_no;
		char *txt;
		char nmbuff[512];
      		if (f->metrics.metrics_val[a].scr != scr) continue;
		if (strlen(f->metrics.metrics_val[a].label)) {
				continue;
		}
		attr_no=get_attrno_for_metric(f,a);
		if (hasPrintedAttribute(attr_no)) continue;
		addPrintedAttribute(attr_no);
  		tabIndex++;

	 	fieldNo=attr_no;
		if (printed) {
			fprintf(ofile,",\n");
		}
		printed=1;
	
		get_attribs(f, attr_no, buff_tabcol,0,a);
	//fprintf(stderr, "Find label : %d %d\n", f->metrics.metrics_val[a].x,f->metrics.metrics_val[a].y);
		txt=find_label (f->metrics.metrics_val[a].x,f->metrics.metrics_val[a].y);
		if (txt) {
			sprintf(nmbuff,",\"text\":\"%s\"",xml_escape( txt));
		} else {
			strcpy(nmbuff,"");
		}
      		fprintf (ofile, "      { \"name\":\"%s.%s\",\"colName\":\"%s\",\"fieldId\":%d,\"sqlTabName\":\"%s\" %s,\"tabIndex\":%d%s,\"widget\":", 

	       			f->attributes.attributes_val[attr_no].tabname, f->attributes.attributes_val[attr_no].colname,
	       			f->attributes.attributes_val[attr_no].colname, fieldNo, f->attributes.attributes_val[attr_no].tabname, buff_tabcol,
	       			tabIndex, nmbuff);

      		print_widget (f, a, attr_no,"Table");

      		fprintf (ofile, "      }");
   }
  fprintf (ofile, "]}\n");
	
}


void dump_layout(struct_form *f, struct s_layout *layout) {

	switch (layout->layout_type) {
		case LAYOUT_GRID:
			dump_grid(f,layout);
			break;
        	case LAYOUT_HBOX:
			dump_hbox(f,layout);
			break;
        	case LAYOUT_VBOX:
			dump_vbox(f,layout);
			break;
        	case LAYOUT_GROUP:
			dump_group(f,layout);
			break;
        	case LAYOUT_FOLDER:
			dump_folder(f,layout);
			break;
        	case LAYOUT_PAGE:
			dump_page(f,layout);
			break;
        	case LAYOUT_TABLE:
			dump_table(f,layout);
			break;
        	case LAYOUT_NOTSET:
			A4GL_assertion(1,"Layout not set");
			break;
	}
}


void dump_form_layout(struct_form *f) {
int n=0;

fprintf(ofile,",\"layout\":[");
	if (f->layout->layout_type==LAYOUT_TABLE) {
		fprintf(ofile,"<VBox >\n");
		n++;
	}
 	dump_layout(f, f->layout);
	if (n) {
		fprintf(ofile,"</VBox>\n");
	}
fprintf(ofile,"]");
}




void
new_field (int y, int x, int w, char because_of, int fstart)
{
  char buff[2000];
  strcpy (buff, &screen[y][x]);
  buff[w] = 0;
//printf("new field: %d\n",nfields);

  nfields++;
  screen_convert_fields = realloc (screen_convert_fields, sizeof (struct s_field) * nfields);
  screen_convert_fields[nfields - 1].x = x;
  screen_convert_fields[nfields - 1].y = y;
  screen_convert_fields[nfields - 1].w = w;
  screen_convert_fields[nfields - 1].label = strdup (buff);
  screen_convert_fields[nfields - 1].field_start = fstart;
}



static int has_label_ending(int x,int y) {
  int a;
  for (a = 0; a < nfields; a++) {
      if (y==screen_convert_fields[a].y) continue; 	// Same line doesn't count..

      if (screen_convert_fields[a].label == 0)
	continue;

      if (screen_convert_fields[a].y==y-1 || screen_convert_fields[a].y==y+1) {
		if (screen_convert_fields[a].x+screen_convert_fields[a].w==x) return 1;
	}

  }
return 0;
}


int
has_label (int x, int y, int w, int set, int fy)
{
  int a;
  int ok;
  int start_in;
  int end_in;
// Find any labels matching on this line over this field
  for (a = 0; a < nfields; a++)
    {
      //printf("%d %d %d (%d %d)\n",x,y,w,fields[a].x,fields[a].y);
      if (screen_convert_fields[a].label == 0)
	continue;

      if (screen_convert_fields[a].y != y)
	continue;

      //
      //         LABEL
      //
      //          [ ]                   /1
      //          [                 ]   /2
      //     [     ]                    /3
      //    [             ]             /4
      //
      //
      ok = 0;
      start_in = 0;
      if (x >= screen_convert_fields[a].x && x <= screen_convert_fields[a].x + strlen (screen_convert_fields[a].label))
	start_in = 1;


      end_in = 0;
      if (x + w >= screen_convert_fields[a].x
	  && x + w <= screen_convert_fields[a].x + strlen (screen_convert_fields[a].label))
	end_in = 1;


      if (end_in || start_in)
	ok = 1;
      if (x <= screen_convert_fields[a].x && x + w >= screen_convert_fields[a].x + strlen (screen_convert_fields[a].label))
	ok = 2;

      if (set && ok && 0 )
	{
	  screen_convert_fields[a].field_start = x;
	  screen_convert_fields[a].y = fy;

	  return ok;
	}
      if (ok)
	return ok;
    }

  return 0;
}

void make_screen (struct_form * f,int scr)
{
  int x, y;
  int a;
  int fno;
  int b;

  if (f->maxcol > 400 || f->maxline > 400)
    {
      fprintf (stderr, "Too wide or too long\n");
      exit (1);
    }
  for (y = 0; y < f->maxline; y++)
    {
      memset (screen[y], ' ', f->maxcol);
      screen[y][f->maxcol + 1] = 0;
    }

  for (a = 0; a < f->metrics.metrics_len; a++)
    {
      int w;
      x = f->metrics.metrics_val[a].x;
      y = f->metrics.metrics_val[a].y;
      w = f->metrics.metrics_val[a].w;

      if (f->metrics.metrics_val[a].scr != scr)
	{
		continue;
	}


      if (f->metrics.metrics_val[a].label[0] == '\n')
	continue;		// Ignore graphics characters-  line drawing

      if (strncmp(f->metrics.metrics_val[a].label ,"nl;",3)==0) {
		continue;
	}


      if (strlen (f->metrics.metrics_val[a].label))
	{
	  strncpy (&screen[y][x], f->metrics.metrics_val[a].label,
		   strlen (f->metrics.metrics_val[a].label));
	}
      else
	{
	  screen[y][x] = 1;
	  screen[y][x + w + 1] = 2;
	}
    }


// We've now got our screen reassembled - now look for any fields which are single spaced delimited...
//
//

  for (y = 0; y < f->maxline; y++)
    {

      		// Convert all ':' to spaces - they'd look rubbish anyway....
      		for (x = 0; x < f->maxcol; x++)
			{
	  			if (screen[y][x] == ':') {
					if (A4GL_isyes(acl_getenv("XMLFORM_REMOVECOLON"))) {
	    					screen[y][x] = ' ';
					}
				}
			}
	

      for (x = 0; x < f->maxcol; x++)
	{
	  int because_of=0;
	  int w;
	  int w2;
	  int fstart = x;
	  if ((screen[y][x] != ' ' ) && screen[y][x] != 1 && screen[y][x] != 2)
	    {
	      for (w = x + 1; w <= f->maxcol; w++)
		{
		  if ((screen[y][w - 1] == ' ' ) && screen[y][w] == 0)
		    {
		      because_of = ' ';
		      break;
		    }		// more than 1 space
		  if ((screen[y][w - 1] == ' ' )  && (screen[y][w] == ' '))
		    {
		      because_of = ' ';
		      break;
		    }		// more than 1 space
		  if (screen[y][w] == 1 || screen[y][w] == 2)
		    {
		      because_of = '[';
		      fstart = w;
		      break;
		    }		// a field
		}

	      if (because_of == ' ')
		{
		  for (w2 = w; w2 < f->maxcol; w2++)
		    {
		      if (screen[y][w2] == ' ' )
			continue;
		      if (screen[y][w2] == 1)
			{
			  fstart = w2;
			  break;
			}
		      break;
		    }
		}
	      new_field (y, x, w - x - 1, because_of, fstart);
	      memset (&screen[y][x], ' ', w - x - 1);
	    }
	}
    }


  for (a = 0; a < f->attributes.attributes_len; a++)
    {
      int mno;
      int ok;
      int w;

      fno = f->attributes.attributes_val[a].field_no;
      if (f->fields.fields_val[fno].metric.metric_len <= 1)
	continue;
      mno = f->fields.fields_val[fno].metric.metric_val[0];

      // We've got an array of these - normally they'd all start at the same 'x' - so lets check
      x = f->metrics.metrics_val[mno].x;
      y = f->metrics.metrics_val[mno].y;
      ok = 1;

      for (b = 1; b < f->fields.fields_val[fno].metric.metric_len; b++)
	{
	  mno = f->fields.fields_val[fno].metric.metric_val[b];
	  if (x != f->metrics.metrics_val[mno].x)
	    {
	      ok = 0;
	      break;
	    }
	  if (y + b != f->metrics.metrics_val[mno].y)
	    {
	      ok = 0;
	      break;
	    }			// Must be contiguous down the page too
	}
      if (ok == 0)
	continue;

      // if we've got to here all ourt fields line up
      //
      mno = f->fields.fields_val[fno].metric.metric_val[0];
      w = f->metrics.metrics_val[mno].w;
      x = f->metrics.metrics_val[mno].x;
      y = f->metrics.metrics_val[mno].y;

      if (has_label (x, y - 1, w, 0, y))
	{
	  //printf("Found 1\n");
	  has_label (x, y - 1, w, 1, y);
	}
      else
	{
	  if (has_label (x, y - 2, w, 0, y))
	    {
	      //printf("Found 2\n");
	      has_label (x, y - 2, w, 1, y);
	    }
	}


    }


}


static char * find_label (int x, int y)
{
  int a;
//fprintf(stderr, "nfields=%d\n",nfields);
  for (a = 0; a < nfields; a++)
    {
	//fprintf(stderr, "%s - %d %d\n",  screen_convert_fields[a].label,screen_convert_fields[a].y, screen_convert_fields[a].field_start );
      if (screen_convert_fields[a].y == y && screen_convert_fields[a].field_start == x)
        {
          return screen_convert_fields[a].label;
        }
    }

return 0;
}

int merge_labels(struct_form *f, int scr) {
	if (screen_convert_fields) {free(screen_convert_fields);  screen_convert_fields=0;}
  	if (nfields) nfields=0;
	make_screen(f,scr);
	return 1;
}






int dump_xml_labels() {
int a;
int printed=0;
for (a=0;a<nfields;a++) {
	
	if (printed) {
		fprintf(ofile,",\n");
	}
	printed++;
	  if (isline (screen_convert_fields[a].label))
	    {
	      fprintf (ofile, "      {\"type\":\"HLine\", \"posY\":\"%ld\",\"posX\":\"%ld\",\"gridWidth\":\"%ld\"}", (long)screen_convert_fields[a].y,
		       (long)screen_convert_fields[a].x, (long)strlen (screen_convert_fields[a].label));
	    }
	  else
	    {
		char guess_align='L';

		if (has_label_ending( screen_convert_fields[a].x+ screen_convert_fields[a].w, screen_convert_fields[a].y)) guess_align='R';

	        fprintf (ofile, "      {\"type\":\"Label\",\"text\":\"%s\",\"posY\":%d,\"posX\":%d,\"gridWidth\":\"%ld\",\"guessAlign\":\"%c\"}",
		       xml_escape (screen_convert_fields[a].label), screen_convert_fields[a].y, screen_convert_fields[a].x,
		       (long)strlen (screen_convert_fields[a].label), guess_align);
	    }
	
}
return printed;
}


void
dump_screen (struct_form * f, int scr, enum e_scrmodes scrmode,char *extra)
{
  int mw = 0;
  int a;
  int mh = 0;
  get_screen_size_dims (f, scr, &mw, &mh);


  switch (scrmode) {
	case SCRMODE_SCREEN:
      		fprintf (ofile, "      {\"type\":\"Screen\",\"width\":%d,\"height\":%d %s, \"items\":[\n", mw, mh,extra);
			break;

	case SCRMODE_GRID:
      		fprintf (ofile, "      {\"type\":\"Grid\",\"width\":%d,\"height\":%d %s, \"items\":[\n", mw, mh,extra);
			break;
    }
  merge_labels(f, scr);
int printed;
  printed=dump_xml_labels();
  //printed=0;
  for (a = 0; a < f->metrics.metrics_len; a++)
    {
	
      if (f->metrics.metrics_val[a].scr != scr)
	continue;

      if (strlen (f->metrics.metrics_val[a].label))
	{
		continue; // Labels get dumped via 'dump_label'
	}
      else
	{
	if (printed) {
		fprintf(ofile,",");
		}
	printed++;
	  // Its a field...
	  print_field (f, a);
	}
    }

   switch(scrmode) {
	case SCRMODE_SCREEN:
      		fprintf (ofile, "]}\n");
		break;
  	case SCRMODE_GRID:
      		fprintf (ofile, "]}\n");
		break;
    }
}





void dump_form_screen(struct_form *f) {
int scr;
int max_scr;

max_scr=getNumberOfScreens(f);
A4GL_assertion(max_scr<0,"No screens");

fprintf(ofile,",\"layout\":[");
for (scr=1; scr<=max_scr;scr++) {
	char *name;
	char buff[200];
	// By default -we stick "Screen #" as the name
	// so we dont want to send this unless it been changed..
	sprintf(buff,"Screen %d", scr-1);
	name=f->snames.snames_val[scr-1].name;

	if (strcmp(name,buff)==0) {
		dump_screen(f,scr,SCRMODE_SCREEN,"");
	} else {
		sprintf(buff,"\"title\":\"%s\"", name);
		dump_screen(f,scr,SCRMODE_SCREEN,buff);
	}
}
fprintf(ofile,"]");
}


static char *FormLayoutAttr_str(struct_form *f, enum FA_ATTRIBUTES_STRING str ) {
int a;
  if (f->layout_attrib==0) return NULL;
  
  for (a = 0; a < f->layout_attrib->str_attribs.str_attribs_len; a++)
    {
      if (f->layout_attrib->str_attribs.str_attribs_val[a].type == str)
        return f->layout_attrib->str_attribs.str_attribs_val[a].value;
    }
  return NULL;
}


void write_json_form(FILE *wofile, char *fname, struct_form *f) {
char *text;
	initialize_xmlpacker();
	ofile=wofile;




        //fprintf(ofile,"<?xml version=\"1.0\" encoding=\"utf-8\"?>\n");
	fprintf(ofile,"{\"name\":\"%s\",\"sqlDbName\":\"%s\",\"width\":%d,\"height\":%d,\"delimiters\":\"%s\",\"encoding\":\"%s\"",fname, f->dbname, f->maxcol, f->maxline, f->delim,f->encoding);
	text=FormLayoutAttr_str(f,FA_S_TEXT);
	if (text) {
		fprintf(ofile,",text=\"%s\"", xml_escape(text));
	}

	fprintf(ofile,"\n");

     int b=0;
     int convert_matrix=0;
     if((f->layout == 0 || f->layout->layout_type == LAYOUT_GRID) && !A4GL_isno(acl_getenv("A4GL_AUTOCONVSCRAR"))){
        for (b=0;b<f->attributes.attributes_len;b++) {
           // We've found our attribute..
           int dim1=0;
           if (isInScreenArray (f, b, &dim1,NULL)) {
              convert_matrix=1;
           break;
           }
        }
     }

     if(convert_matrix) {
        convertMatrix(f);
     }


	if (f->layout==0) {
		// Its a screen not a layout
		dump_form_screen(f);
	} else {
		dump_form_layout(f);
	}
	printRecordView(f);
 	fprintf(ofile,"}\n");
        fclose(ofile);
				
}







static char *
decode_dt (int a, int b)
{
  static char buff1[200];
  static char buff2[200];
  int c;
  if (a == 0)
    {
      if (b == 1)
	return "YEAR";
      return "SECOND";
    }

  if (b == 1)
    {
      c = a >> 4;
      sprintf (buff1, "%x %x (b=%d)", c, a, b);
      switch (c)
	{
	case 1:
	  strcpy (buff1, "YEAR");
	  break;
	case 2:
	  strcpy (buff1, "MONTH");
	  break;
	case 3:
	  strcpy (buff1, "DAY");
	  break;
	case 4:
	  strcpy (buff1, "HOUR");
	  break;
	case 5:
	  strcpy (buff1, "MINUTE");
	  break;
	case 6:
	  strcpy (buff1, "SECOND");
	  break;
	case 7:
	  strcpy (buff1, "FRACTION(1)");
	  break;
	case 8:
	  strcpy (buff1, "FRACTION(2)");
	  break;
	case 9:
	  strcpy (buff1, "FRACTION(3)");
	  break;
	case 10:
	  strcpy (buff1, "FRACTION(4)");
	  break;
	case 11:
	  strcpy (buff1, "FRACTION(5)");
	  break;
	}
      return buff1;
    }
  else
    {
      c = a & 0xf;
      sprintf (buff2, "%x %x (b=%d)", c, a, b);
      switch (c)
	{
	case 1:
	  strcpy (buff2, "YEAR");
	  break;
	case 2:
	  strcpy (buff2, "MONTH");
	  break;
	case 3:
	  strcpy (buff2, "DAY");
	  break;
	case 4:
	  strcpy (buff2, "HOUR");
	  break;
	case 5:
	  strcpy (buff2, "MINUTE");
	  break;
	case 6:
	  strcpy (buff2, "SECOND");
	  break;
	case 7:
	  strcpy (buff2, "FRACTION(1)");
	  break;
	case 8:
	  strcpy (buff2, "FRACTION(2)");
	  break;
	case 9:
	  strcpy (buff2, "FRACTION(3)");
	  break;
	case 10:
	  strcpy (buff2, "FRACTION(4)");
	  break;
	case 11:
	  strcpy (buff2, "FRACTION(5)");
	  break;
	}
      return buff2;
    }
}

static char *
decode_ival_define1 (int n)
{
  static char buff[256];
  int l;

  if (n == 0x602)
    return "YEAR";
  if (n == 0x84a)
    return "DAY";
  if (n == 0xa6d)
    return "HOUR(3)";

  //printf("-->%x (n==0x602)=%d \n",n, n==0x602);

  l = (n >> 8) & 0xf;
  if (l == 6)
    {
      switch ((n >> 4) & 0xf)
	{
	case 1:
	  return "YEAR";
	case 2:
	  return "MONTH";
	case 3:
	  return "DAY";
	case 4:
	  return "HOUR";
	case 5:
	  return "MINUTE";
	case 6:
	  return "SECOND";
	case 7:
	  return "FRACTION(1)";
	case 8:
	  return "FRACTION(2)";
	case 9:
	  return "FRACTION(3)";
	case 10:
	  return "FRACTION(4)";
	case 11:
	  return "FRACTION(5)";
	}
    }
  else
    {
      switch ((n >> 4) & 0xf)
	{
	case 1:
	  sprintf (buff, "YEAR(%d)", l);
	  return buff;
	case 2:
	  sprintf (buff, "MONTH(%d)", l);
	  return buff;
	case 3:
	  sprintf (buff, "DAY(%d)", l);
	  return buff;
	case 4:
	  sprintf (buff, "HOUR(%d)", l);
	  return buff;
	case 5:
	  sprintf (buff, "MINUTE(%d)", l);
	  return buff;
	case 6:
	  sprintf (buff, "SECOND(%d)", l);
	  return buff;

	}

    }
  A4GL_assertion (1, "Unknown CURRENT 9.1");
  return "";
}


static char *
decode_ival_define2 (int n)
{
  if (n == 0x602)
    return "MONTH";
  if (n == 0x84a)
    return "SECOND";
  if (n == 0xa6d)
    return "FRACTION(3)";
  switch (n & 0xf)
    {
    case 1:
      return "YEAR";
    case 2:
      return "MONTH";
    case 3:
      return "DAY";
    case 4:
      return "HOUR";
    case 5:
      return "MINUTE";
    case 6:
      return "SECOND";
    case 7:
      return "FRACTION(1)";
    case 8:
      return "FRACTION(2)";
    case 9:
      return "FRACTION(3)";
    case 10:
      return "FRACTION(4)";
    case 11:
      return "FRACTION(5)";
    }
  A4GL_assertion (1, "Unknown CURRENT 8.1");
  return "";
}



static char * xml_escape (char *s)
{
  static char *buff = 0;
  static int last_len = 0;
  int c;
  int a;
  int l;
  int b;
  int allocated;


  c = 0;


  if (strchr (s, '&'))
    c++;
  if (strchr (s, '<'))
    c++;
  if (strchr (s, '>'))
    c++;
  if (strchr (s, '"'))
    c++;
  if (strchr (s, '\''))
    c++;
  if (strchr (s, '\n'))
    c++;
  if (strchr (s, '\r'))
    c++;


  if (c == 0)
    {
      return s;
    }

  l = strlen (s);
  allocated = (l * 6) + 1;

  if (l > last_len)
    {
      buff = realloc (buff, allocated);
      last_len = l;
    }

  b = 0;
  for (a = 0; a < l; a++)
    {
      if (s[a] == '>')
	{
	  buff[b++] = '&';
	  buff[b++] = 'g';
	  buff[b++] = 't';
	  buff[b++] = ';';
	  continue;
	}
      if (s[a] == '<')
	{
	  buff[b++] = '&';
	  buff[b++] = 'l';
	  buff[b++] = 't';
	  buff[b++] = ';';
	  continue;
	}
      if (s[a] == '&')
	{
	  buff[b++] = '&';
	  buff[b++] = 'a';
	  buff[b++] = 'm';
	  buff[b++] = 'p';
	  buff[b++] = ';';
	  continue;
	}
      if (s[a] == '"')
	{
	  buff[b++] = '&';
	  buff[b++] = 'q';
	  buff[b++] = 'u';
	  buff[b++] = 'o';
	  buff[b++] = 't';
	  buff[b++] = ';';
	  continue;
	}
      if (s[a] == '\'')
	{
	  buff[b++] = '&';
	  buff[b++] = 'a';
	  buff[b++] = 'p';
	  buff[b++] = 'o';
	  buff[b++] = 's';
	  buff[b++] = ';';
	  continue;
	}
      if (s[a] < 31 || s[a] > 126)
	{
	  int z1;
	  char buff2[20];
	  z1 = ((unsigned char) s[a]);
	  sprintf (buff2, "&#x%02X;", z1);
	  for (z1 = 0; z1 < strlen (buff2); z1++)
	    {
	      buff[b++] = buff2[z1];
	    }
	  continue;
	}
      buff[b++] = s[a];
    }
if (b>=allocated) {

//fprintf(stderr,"b=%d allocated=%d l=%d\n", b,allocated,l);
}
  A4GL_assertion (b >= allocated, "XML escape buffer too small");
  buff[b] = 0;
  return buff;
}



static char * get_sql_dtype ( int dtype)
{
  //int a;
  //int cnt;
  //char buff[256];
  static char buff_dtype[256];
  int dtype_sz;

  dtype_sz = dtype >> 16;
  dtype = dtype & 0xffff;
  switch (dtype & DTYPE_MASK)
    {
        case DTYPE_CHAR:
              sprintf (buff_dtype, "CHAR(%d)", dtype_sz);
                    break;
        case DTYPE_NCHAR:
              sprintf (buff_dtype, "NCHAR(%d)", dtype_sz);
                    break;
                        case DTYPE_VCHAR:
                              sprintf (buff_dtype, "VARCHAR(%d)", dtype_sz);
                                    break;
                        case DTYPE_NVCHAR:
                              sprintf (buff_dtype, "NVARCHAR(%d)", dtype_sz);
                                    break;

    case DTYPE_INT:
      sprintf (buff_dtype, "INTEGER");
      break;
    case DTYPE_SMINT:
      sprintf (buff_dtype, "SMALLINT");
      break;
    case DTYPE_DATE:
      sprintf (buff_dtype, "DATE");
      break;
    case DTYPE_TEXT:
      sprintf (buff_dtype, "TEXT");
      break;
    case DTYPE_BYTE:
      sprintf (buff_dtype, "BYTE");
      break;
    case DTYPE_FLOAT:
      sprintf (buff_dtype, "FLOAT");
      break;
    case DTYPE_SMFLOAT:
      sprintf (buff_dtype, "SMALLFLOAT");
      break;
    case DTYPE_SERIAL:
      sprintf (buff_dtype, "SERIAL");
      break;

    case DTYPE_DECIMAL:
      sprintf (buff_dtype, "DECIMAL(%d,%d)", dtype_sz >> 8, dtype_sz & 255);
      break;

    case DTYPE_MONEY:
      sprintf (buff_dtype, "MONEY(%d,%d)", dtype_sz >> 8, dtype_sz & 255);
      break;


    case DTYPE_DTIME:
      sprintf (buff_dtype, "DATETIME %s TO %s", decode_dt (dtype_sz, 1), decode_dt (dtype_sz, 2));
      break;

    case DTYPE_INTERVAL:
      sprintf (buff_dtype, "INTERVAL %s TO %s", decode_ival_define1 (dtype_sz), decode_ival_define2 (dtype_sz));
      break;


    default:
      fprintf (stderr, "Unhandled define in module variable removal... variable dtype : %d (%x)\n", dtype, dtype);
      A4GL_assertion (1, "Unhandled define in module variable removal...");

    }


return buff_dtype;


}



int get_num_labels(void) {
	return nfields;
}


int get_label(int n, char **label, int *x,int *y) {
  *label=screen_convert_fields[n].label;
  *x=screen_convert_fields[n].x ;
  *y=screen_convert_fields[n].y ;
	return 1;
}


void A4GLPacker_A4GL_output_common_header(char* module,char* version) {

}

int A4GLPacker_A4GL_valid_common_header(char* module,char* version) {
        return 1;
}

void convertMatrix(struct_form *f) {
   int scr = 0;
   int grid = 0;
   int table = 0;
   int dim1=0;


   int a;
   for (a = 0; a < f->metrics.metrics_len; a++) {
      int attr_no;
      if (f->metrics.metrics_val[a].scr != 1) continue;
      attr_no=get_attrno_for_metric(f,a);

      if(!isInScreenArray (f, attr_no, &dim1,NULL)) {
         table=0; //we are not in table (anymore)

         if(!grid){
            scr++;
            grid = 1;

            if(f->layout == 0 || f->layout->layout_type == LAYOUT_GRID){
               struct s_layout *layout;
               layout=malloc(sizeof(struct s_layout));
               layout->layout_type = LAYOUT_VBOX;
		layout->id="";
               layout->children.children_len = 0;
               layout->attrib = 0;
               layout->screen_no = 0;
               if (layout->children.children_len==0) {
                  layout->children.children_val=NULL;
               }

               f->layout = layout;
            }

            struct s_layout *grid_layout;
            grid_layout=malloc(sizeof(struct s_layout));
            grid_layout->layout_type = LAYOUT_GRID;
		grid_layout->id="";
            grid_layout->attrib = 0;
            grid_layout->screen_no = scr;
            grid_layout->children.children_len = 0;

            f->layout->children.children_len++;
            f->layout->children.children_val=realloc(f->layout->children.children_val, sizeof(struct s_layout *)*f->layout->children.children_len);
            f->layout->children.children_val[f->layout->children.children_len-1]=grid_layout;
         }
      }
      else{
         grid = 0;

         if(!table){
            scr++;
            table = 1;

            if(f->layout == 0){
               struct s_layout *layout;
               layout=malloc(sizeof(struct s_layout));
               layout->layout_type = LAYOUT_VBOX;
		layout->id="";
               layout->children.children_len = 0;
               layout->attrib = 0;
               layout->screen_no = 0;
               if (layout->children.children_len==0) {
                  layout->children.children_val=NULL;
               }

               f->layout = layout;
            }

            struct s_layout *table_layout;
            table_layout=malloc(sizeof(struct s_layout));
            table_layout->layout_type = LAYOUT_TABLE;
		table_layout->id="";
            table_layout->attrib = 0;
            table_layout->screen_no = scr;
            table_layout->children.children_len = 0;

            f->layout->children.children_len++;
            f->layout->children.children_val=realloc(f->layout->children.children_val, sizeof(struct s_layout *)*f->layout->children.children_len);
            f->layout->children.children_val[f->layout->children.children_len-1]=table_layout;
         }
      }
      f->metrics.metrics_val[a].scr = scr;
   }

}

static int isCharType(int n) {
   switch (n&DTYPE_MASK) { 
         case DTYPE_CHAR:
         case DTYPE_VCHAR:
         case DTYPE_NCHAR:
         case DTYPE_NVCHAR:
               return 1;
   }
   return 0;
}



static char lastKey[20000];
static int objLevel=0;
static int my_callback(void *userdata, int type, const char *data, uint32_t length) {
struct_form *frm=(struct_form*)userdata;

  FILE *output = stdout; //(userdata) ? userdata : stdout;
        switch (type) {
        case JSON_OBJECT_BEGIN:
		objLevel++;
		break;

        case JSON_ARRAY_BEGIN:
                fprintf(output, "entering %s\r\n", (type == JSON_ARRAY_BEGIN) ? "array" : "object");
                break;

        case JSON_OBJECT_END:
		objLevel--;
		break;

        case JSON_ARRAY_END:
                fprintf(output, "leaving %s\r\n", (type == JSON_ARRAY_END) ? "array" : "object");
                break;
        case JSON_KEY:
      		strcpy (lastKey, data);
	        fprintf(output, "key %*s\r\n", length, data);
                break;

        case JSON_STRING:
        case JSON_INT:
        case JSON_FLOAT:
		if (strcmp(lastKey,"sqlDbName")==0) {
			frm->dbname=strdup(data);
			break;
		}
                fprintf(output, "value %*s\r\n", length, data);
                break;
        case JSON_NULL:
                fprintf(output, "constant null\r\n"); break;
        case JSON_TRUE:
                fprintf(output, "constant true\r\n"); break;
        case JSON_FALSE:
                fprintf(output, "constant false\r\n"); break;
        }
return 0;
}


int A4GLPacker_A4GL_unpack_all (char *name, void *s, char *filename) {
json_parser parser;

if (json_parser_init(&parser, NULL, my_callback, s)) {
        fprintf(stderr, "something wrong happened during init\n");
}


((struct_form*)s)->fcompile_version = FCOMILE_XDR_VERSION;
((struct_form*)s)->delim = "[]|";
FILE *f;
static char *buff=0;

if (buff) {
	acl_free(buff);
}

f=fopen(filename,"r");

if (!f) {
	char fname[20000];
	strcpy(fname,filename);
	if (strchr(fname,'.')) {
		char *ptr=strrchr(fname,'.');
		*ptr=0;
		strcat(fname,".json");
		f=fopen(fname,"r");
	}
}

if (!f) {
	return 0;
}
int ret;
 fseek (f, 0, SEEK_END);
int l;
      l = ftell (f);
      rewind (f);
      buff = malloc (l + 1);
      fread (buff, l, 1, f);
      buff[l] = 0;
      fclose (f);

while (1) {
	ret = json_parser_string (&parser, buff, strlen (buff), NULL);
  if (ret)
        {
	printf("Error\n");
	break;
	}
	if (json_parser_is_done (&parser))
        	break;
}

	return 1;
}
