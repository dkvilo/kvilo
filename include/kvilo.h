/*
* David Kviloria <datokviloria@gmail.com>
*/
#pragma once

#ifndef KVILO_H
#define KVILO_H

#include "colors.h"
#include <unistd.h>

#include "version.h"

#include "lua.h"
#include "lauxlib.h"

typedef struct {
  char m_path[180];
  char m_dir[180];
  char m_default_collection[180];
  char m_default_config[80];
  lua_State *L;
} config_t;

#ifdef DEFINE_NO_INLINE
#define KVILO_FUNC_TYPE extern
#else
#define KVILO_FUNC_TYPE extern inline
#endif

KVILO_FUNC_TYPE
void new_config(config_t *cfg) {
  strcpy(cfg->m_dir, "/.kvilo/");
  strcpy(cfg->m_default_config, "conf.lua");
  strcpy(cfg->m_default_collection, "main");
}

KVILO_FUNC_TYPE
void generate_collection_path(config_t *cfg) {
  strcpy(cfg->m_path, getenv("HOME"));
  strcat(cfg->m_path, cfg->m_default_collection);
}

KVILO_FUNC_TYPE
void absolute_path(config_t *cfg, char *path) {
  strcpy(cfg->m_path, path);
}

KVILO_FUNC_TYPE
void config_load_defaults(config_t *cfg) {
  strcat(cfg->m_path, cfg->m_dir);
}

KVILO_FUNC_TYPE
void create_message(const char *message) {
	printf(KVILO_YELLOW" [?] %s%s\n",KVILO_RESET, message);
}

KVILO_FUNC_TYPE
void create_error(unsigned short type, const char *message) {
	if (type) printf(KVILO_RED"\n [x]%s %s\n", KVILO_RESET, message);
	else printf(KVILO_RED" [x]%s %s\n", KVILO_RESET, message);
}

KVILO_FUNC_TYPE
void bind_lua(config_t *cfg, char const *argv[]) {
  cfg->L = luaL_newstate();
  luaL_openlibs(cfg->L);

  lua_createtable(cfg->L, 0, 6);

  lua_pushstring(cfg->L, "version");
  lua_pushstring(cfg->L, VERSION);
  lua_settable(cfg->L, -3);

  lua_pushstring(cfg->L, "arg1");
  lua_pushstring(cfg->L, argv[1]);
  lua_settable(cfg->L, -3);

  lua_pushstring(cfg->L, "arg2");
  lua_pushstring(cfg->L, argv[2]);
  lua_settable(cfg->L, -3);

  lua_pushstring(cfg->L, "arg3");
  lua_pushstring(cfg->L, argv[3]);
  lua_settable(cfg->L, -3);

  lua_pushstring(cfg->L, "arg4");
  lua_pushstring(cfg->L, argv[4]);
  lua_settable(cfg->L, -3);

  lua_pushstring(cfg->L, "arg5");
  lua_pushstring(cfg->L, argv[5]);
  lua_settable(cfg->L, -3);

  lua_setglobal(cfg->L, "kvilo");

  char *config_path[120];
  snprintf(config_path, sizeof(config_path), "%s%s", cfg->m_path, cfg->m_default_config);

  if (access(config_path, F_OK) != -1) {
    
    luaL_dofile(cfg->L, config_path);

    lua_getglobal(cfg->L, "boot");
    lua_pcall(cfg->L, 1, 1, 1);
    
    const char *cmd = lua_tostring(cfg->L, -1);
    if (cmd != NULL) {
      system(cmd);
    } 
  }
}

#endif
