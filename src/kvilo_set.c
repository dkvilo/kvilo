/*
* David Kvilora <datokviloria@gmail.com>
*/
#include <stdio.h>
#include <string.h>

void kvilo_set(char *config_path, char *config_file, const char *var) {

  if (var != NULL) {

    char *line[128];
    char *token;
    char *search = "=";
    char *cliKey;
    char res_var[100];
    unsigned char write = 1;

    /*
    * Save var
    */
    strcpy(res_var, var);

    FILE *fp = fopen(strcat(config_path, config_file), "a+");

    if (fp == NULL) {
      create_error(1, "Error While Update Collection\n");
      return 1;
    }

    /*
    * Get Key form cli
    */
    cliKey = strtok(res_var, search);

    while (fgets(line, sizeof line, fp) != NULL) {
      token = strtok(line, search);
      if (strcmp(cliKey, token) == 0 )  {
        create_error(1, "Key is already in Collection\n");
        write = 0;
      }
    }

    if (write) {
      fprintf(fp, "%s\n", var);
    }

    fclose(fp);

  } else {
    create_error(1, "Missing <key>=<value>\n");
  }

}
