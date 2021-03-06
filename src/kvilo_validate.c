/*
* David Kvilora <datokviloria@gmail.com>
*/

#include <stdio.h>
#include <string.h>

#include "kvilo_get_config.h"
#include "colors.h"

void kvilo_validate(const char *key, char *config_path, char *config_file, const char *from_cli)
{

  char *val = get_config((char *)key, config_path, config_file);

  if (strcmp(val, "NONE") == 0)
  {
    create_error(1, "Variable not found! Type:\tkvilo set <key>=<value>\n");
    exit(0);
  }

  /*
  * Remove \n from value
  */
  rmcfs(val, '\n');

  printf("\n Variable Validation in Collection: %s[%s]%s\n\n", KVILO_YELLOW, config_file, KVILO_RESET);

  if (strcmp(val, from_cli) == 0)
  {
    printf("\t[+] status: %sTRUE\n", KVILO_GREEN);
    printf("%s\t[+] excepted: %s=%s\n", KVILO_RESET, key, from_cli);
    printf("%s\t[+] actual: %s=%s\n", KVILO_RESET, key, val);
    printf("\n");
    exit(0);
  }

  printf("\t[x] status: %sFALSE\n", KVILO_RED);
  printf("%s\t[+] excepted: %s=%s\n", KVILO_RESET, key, from_cli);
  printf("%s\t[+] actual: %s=%s\n", KVILO_RESET, key, val);
  printf("\n");
}
