#

code
#include <stdio.h>
#include <gtk/gtk.h>
#include <glade/glade.h>

#define WINCODE 'w'
#define INTEGERCODE 'f'
#define IDCODE 'i'

/* This is the filename of the file currently being edited, in on-disk
   encoding (which may be UTF-8 or the locale's encoding). */
static gchar *current_filename = NULL;

/* This flag is set to TRUE if the file has been changed. We don't actually
   use it here, but the program could be extended to prompt to save changes. */
static gboolean file_changed = FALSE;
#define BUFFER_SIZE 8192

endcode


define mv_ok integer



function textview_line_count_get(lv_form,lv_field)
define lv_form INTEGER
define lv_field INTEGER
define lv_widget INTEGER
define lv_cnt integer
let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return 0 end if

return lv_cnt
end function




function textview_line_from_char_get(lv_form,lv_field,lv_char_index)
define lv_form INTEGER
define lv_field INTEGER
define lv_char_index integer
define lv_widget INTEGER
define lv_cnt integer
let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return 0 end if
return lv_cnt
end function




function textview_line_length_get(lv_form,lv_field,lv_line)
define lv_form INTEGER
define lv_field INTEGER
define lv_line integer
define lv_widget INTEGER
define lv_cnt integer
let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return 0 end if
return lv_cnt
end function




function textview_line_start_get(lv_form,lv_field,lv_line)
define lv_form INTEGER
define lv_field INTEGER
define lv_line integer
define lv_widget INTEGER
define lv_cnt integer
let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return 0 end if
return lv_cnt
end function


function textview_line_text_get(lv_form,lv_field,lv_line)
define lv_form INTEGER
define lv_field INTEGER
define lv_line integer
define lv_widget INTEGER
let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return 0 end if
return ""
end function



function textview_max_chars_set(lv_form,lv_field,lv_chars)
define lv_form INTEGER
define lv_field INTEGER
define lv_widget INTEGER
define lv_chars integer
let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return  end if
code
gtk_entry_set_max_length(lv_widget,lv_chars);
endcode
return 
end function

function textview_max_chars_get(lv_form,lv_field)
define lv_form INTEGER
define lv_field INTEGER
define lv_widget INTEGER
define lv_chars integer
let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return 0 end if
code
lv_chars=gtk_entry_get_max_length(lv_widget);
endcode
return lv_chars
end function





function textview_selected_text_get(lv_form,lv_field)
define lv_form INTEGER
define lv_field INTEGER
define lv_widget INTEGER
define lv_start,lv_length INTEGER

let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return "" end if
return  ""
end function


function textview_selected_text_update(lv_form,lv_field,lv_replace_with)
define lv_form INTEGER
define lv_field INTEGER
define lv_widget INTEGER
define lv_replace_with CHAR(255)
define lv_start,lv_length INTEGER
let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return end if

call textview_selection_get(lv_form,lv_field) returning lv_start,lv_length
call textview_selection_delete(lv_form,lv_field)
code
A4GL_trim(lv_replace_with);
gtk_editable_insert_text(lv_widget,lv_replace_with,lv_length,lv_start);
endcode
return 
end function


function textview_selection_delete(lv_form,lv_field)
define lv_form INTEGER
define lv_field INTEGER
define lv_widget INTEGER

let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return  end if

code
{
  GtkTextBuffer *buffer;
  buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (lv_widget));
  gtk_text_buffer_delete_selection (buffer, TRUE, TRUE);
}
endcode

return 
end function


function textview_selection_get(lv_form,lv_field)
define lv_form INTEGER
define lv_field INTEGER
define lv_widget INTEGER
define lv_start,lv_length INTEGER
let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return 0,0  end if
code
gtk_editable_get_selection_bounds(lv_widget,&lv_start,&lv_length);
if (lv_start==0) lv_length=0;
else {lv_length=lv_length-lv_start;}
endcode
return lv_start,lv_length
end function


function textview_selection_set(lv_form,lv_field,lv_start,lv_length)
define lv_form INTEGER
define lv_field INTEGER
define lv_widget INTEGER
define lv_start,lv_length INTEGER
let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return  end if
code
gtk_editable_select_region(lv_widget,lv_start,lv_start+lv_length);
endcode
return
end function



function textview_selection_cut(lv_form,lv_field)
define lv_form INTEGER
define lv_field INTEGER
define lv_widget INTEGER
let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return  end if
code
  g_signal_emit_by_name (G_OBJECT (lv_widget), "cut_clipboard", NULL);
endcode
return
end function

function textview_selection_copy(lv_form,lv_field)
define lv_form INTEGER
define lv_field INTEGER
define lv_widget INTEGER
let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return  end if
code
  g_signal_emit_by_name (G_OBJECT (lv_widget), "copy_clipboard", NULL);
endcode
return
end function


