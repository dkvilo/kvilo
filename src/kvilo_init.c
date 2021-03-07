/*
* David Kvilora <datokviloria@gmail.com>
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "colors.h"

void kvilo_init(const char *flag, char *config_path, char *config_file)
{

  char *temp_path[sizeof(char *) * 2];
  snprintf(temp_path, sizeof(temp_path), "%s%s", config_path, config_file);

  struct stat st = {0};
  if (stat(config_path, &st) == -1)
  {
    mkdir(config_path, 0700);
  }

  int exists = access(temp_path, F_OK) != -1;
  if (exists && flag == NULL)
  {
    create_error(1, "Note: Collection is already initialized!\n\n\tType: [kvilo init <collection> -f] to recreate");
    create_error(1, "Warning: This action will remove all data from collection\n");
  }
  else if (exists && strcmp(flag, "-f") == 0)
  {
    kvilo_create_col(config_path, config_file);
  }
  else
  {
    kvilo_create_col(config_path, config_file);
  }
}
