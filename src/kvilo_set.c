/*
* David Kvilora <datokviloria@gmail.com>
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "colors.h"

void kvilo_set(char *config_path, char *config_file, const char *var) {

  if (var != NULL) {

    char *line[1024];
    char *token;
    char *value;
    char *search = "=";
    char *cliKey;
    char *res_var = (char *) malloc(strlen((char *) var) *sizeof(var));
		unsigned char write = 1;

    /*
    * Save var
    */
    strcpy(res_var, var);

    FILE *fp = fopen(strcat(config_path, config_file), "a+");

    if (fp == NULL) {
      create_error(1, "Error While Update Collection\n");
      exit(0);
    }

    /*
    * Get Key form cli
    */
    cliKey = strtok(res_var, search);
    value = strtok(NULL, search);
		
    while (fgets(line, sizeof line, fp) != NULL) {
      token = strtok(line, search);
      if (strcmp(cliKey, token) == 0 )  {
        create_error(1, "Key is already in Collection\n");
        write = 0;
      }
    }

    if (value != NULL) {
      if (write) {
        fprintf(fp, "%s\n", var);
      }
    } else {
      // create_error(1, "Error: Invalid Syntax!")
      printf("\n %s[x]%s Error: invalid syntax %s`%s`%s\n\n\tValid: %sfoo=bar%s\n\n", KVILO_RED, KVILO_RESET, KVILO_RED, var, KVILO_RESET, KVILO_GREEN, KVILO_RESET);
    }

		free(res_var);
    
		fclose(fp);

  } else {
    create_error(1, "Missing <key>=<value>\n");
  }

}