function textview_selection_paste(lv_form,lv_field)
define lv_form INTEGER
define lv_field INTEGER
define lv_widget INTEGER
let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return  end if
code
  g_signal_emit_by_name (G_OBJECT (lv_widget), "paste_clipboard", NULL);
endcode
return
end function



function textview_selection_clear(lv_form,lv_field)
define lv_form INTEGER
define lv_field INTEGER
call textview_selection_delete(lv_form,lv_field)
end function

function textview_text_get(lv_form,lv_field)
define lv_form INTEGER
define lv_field INTEGER
define lv_widget INTEGER
let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return ""  end if
code
{
  GtkTextBuffer *buffer;
  gchar *data;
  GtkTextIter start, end;
  buffer=gtk_text_view_get_buffer (GTK_TEXT_VIEW (lv_widget));
  gtk_text_buffer_get_bounds (buffer, &start, &end);
  data = gtk_text_buffer_get_text (buffer, &start, &end, TRUE);
  A4GL_push_char(data);
 A4GLSTK_popFunction();
return 1;
}
endcode
return ""
end function


# if reset is 1 then it'll reset the current_filename - which is actually of very limited use...
# and needs moving into the get/set data for the object.....
function textview_new_file(lv_form,lv_field,lv_reset)
define lv_form INTEGER
define lv_field INTEGER
define lv_widget INTEGER
define lv_reset integer
let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return   end if
code
{
	new_file(lv_widget,lv_reset);
}
endcode
return 
end function

function textview_open_file(lv_form,lv_field,lv_file)
define lv_form INTEGER
define lv_field INTEGER
define lv_file CHAR(255)
define lv_widget INTEGER
let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return ""  end if
code
{
	A4GL_trim(lv_file);
	real_open_file(lv_widget,lv_file);
}
endcode
return mv_ok
end function





function textview_save_file(lv_form,lv_field,lv_file)
define lv_form INTEGER
define lv_field INTEGER
define lv_file CHAR(255)
define lv_widget INTEGER
let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return ""  end if
code
{
	A4GL_trim(lv_file);
	real_save_file(lv_widget,lv_file);
}
endcode
return mv_ok
end function




code

static void
new_file (GtkWidget *text,int reset)
{
  GtkTextBuffer *buffer;
  GtkTextIter start, end;

  buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (text));
  gtk_text_buffer_get_bounds (buffer, &start, &end);
  gtk_text_buffer_delete (buffer, &start, &end);


  if (reset) {
  	g_free (current_filename);
  	current_filename = NULL;
  	file_changed = FALSE;
	}
}



static void
real_open_file (GtkWidget *text, const gchar *filename)
{
  GtkTextBuffer *text_buffer;
  GtkTextIter start, end;
  FILE *fp;
  gchar buffer[BUFFER_SIZE];
  gint bytes_read;
  mv_ok=0;

  text_buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (text));
  gtk_text_buffer_get_bounds (text_buffer, &start, &end);
  gtk_text_buffer_delete (text_buffer, &start, &end);
  g_free (current_filename);
  current_filename = NULL;
  file_changed = FALSE;

  fp = fopen (filename, "r");
  if (fp == NULL)
    {
      return;
    }

  for (;;)
    {
      bytes_read = fread (buffer, sizeof (gchar), BUFFER_SIZE, fp);

      if (bytes_read > 0)
        {
          gtk_text_buffer_get_end_iter (text_buffer, &end);
          gtk_text_buffer_insert (text_buffer, &end, buffer, bytes_read);
        }

      if (bytes_read != BUFFER_SIZE && (feof (fp) || ferror (fp)))
        break;
    }

  /* If there is an error while loading, we reset everything to a good state.
   */
  if (ferror (fp))
    {
      fclose (fp);
      gtk_text_buffer_get_bounds (text_buffer, &start, &end);
      gtk_text_buffer_delete (text_buffer, &start, &end);
      return;
    }

  fclose (fp);

  current_filename = g_strdup (filename);
  mv_ok=1;
}



static void
real_save_file (GtkWidget *text, const gchar *filename)
{
  GtkTextBuffer *text_buffer;
  GtkTextIter start, end;
  gchar *data;
  FILE *fp;
  gint bytes_written, len;
  mv_ok=0;

  if (current_filename == NULL || strcmp (current_filename, filename))
    {
      g_free (current_filename);
      current_filename = g_strdup (filename);
    }

  text_buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (text));

  gtk_text_buffer_get_bounds (text_buffer, &start, &end);
  data = gtk_text_buffer_get_text (text_buffer, &start, &end, TRUE);

  fp = fopen (filename, "w");
  if (fp == NULL)
    {
      g_free (data);
      return;
    }

  len = strlen (data);
  bytes_written = fwrite (data, sizeof (gchar), len, fp);
  fclose (fp);

  g_free (data);
  if (len != bytes_written)
    {
      return;
    }

  file_changed = FALSE;
  mv_ok=1;
}



endcode
