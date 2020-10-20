/*
* David Kvilora <datokviloria@gmail.com>
* 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define DEFINE_NO_INLINE
#include "../include/kvilo.h"

#include "kvilo_set.h"
#include "kvilo_unset.h"
#include "kvilo_init.h"
#include "kvilo_read_config.h"
#include "kvilo_get_config.h"
#include "kvilo_validate.h"
#include "kvilo_get.h"
#include "kvilo_help.h"
#include "kvilo_create_col.h"


int main(int argc, char const *argv[]) {

  char *config_path[256];
	snprintf(config_path, sizeof(config_path), getenv("HOME"));

  config_t cfg;
  new_config(&cfg);
  absolute_path(&cfg, config_path);
  config_load_defaults(&cfg);

  bind_lua(&cfg, argv);

	if ( argc <= 1 ) {
		kvilo_help();
		return 0;
	}

  if (strcmp(argv[1], "init") == 0 || strcmp(argv[1], "-i") == 0) {
    if (argc == 3) strcpy(cfg.m_default_collection, argv[2]);
    kvilo_init((argv[3]), cfg.m_path, cfg.m_default_collection);
  }

	if (strcmp(argv[1], "get") == 0 || strcmp(argv[1], "-g") == 0) {

    if (argc == 3) {
      kvilo_get(argv[2], cfg.m_path, cfg.m_default_collection);
      return 0;
    }

    else if (argc == 4) {
      strcpy(cfg.m_default_collection, argv[2]);
		  kvilo_get(argv[3], cfg.m_path, cfg.m_default_collection);
      return 0;
    }

    else {
      create_error(1, "Error: Wrong usage of [GET]");
      create_message("Usage: kvilo get <collection> (optional) <key> (required)");
			return 1;
    }

	}

	if (strcmp(argv[1], "set") == 0 || strcmp(argv[1], "-s") == 0) {
    
    if (argc == 3) {
      kvilo_set(cfg.m_path, cfg.m_default_collection, argv[2]);
      return 0;
    }
    
    else if (argc == 4) {
      strcpy(cfg.m_default_collection, argv[2]);
	  	kvilo_set(cfg.m_path, cfg.m_default_collection, argv[3]);
      return 0;
    }

    else {
      create_error(1, "Error: Wrong usage of [SET]");
      create_message("Usage: kvilo set <collection> (optional) <key=<value> (required)");
			return 1;
    }

	}

  if (strcmp(argv[1], "-u") == 0 || strcmp(argv[1], "unset") == 0) {
    
    if (argc == 3) {
      kvilo_unset(argv[2], cfg.m_path, cfg.m_default_collection);
			return 0;
		}

    else if (argc == 4) {
      strcpy(cfg.m_default_collection, argv[2]);
      kvilo_unset(argv[3], cfg.m_path, cfg.m_default_collection);
      return 0;
    }

    else {
			create_error(1, "Error: Wrong usage of [UNSET]");
      create_message("Usage: kvilo unset <collection> (optional) <key> (required)");
    }
	}

	if (strcmp(argv[1], "show") == 0 || strcmp(argv[1], "ls") == 0) {
    if (argc == 3) strcpy(cfg.m_default_collection, argv[2]);
		kvilo_read_config(cfg.m_path, cfg.m_default_collection);
	}

	if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "val") == 0) {

    if (argc == 4) {
      kvilo_validate(argv[2], cfg.m_path, cfg.m_default_collection, argv[3]);
			return 0;
		}

    else if (argc == 5) {
      strcpy(cfg.m_default_collection, argv[2]);
      kvilo_validate(argv[3], cfg.m_path, cfg.m_default_collection, argv[4]);
      return 0;
    }

    else {
			create_error(1, "Error: Wrong usage of [VAL]");
      create_message("Usage: kvilo val <collection> (optional) <key> (required) <value> (required)");
      return 1;
    }
	}

	if (strcmp(argv[1], "exp") == 0 || strcmp(argv[1], "-e") == 0) {
		
    if (argc == 2) {
      kvilo_export_env(cfg.m_path, cfg.m_default_collection, 0);
			return 0;
		}

    else if (argc == 3) {
      strcpy(cfg.m_default_collection, argv[2]);
      kvilo_export_env(cfg.m_path, cfg.m_default_collection, 0);
      return 0;
    }

    else {
			create_error(1, "Error: Wrong usage of [EXP]");
      create_message("Usage: kvilo exp <collection> (optional)");
    }

	}

	if (strcmp(argv[1], "exp-example") == 0 || strcmp(argv[1], "-ee") == 0) {
    if (argc == 2) {
      kvilo_export_env(cfg.m_path, cfg.m_default_collection, 1);
			return 0;
		}

    else if (argc == 3) {
      strcpy(cfg.m_default_collection, argv[2]);
      kvilo_export_env(cfg.m_path, cfg.m_default_collection, 1);
      return 0;
    }

    else {
			create_error(1, "Error: Wrong usage of [SYS-EXP-ENV]");
      create_message("Usage: kvilo exp-example <collection> (optional)");
    }
	}

	if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "help") == 0) {
		kvilo_help();
	}

	return 0;
}

