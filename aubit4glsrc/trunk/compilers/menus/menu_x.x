
struct menu_option_item {
	string id<>;
	string caption<>;
	string key_list<>;
	string image<>;
	int checked;
	int align;
	int color;
	string submenu_id<>;
};

struct menu {
	string id<>;
	menu_option_item options<>;
};


struct menu_list {
	menu menus<>;
};




