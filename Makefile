# David Kviloria 2016 - 2020
# datokviloria@gmail.com

CC := gcc -std=c99
SOURCE := src
BUILD_DIR := build
BIN := kvilo
KVILO_HOME := ~/.kvilo

KVILO_INCS := include
DEPS_DIR := deps

LUA_DIR := $(DEPS_DIR)/lua-5.2.0
LUA_LIB := $(LUA_DIR)/install/lib/liblua.a

FINAL_CFLAGS := -I./$(KVILO_INCS) -I./$(LUA_DIR)/src ./$(LUA_LIB)

lua:
	cd $(LUA_DIR) && make local

prepare:
	mkdir build

copy_config:
	cp ./conf.lua $(KVILO_HOME)

install_linux:
	chmod 711 $(BUILD_DIR)/$(BIN) && cp $(BUILD_DIR)/$(BIN) /usr/bin/

install_mac:
	cp $(BUILD_DIR)/$(BIN) /usr/local/bin/

clean_bin:
	rm $(BUILD_DIR)/$(BIN)

clean:
	rm -rf $(BUILD_DIR)

build:
	make prepare && make lua && $(CC) -w $(SOURCE)/*.c $(FINAL_CFLAGS) -o $(BUILD_DIR)/$(BIN)

.PHONY:
	build clean install_mac install_linux lua prepare

.DEFAULT:
	build