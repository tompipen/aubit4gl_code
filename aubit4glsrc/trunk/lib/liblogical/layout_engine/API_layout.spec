LIBRARY LOGREP
VARIABLE LOGREP
#include "API_layout.h"

LR_default_file void* report void* rbx int rbs -> void
LR_preview_file void* report -> void
LR_show_layout_rest void* report void* vbox void* rbx int rbs -> void
LR_setup_entry void* report int b int e void* evt void* label -> void
LR_setup_block void* report int b void* evt void* label -> void
LR_save_file void* report FILE* fout void* rbx int rbs -> int
LR_load_file void* report FILE* fin void* rbx int rbs -> int
LR_process_file void* report FILE* fout FILE* filter -> int
