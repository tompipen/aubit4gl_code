#include <stdio.h>
//#include "menu_x.h"
#include "../../lib/libincl/menuxw.h"

#ifdef __CYGWIN__
	#include <rpc/rpc.h>
#endif


//here only to satisfy libMENU_XDR, when linked with mdecompile executable.
//Should be removed once libMENU_ is dlopen() enabled:
char *outputfilename;


main(int argc,char *argv[]) {
struct menu_list the_menus;
FILE *f;
XDR xdrp;
int a;

	if (argc!=2) {
		printf("Usage %s filename\n",argv[0]);
		exit(0);
	}

	f=fopen(argv[1],"rb");

	if (f==0) {
		printf("Unable to open file %s\n",argv[1]);
		exit(2);
	}

	memset(&the_menus,0,sizeof(menu_list));

	xdrstdio_create(&xdrp,f,XDR_DECODE);


	a=xdr_menu_list(&xdrp,&the_menus);
	if (!a) {
		printf("Bad format\n");
	} else {
		dump_menu(&the_menus);
	}
}


dump_menu(menu_list *m) {
	int a;
	menu *mm;
	printf("%d menus & submenus\n",m->menus.menus_len);
	for (a=0;a<m->menus.menus_len;a++) {
		mm=&m->menus.menus_val[a];
		printf("Menu : %s\n",mm->id);
		dump_options(mm);
	}
}

dump_options(menu *mm) {
int a;
menu_option_item *o;
for (a=0;a<mm->options.options_len;a++) {
	o=&mm->options.options_val[a];
	printf("   %s (%s) ",o->id,o->caption);
	if (strlen(o->submenu_id)!=0) {
		printf(" [Submenu ->%s] ",o->submenu_id);
	}
	printf(" Keys=%s Check=%d Attr=%x Color=%d\n",o->key_list,
		o->checked,o->align,o->color);
	printf(" Image='%s'\n",o->image);
}
}

