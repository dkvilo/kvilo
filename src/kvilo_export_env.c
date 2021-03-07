/*
* David Kvilora <datokviloria@gmail.com>
*/
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "colors.h"
#include "version.h"

void kvilo_export_env(char *config_path, char *config_file, short example)
{

  char *key;
  char *value;
  char *search = "=";
  const char *envArray[250];

  time_t rawtime;
  struct tm *timeinfo;
  time(&rawtime);
  timeinfo = localtime(&rawtime);

  FILE *fp = fopen(strcat(config_path, config_file), "r");

  if (fp == NULL)
  {
    printf(fp, "# KVILO ENV Manager %s\n# Collection: `%s`\n# Time: %s\n", VERSION, config_file, asctime(timeinfo));
    exit(0);
  }

  char line[128];
  unsigned short count_line = 0;

  printf("# KVILO ENV Manager %s\n# Collection: `%s`\n# Time: %s\n", VERSION, config_file, asctime(timeinfo));
  while (fgets(line, sizeof line, fp) != NULL)
  {
    count_line++;
    key = strtok(line, search);
    if (!example)
    {
      value = strtok(NULL, search);
      printf("%s=%s", key, value);
    }
    else
    {
      printf("%s=\n", key);
    }
  }

  fclose(fp);
}
