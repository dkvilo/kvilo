/*
* David Kvilora <datokviloria@gmail.com>
*/
#include <stdio.h>
#include <unistd.h>

#include "../include/colors.h"

void create_coll(char *config_path, char *config_file);

void kvilo_init(const char *flag, char *config_path, char *config_file) {

  if (access(strcat(config_path, config_file), F_OK) != -1) {
    if (flag != NULL) {
      if (strcmp(flag, "-f") == 0) {
        create_coll(config_path, config_file);
      }
    } else {
      create_error(1, "Note: Collection [master] is initialized!\n\n\tType: [kvilo init -f] to recreate");
      create_error(1, "Warning: This action will remove all data from clollection\n");
    }
  } else {
    create_coll(config_path, config_file);
  }
}

void create_coll(char *config_path, char *config_file) {

  FILE *fp = fopen(config_path, "w");
  if (fp == NULL) {
    create_error(1, "SYSError: While Createing Config ...\n");
    exit(0);
  }
  printf("\n [+] Collection %s[master]%s generated successfully\n\n", KVILO_YELLOW, KVILO_RESET);
  fclose(fp);

}
