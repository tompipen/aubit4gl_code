#include "convertsql.h"

int
main (int argc, char *argv[])
{
  if (argc != 3 )
  {
      printf("Usage:\n   %s source-sql-dialect target-sql-dialect\n",
              argv[0]);
      exit(1);
  }
  exit( process_stdin(argv[1],argv[2]) );
}

