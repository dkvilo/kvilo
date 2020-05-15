#include <stdio.h>
#include <string.h>

#include "../include/colors.h"

#include "kvilo_get_config.h"

void kvilo_unset(const char *cli_key, char *config_path, char *config_file) {
  
  char *val = getConfig((char *) cli_key, config_path, config_file);

  if (strcmp(val, "NONE") == 0) {
    create_error(1, "Variable not found! Type:\tkvilo set <key>=<value>\n");
    exit(0);
  }

  char path[128];
  char *inFileName = config_path;

  snprintf(path, sizeof path, "%s%s", config_path, "-old2");

  char *outFileName = path;
  char *search = "=";
  
  FILE *inFile = fopen(inFileName, "r");
  FILE *outFile = fopen(outFileName, "w+");
  
  char line [1024];

  if( inFile == NULL ) {
    printf("Open Error");
    exit(0);
  }

  while( fgets(line, sizeof(line), inFile) != NULL ) {

    char *b_line = line;
    char *key = strtok(b_line, search);
    char *value = strtok(NULL, search);

    if (strcmp(cli_key, line) == 0) {
      continue;
    } else {
      if (value != NULL)
        fprintf(outFile, "%s=%s", key, value);
    }

  }

  fclose(inFile);
  fclose(outFile);

  if( !rename(outFileName, inFileName) ) {
    if ( rename(outFileName, inFileName) ) {
      printf("\n [+] Variable (%s%s%s) has been removed from (%s%s%s) collection\n\n", KVILO_RED, cli_key, KVILO_RESET, KVILO_YELLOW, "master", KVILO_RESET);
    }
  }

}
