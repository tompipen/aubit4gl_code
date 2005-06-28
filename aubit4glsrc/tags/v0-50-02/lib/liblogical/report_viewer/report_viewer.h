#include <stdio.h>
#include <gtk/gtk.h>
#include <string.h>
#include "../common/a4gl_lle.h"

void setup_entry(int b,int e,GtkWidget *evt,GtkWidget *lab);
void set_block_clicked(int rb);
int fake_clicked(int rb,int entry) ;
void setup_block(int b,GtkWidget *evt,GtkWidget *lab);
void set_clicked(int rb,int entry);
