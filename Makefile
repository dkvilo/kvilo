CC := gcc
SOURCE := src
BUILD_DIR := build
BIN := kvilo

prepare:
	mkdir build

install_linux:
	chmod 711 $(BUILD_DIR)/$(BIN) && cp $(BUILD_DIR)/$(BIN) /usr/bin/

install_mac:
	cp $(BUILD_DIR)/$(BIN) /usr/local/bin/

clean_bin:
	rm $(BUILD_DIR)/$(BIN)

clean:
	rm -rf $(BUILD_DIR)

build:
	make prepare && $(CC) -w $(SOURCE)/*.c -o $(BUILD_DIR)/$(BIN)

.PHONY:
	build clean install_mac install_linux
