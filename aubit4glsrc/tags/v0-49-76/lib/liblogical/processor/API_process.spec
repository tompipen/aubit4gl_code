LIBRARY LOGREPPROC
VARIABLE LOGREP
HEADER_FILE "process.h"

RP_default_file void* report char* errbuff void* rbx int rbs -> int
RP_load_file void* report FILE* fin -> int
RP_process_report void* report char* buff void* rbx int rbs -> int

