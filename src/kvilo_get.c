/*
* David Kvilora <datokviloria@gmail.com>
*/
#include <stdio.h>
#include <string.h>

#include "kvilo_get_config.h"

void kvilo_get(const char *key, char *config_path, char *config_file){
  char *val = getConfig((char *) key, config_path, config_file);
  if (strcmp(val, "NONE") == 0) {
    create_error(1, "Variable not found! Type:\tkvilo set <key>=<value>\n");
    return 1;
  }
  printf("%s", val);
}
