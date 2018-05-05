#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#include "../include/c127.h"
#include "../include/kvilo.h"

char config_path[80];
char *config_file =  "/.kconfig";
char answer[5];

int main(int argc, char const *argv[]) {

	snprintf(config_path, sizeof config_path, getenv("HOME"));
	time_t my_time;
	time(&my_time);

	if ( argc <= 1 ) {
		create_error(0, "Missing Arguments: Type kvilo -h");
		return 1;
	}

	if (strcmp(argv[1], "init") == 0) {
		FILE *fp = fopen(strcat(config_path, config_file), "w");

		if (fp == NULL) {
			create_error(0, "While Createing Config ...");
			return 1;
		}

		create_message("Config was generated [OK]\n");
		fclose(fp);
	}

	else if (strcmp(argv[1], "get") == 0) {
		char *val = getConfig((char *)argv[2]);
		printf("%s", val);
	}

	else if (strcmp(argv[1], "set") == 0) {
		FILE *fp = fopen(strcat(config_path, config_file), "a");

		if (fp == NULL) {
			create_error(0, "While Updating Config ...");
			return 1;
		}

		fprintf(fp, "%s\n", argv[2]);
		fclose(fp);
	}


	else if (strcmp(argv[1], "list") == 0) {

		char *key;
		char *value;
		char *search = "=";

		FILE *fp = fopen(strcat(config_path, config_file), "r");

		if (fp == NULL) {
			create_error(0, "kconfig file not found! Type:\n\n\t[+] kvilo init \n\t[+] kvilo -i\n");
			create_error(0, "Help: kvilo -h");
			return 1;
		}

		char line[128];
		unsigned short count_line = 0;

		printf("File: %s/\n", config_path );
		while (fgets(line, sizeof line, fp) != NULL) {
			count_line++;
			key = strtok(line, search);
			value = strtok(NULL, search);
			printf(" %d) %s = %s", count_line, key, value);
		}

		printf("\n");
		fclose(fp);
	}

	else if ( strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--validate") == 0) {

		if (argc <= 2) {
			create_error(0, "Missing argument: kvilo --validate <key> <value>");
			return 1;
		}

		char *username = (char *) getConfig((char *) argv[2]);

		remove_from_string(username, '\n');

		if (strcmp(username, argv[3]) == 0 ) {
			printf("[+] Status: [OK]\n");
		} else {
			create_error(0, "[NOT_OK]");
			return 1;
		}

	}

	 else {
		create_error(0, "Unknown args Type: kvilo -h");
	}

	return 0;
}

void create_message(const char *message) {
	printf("[+] %s", message);
}

void create_error(unsigned short type, const char *message) {
	if (type) printf("\n [x] Error: %s\n", message);
	else printf("[x] Error: %s\n", message);
}

char *getConfig(char *target_key) {

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
			fclose(fp);
		}
	}

	return  value;
}

void remove_from_string(char* source, char target) {
  char *i = source;
  char *j = source;
  while(*j != 0) {
    *i = *j++;
    if(*i != target) {
      i++;
		}
  }
  *i = 0;
}
