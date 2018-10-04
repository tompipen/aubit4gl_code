#include <stdarg.h>
#include <stdio.h>
#include "a4gl_libaubit4gl.h"
#include "comms.h"
#include "uilib.h"
#include "pipe.h"
#include "uilib/xml/attr.h"
#include "a4gl_API_ui_lib.h"

static char reading_form_id[200];

static int generate_json_forms=1;
static int last_h=1;
static int last_w=1;


static void
A4GL_JSON_opening_form_xml (char *formname, char *formfile, char *fbuff)
{
  //int a;
  char *buff;
char buff2[2000];
int len;
int l;
char *ptr;

  int cnt;
  send_to_ui ("         {\"Name\":\"%s\",\"File\":\"%s\", \"Data\":[", formname, formfile);

  cnt=0;
  len=strlen(fbuff);
  A4GL_base64_encode(fbuff,len,&buff);
  l=strlen(buff);
  ptr=buff;
#define CHUNKSIZE 80
  
  while (cnt<l) {
	strncpy(buff2,ptr,CHUNKSIZE);
	buff2[CHUNKSIZE]=0;
  	send_to_ui ("            \"%s\",", buff2);
	cnt+=CHUNKSIZE;
	ptr+=CHUNKSIZE;
  }
free(buff);
/*
  for (a = 0; a < strlen (fbuff); a += 256)
    {
      char b[300];
      strncpy (b, &fbuff[a], 256);
      b[256] = 0;
      send_to_ui ("%s", uilib_xml_escape (b));
    }
*/
  send_to_ui ("null]}");
}

static int
A4GL_JSON_opening_form (char *formfile, char *formname,int append_xml)
{
  FILE *f;
  char *fbuff;
  char buff[2000];
  char buff_formname[2000];
  strcpy (buff, formfile);
  A4GL_trim (buff);
  strcpy (buff_formname, formname);
  A4GL_trim (buff_formname);

  last_h=1; last_w=1;
  if (append_xml) {
  	strcat (buff, ".xml");
  }
  f = A4GL_open_file_dbpath (buff);

  if (f)
    {
      long l;
      fseek (f, 0, SEEK_END);
      l = ftell (f);
      rewind (f);
      fbuff = malloc (l + 1);
      fread (fbuff, l, 1, f);
      fbuff[l] = 0;
      fclose (f);
      A4GL_JSON_opening_form_xml (buff_formname, formfile, fbuff);
      free (fbuff);
      return 1;
    }
  else
    {
      //printf ("Unable to open file \"%s\"\n", buff);
      return 0;
    }
}

static char *
A4GL_decode_str_fprop (struct_scr_field * fprop, int type)
{
  int b;
  if (fprop == 0)
    return 0;
  if (fprop->str_attribs.str_attribs_val == 0)
    return 0;
  for (b = 0; b < fprop->str_attribs.str_attribs_len; b++)
    {
      if (fprop->str_attribs.str_attribs_val[b].type == type)
        {
          return fprop->str_attribs.str_attribs_val[b].value;
        }
    }
  return "";
}


static void dump_form_labels_json(void) {
int a;
int nfields;
nfields=get_num_labels();
for (a=0;a<nfields;a++) {
	int x;
	int y;
	char *label;
	get_label(a,&label,&x,&y);
  send_to_ui ("      { \"ROW\":%d,\"COLUMN\":%d,\"Data\":\"%s\"},", 
			y,
			x, uilib_xml_escape (char_encode(label)));
}

}

static void
A4GL_make_field_json (int frow, int fcol, int rows, int cols, char *widget,
		 char *config, char *inc, void *id, char *tab_and_col, char *action, int attr_no)
{
  	send_to_ui ("      {\"ROW\":%d, \"COLUMN\":%d, \"ROWS\":%d, \"COLS\":%d, \"WIDGET\":\"%s\"",frow, fcol, rows, cols, uilib_xml_escape (char_encode(widget)));
 	send_to_ui("           , \"CONFIG\":\"%s\"",uilib_xml_escape (char_encode(config)));
	send_to_ui("           , \"INC\":\"%s\",\"ID\":%d",uilib_xml_escape (char_encode(inc)), (long) id);
	send_to_ui("           , \"TABCOL\":\"%s\"",uilib_xml_escape (char_encode(tab_and_col)));
	send_to_ui("           , \"ACTION\":\"%s\",\"ATTRIBUTE_NO\":%d},", uilib_xml_escape (char_encode(action)), attr_no);
}


