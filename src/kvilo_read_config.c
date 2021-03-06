/*
* David Kvilora <datokviloria@gmail.com>
*/
#include <stdio.h>
#include <string.h>

#include "colors.h"
#define DEFINE_KVILO_UTIL_NO_STATIC
#include "kvilo_util.h"

void kvilo_read_config(char *config_path, char *config_file)
{

  char *key;
  char *value;
  char *search = "=";

  FILE *fp = fopen(strcat(config_path, config_file), "r");

  if (fp == NULL)
  {
    create_error(0, "Collection not found! Type:\n\n\t[+] kvilo init \n\t[+] kvilo -i\n");
    create_error(0, "Help: kvilo -h");
    exit(0);
  }

  char line[1024];
  unsigned short count_line = 0;

  printf("Collection: %s[%s]%s\n\n", KVILO_YELLOW, config_file, KVILO_RESET);
  while (fgets(line, sizeof line, fp) != NULL)
  {
    count_line++;
    key = strtok(line, search);
    value = strtok(NULL, search);
    printf(" %d) %s = %s", count_line, key, value);
  }

  if (count_line == 0)
  {
    create_error(0, "Collection is empty type:\tkvilo set <key> <value>");
  }

  printf("\n");
  fclose(fp);
}
