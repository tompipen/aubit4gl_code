struct call_funcs system_funcs[]={
	{ &printf,				"printf",			0}, 
	{ &exit,				"exit",				"44"}, 
	{0,0,0} 
};




void init_calls(int argc,char *argv[]) {
// Does nothing ...
}


void *resolve_externs (char *name) {
	return (void *) -1;
}
