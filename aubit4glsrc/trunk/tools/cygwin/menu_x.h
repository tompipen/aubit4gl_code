#ifndef XDRFILE
#define XDRFILE
#define bool_t int

struct menu_option_item {
	char *id;
	char *caption;
	char *key_list;
	char *image;
	int checked;
	int align;
	int color;
	char *submenu_id;
};
typedef struct menu_option_item menu_option_item;
bool_t xdr_menu_option_item();


struct menu {
	char *id;
	struct {
		unsigned int options_len;
		menu_option_item *options_val;
	} options;
};
typedef struct menu menu;
bool_t xdr_menu();


struct menu_list {
	struct {
		unsigned int menus_len;
		menu *menus_val;
	} menus;
};
typedef struct menu_list menu_list;
bool_t xdr_menu_list();

#endif

