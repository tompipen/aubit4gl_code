LIBRARY LOGREP
VARIABLE LOGREP

LR_default_file -> void
LR_preview_file -> void
LR_show_layout_rest void* vbox -> void
LR_setup_entry int b int e void* evt void* label -> void
LR_setup_block int b void* evt void* label -> void
LR_save_file FILE* fout -> int
LR_load_file FILE* fin -> int
LR_process_file FILE* fout FILE* filter void* report -> int
