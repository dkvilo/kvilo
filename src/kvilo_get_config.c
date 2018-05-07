/*
* David Kviloria <datokviloria@gmail.com>
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/colors.h"

char *getConfig(char *target_key, char *config_path, char *config_file) {

	char *line[128];
	char *search = "=";
	char *token;
	char *value;
	long int size;

	FILE *fp = fopen(strcat(config_path, config_file), "r");

	if (fp == NULL) {
			value = "NONE";
			create_error(0, "Collection not found! Type:\n\n\t[+] kvilo init \n\t[+] kvilo -i\n");
			return value;
	}

	while (fgets(line, sizeof line, fp) != NULL) {
		token = strtok(line, search);
		if (strcmp(target_key, token) == 0 ) {
			value = strtok(NULL, search);
			break;
		} else {
			value = "NONE";
		}
	}

	/*
	* Check if collection is not empty
	*/
	if (NULL != fp) {
		fseek (fp, 0, SEEK_END);
		size = ftell(fp);
		if (0 == size) {
				printf("\n [!] Collection %s[%s]%s is empty!\n", KVILO_YELLOW, "master", KVILO_RESET);
				value = "NONE";
				return value;
		}
	}

	fclose(fp);
	return value;
}
