/*
* David Kviloria <datokviloria@gmail.com>
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getConfig(char *target_key, char *config_path, char *config_file) {

	FILE *fp = fopen(strcat(config_path, config_file), "r");

	char *line[128];
	char *search = "=";
	char *token;
	char *value;

	while (fgets(line, sizeof line, fp) != NULL) {
		token = strtok(line, search);
		if (strcmp(target_key, token) == 0 )  {
			value = strtok(NULL, search);
			break;
		} else {
			value = "NONE";
		}
	}

	fclose(fp);
	return  value;
}
