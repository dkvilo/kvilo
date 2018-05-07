/*
* David Kvilora <datokviloria@gmail.com>
*/
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "../include/colors.h"
#include "../include/version.h"

/*
* TODO: need to support to export diff collection as env file
*/
void kvilo_export_env(char *config_path, char *config_file) {

  char *key;
  char *value;
  char *search = "=";
  const char *envArray[250];

  time_t rawtime;
  struct tm * timeinfo;
  time ( &rawtime );
  timeinfo = localtime ( &rawtime );

  FILE *fp = fopen(strcat(config_path, config_file), "r");

  if (fp == NULL) {
    printf(fp, "# KVILO ENV Manager %s\n# Collection: `%s`\n# Time: %s\n", VERSION, "master", asctime(timeinfo));
    return 1;
  }

  char line[128];
  unsigned short count_line = 0;

  printf("# KVILO ENV Manager %s\n# Collection: `%s`\n# Time: %s\n", VERSION, "master", asctime(timeinfo));
  while (fgets(line, sizeof line, fp) != NULL) {
    count_line++;
    key = strtok(line, search);
    value = strtok(NULL, search);
    printf("%s=%s", key, value);
  }

  fclose(fp);
}
