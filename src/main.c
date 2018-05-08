/*
* David Kvilora <datokviloria@gmail.com>
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../include/kvilo.h"

#include "kvilo_set.h"
#include "kvilo_unset.h"
#include "kvilo_init.h"
#include "kvilo_read_config.h"
#include "kvilo_get_config.h"
#include "kvilo_validate.h"
#include "kvilo_get.h"
#include "kvilo_help.h"

char config_path[80];
char *config_file =  "/.kvilo_master";

int main(int argc, char const *argv[]) {

	snprintf(config_path, sizeof config_path, getenv("HOME"));

	if ( argc <= 1 ) {
		kvilo_help();
		return 1;
	}

	if (strcmp(argv[1], "init") == 0 || strcmp(argv[1], "-i") == 0) {
 	 if (argc == 3) {
 		 if (strcmp(argv[2], "-f") == 0) {
 			 kvilo_init(argv[2], config_path, config_file);
 		 } else {
 			 create_error(1, "Error: Unknown Flag for init: Did you mean -f ?\n");
 		 }
 	 } else {
 		 kvilo_init(NULL, config_path, config_file);
 	 }
  }

	else if (strcmp(argv[1], "get") == 0) {
		if (argc <= 2) {
			create_error(1, "Error: Missing argument for get! Type:\t kvilo get <key>\n");
			return 1;
		}
		kvilo_get(argv[2], config_path, config_file);
	}

	else if (strcmp(argv[1], "set") == 0) {
		kvilo_set(config_path, config_file, argv[2]);
	}

	else if (strcmp(argv[1], "show") == 0) {
		kvilo_read_config(config_path, config_file);
	}

	else if ( strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "validate") == 0) {
		if (argc <= 3) {
			create_error(1, "Error: Missing argument for get! Type:\t kvilo validate <key> <value>\n");
			return 1;
		}
		kvilo_validate(argv[2], config_path, config_file, argv[3]);
	}

	else if (strcmp(argv[1], "export-env") == 0 || strcmp(argv[1], "-e-env") == 0) {
		kvilo_export_env(config_path, config_file);
	}

	else if (strcmp(argv[1], "export") == 0 || strcmp(argv[1], "-e") == 0) {
		system("kvilo export-env > .env");
	}

	else if (strcmp(argv[1], "export-example") == 0 || strcmp(argv[1], "-ee") == 0) {
		system("kvilo export-env > .env-example");
	}

	else if (strcmp(argv[1], "-u") == 0 || strcmp(argv[1], "unset") == 0) {
		if (argc <= 2) {
			create_error(1, "Error: Missing argument for unset! Type:\t kvilo unset <key>\n");
			return 1;
		}
		kvilo_unset(argv[2], config_path, config_file);
	}

	else if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "help") == 0) {
		kvilo_help();
	}

	 else {
		create_error(1, "Unknown args Type: kvilo -h\n");
	}

	return 0;
}

void create_message(const char *message) {
	printf("[+] %s", message);
}

void create_error(unsigned short type, const char *message) {
	if (type) printf(KVILO_RED"\n [x]%s %s\n", KVILO_RESET, message);
	else printf(KVILO_RED" [x]%s %s\n", KVILO_RESET, message);
}