int read_metrics_json (struct s_form_dets *formdets)
{
  int metric_no, n;
  char delims[3][2];
  char *widget;
  char *config;
  char *include;
  struct struct_scr_field *fprop = 0;
  char *action;
  int generated_xml_form=0;



  if (generate_json_forms) {
		FILE *f;
		char buff[200];
		tmpnam(buff);
		//fprintf(stderr,"Using JSON form... %s", buff);
		//strcpy(buff,"tmp.xml");
		f=fopen(buff,"w");
		if (f) {
			write_json_form(f,reading_form_id,formdets->fileform) ;
	  		if (A4GL_JSON_opening_form (buff, reading_form_id,0)) {
				generated_xml_form=1;
			}

		}
		unlink(buff);
  } 

  if (generated_xml_form) {
		//fprintf(stderr,"Used JSON form...\n");
	return 1;
  }
//fprintf(stderr,"not using XML form...\n");
	
  delims[0][0] = formdets->fileform->delim[0];
  delims[1][0] = formdets->fileform->delim[1];
  delims[2][0] = formdets->fileform->delim[2];
  delims[0][1] = 0;
  delims[1][1] = 0;
  delims[2][1] = 0;
  n = formdets->fileform->metrics.metrics_len;
  A4GL_debug ("metrics len=%d", n);

  send_to_ui ("{ \"MAXCOL\":%d,\"MAXLINE\":%d, \"Screen\":[ ", formdets->fileform->maxcol, formdets->fileform->maxline);

  merge_labels(formdets->fileform,1); // using 1 because we want to dump Screen 1

  dump_form_labels_json();

  for (metric_no = 0; metric_no < n; metric_no++)
    {


      formdets->fileform->metrics.metrics_val[metric_no].pos_code = 0;
      A4GL_debug ("checking label %s\n", formdets->fileform->metrics.metrics_val[metric_no].label);

      if (strlen (formdets->fileform->metrics.metrics_val[metric_no].label) != 0)
	{
		continue;
	  	//A4GL_make_label (formdets->fileform->metrics.metrics_val[metric_no].  y, formdets->fileform->metrics.metrics_val[metric_no].  x, formdets->fileform->metrics.metrics_val[metric_no].label);
	}
      else
	{
	  int attr_no;
	  attr_no = A4GL_find_attrib_from_metric (formdets->fileform, metric_no);
	  if (attr_no == -1)
	    continue;
	  widget = 0;
	  config = 0;
	  include = 0;
	  action = 0;
	  if (attr_no >= 0)
	    {
	      fprop = &formdets->fileform->attributes.attributes_val[attr_no];
	      A4GL_debug ("attr_no=%d fprop=%p", attr_no, fprop);

	      widget = A4GL_decode_str_fprop (fprop, FA_S_WIDGET);
	      config = A4GL_decode_str_fprop (fprop, FA_S_CONFIG);
	      include = 0;
	      if (A4GL_has_str_attribute (fprop, FA_S_INCLUDE))
		{
		  include = A4GL_get_str_attribute (fprop, FA_S_INCLUDE);
		}
	      else
		{
		  include = 0;
		}
	      action = 0;
	      if (A4GL_has_str_attribute (fprop, FA_S_ACTION))
		{
		  action = A4GL_get_str_attribute (fprop, FA_S_ACTION);
		}
	      else
		{
		  action = 0;
		}
	    }
	  else
	    {
	      widget = 0;
	      config = 0;
	      include = 0;
	      action = 0;
	    }

	  if (widget == 0)
	    widget = "";
	  if (config == 0)
	    config = "";
	  if (include == 0)
	    include = "";
	  if (action == 0)
	    action = "";



	  A4GL_make_field_json (formdets->fileform->metrics.
			   metrics_val[metric_no].y,
			   formdets->fileform->metrics.
			   metrics_val[metric_no].x,
			   formdets->fileform->metrics.
			   metrics_val[metric_no].h,
			   formdets->fileform->metrics.
			   metrics_val[metric_no].w, widget,
			   config, include, fprop, make_tab_and_col (fprop->tabname, fprop->colname), action, attr_no);

	}
    }

  send_to_ui ("null], \"ScreenRecords\":[");
  // We also need to send the screen records as these might be used....
  for (n = 0; n < formdets->fileform->records.records_len; n++)
    {
      int attr;
      send_to_ui ("{\"NAME\":\"%s\", \"SIZE\":%d, \"Attributes\":[", formdets->fileform->records.records_val[n].name,
		  formdets->fileform->records.records_val[n].dim);
      for (attr = 0; attr < formdets->fileform->records.records_val[n].attribs.attribs_len; attr++)
	{
	  int attr_no;
	  attr_no = formdets->fileform->records.records_val[n].attribs.attribs_val[attr];
	  fprop = &formdets->fileform->attributes.attributes_val[attr_no];
	  send_to_ui ("{ \"ATTRIBUTE_NO\":%d, \"NAME\":\"%s\"},",
		      formdets->fileform->records.records_val[n].attribs.attribs_val[attr], fprop->colname);
	}
      send_to_ui ("null]}");
    }
  send_to_ui ("],\"Attributes\":[");
  for (n = 0; n < formdets->fileform->attributes.attributes_len; n++)
    {
      int b;
      struct struct_scr_field *f;
      f = &formdets->fileform->attributes.attributes_val[n];
      send_to_ui ("{ \"ATTRIBUTE_NO\":%d,\"DATATYPE\":%d,\"DATATYPE_SIZE\":%d, \"DYNAMIC\":%d, \"REVERSE\":%d",
		  n, f->datatype, f->dtype_size, f->dynamic, f->do_reverse);
      for (b = 0; b < f->str_attribs.str_attribs_len; b++)
	{
	  switch (f->str_attribs.str_attribs_val[b].type)
	    {
	    case FA_S_INCLUDE:
	    case FA_S_WIDGET:
	    case FA_S_CONFIG:
	    case FA_S_ACTION:
	      break;

	    case FA_S_PICTURE:
	      send_to_ui (",\"PICTURE\":\"%s\"", uilib_xml_escape (char_encode(f->str_attribs.str_attribs_val[b].value)));
	      break;
	    case FA_S_FORMAT:
	      send_to_ui (",\"FORMAT\":\"%s\"", uilib_xml_escape (char_encode(f->str_attribs.str_attribs_val[b].value)));
	      break;
	    case FA_S_DEFAULT:
	      send_to_ui (",\"DEFAULT\":\"%s\"", uilib_xml_escape (char_encode(f->str_attribs.str_attribs_val[b].value)));
	      break;
	    case FA_S_PROGRAM:
	      send_to_ui (",\"PROGRAM\":\"%s\"", uilib_xml_escape (char_encode(f->str_attribs.str_attribs_val[b].value)));
	      break;
	    case FA_S_COMMENTS:
	      send_to_ui (",\"COMMENTS\":\"%s\"", uilib_xml_escape (char_encode(f->str_attribs.str_attribs_val[b].value)));
	      break;
	    case FA_S_CLASS:
	      send_to_ui (",\"CLASS\":\"%s\"", uilib_xml_escape (char_encode(f->str_attribs.str_attribs_val[b].value)));
	      break;
	default: 
		break;

	    }
	}

      for (b = 0; b < f->bool_attribs.bool_attribs_len; b++)
	{
	  switch (f->bool_attribs.bool_attribs_val[b])
	    {
	    case FA_B_AUTONEXT:
	      send_to_ui (",\"AUTONEXT\":true");
	      break;
	    case FA_B_REVERSE:
	      send_to_ui (",\"REVERSE\":true");
	      break;
	    case FA_B_INVISIBLE:
	      send_to_ui (",\"INVISIBLE\":true");
	      break;
	    case FA_B_NOENTRY:
	      send_to_ui (",\"NOENTRY\":true");
	      break;
	    case FA_B_VERIFY:
	      send_to_ui (",\"VERIFY\":true");
	      break;
	    case FA_B_WORDWRAP:
	      send_to_ui (",\"WORDWRAP\":true");
	      break;
	    case FA_B_COMPRESS:
	      send_to_ui (",\"COMPRESS\":true");
	      break;
	    case FA_B_UPSHIFT:
	      send_to_ui (",\"UPSHIFT\":true");
	      break;
	    case FA_B_DOWNSHIFT:
	      send_to_ui (",\"DOWNSHIFT\":true");
	      break;
	    case FA_B_REQUIRED:
	      send_to_ui (",\"REQUIRED\":true");
	      break;
	    case FA_B_NOUPDATE:
	      send_to_ui (",\"NOUPDATE\":true");
	      break;
	    case FA_B_QUERYCLEAR:
	      send_to_ui (",\"QUERYCLEAR\":true");
	      break;
	    case FA_B_ZEROFILL:
	      send_to_ui (",\"ZEROFILL\":true");
	      break;
	    case FA_B_RIGHT:
	      send_to_ui (",\"RIGHT\":true");
	      break;

	case FA_B_HIDDEN:
		send_to_ui (",\"HIDDEN\":true");
		break;

	case FA_B_SCROLL:
		send_to_ui (",\"SCROLL\":true");
		break;

	case FA_B_WANTTABS:
		send_to_ui (",\"WANTTABS\":true");
		break;

	case FA_B_WANTNORETURNS:
		send_to_ui (",\"WANTNORETURNS\":true");
		break;

	case FA_B_FONTPITCHFIXED:
		send_to_ui (",\"FONTPITCHFIXED\":true");
		break;

	case FA_B_FONTPITCHVARIABLE:
		send_to_ui (",\"FONTPITCHVARIABLE\":true");
		break;

	case FA_B_AUTOSCALE:
		send_to_ui (",\"AUTOSCALE\":true");
		break;

	case FA_B_STRETCH_BOTH:
		send_to_ui (",\"STRETCH_BOTH\":true");
		break;

	case FA_B_STRETCH_Y:
		send_to_ui (",\"STRETCH_Y\":true");
		break;

	case FA_B_SCROLLBARS_BOTH:
		send_to_ui (",\"SCROLLBARS\":\"BOTH\"");
		break;

	case FA_B_SCROLLBARS_VERTICAL:
		send_to_ui (",\"SCROLLBARS\":\"VERTICAL\"");
		break;

	case FA_B_SCROLLBARS_HORIZONAL:
		send_to_ui (",\"SCROLLBARS\":\"HORIZONAL\"");
		break;

	default:
		break;

	    }
	}
      send_to_ui ("},");
    }
  send_to_ui ("null]}");


  return 1;
}
