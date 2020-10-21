/*
* David Kvilora <datokviloria@gmail.com>
*/
#include <stdio.h>
#include "colors.h"

void kvilo_create_col(char *config_path, char *config_file) {

  char *col[sizeof(char*) * 2];
  snprintf(col, sizeof(col), "%s%s", config_path, config_file);
  
  FILE *fp = fopen(col, "w");
  if (fp == NULL) {
    create_error(1, "SYSError: While Createing collection ...\n");
    exit(0);
  }

  printf("\n [+] Collection %s[%s]%s generated successfully\n\n", KVILO_YELLOW, config_file, KVILO_RESET);
  fclose(fp);
}
