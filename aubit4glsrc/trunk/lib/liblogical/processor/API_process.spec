LIBRARY LOGREPPROC
VARIABLE LOGREP
HEADER_FILE "process.h"

RP_default_file void* report char* errbuff -> int
RP_load_file void* report FILE* fin -> int
RP_process_report void* report char* buff -> int

