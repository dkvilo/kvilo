init:
	mkdir build

buildx:
	gcc -w src/*.c -o build/kvilo

install:
	chmod 711 build/kvilo && sudo cp build/kvilo /usr/bin

clean_bin:
	rm build/kvilo

reset_build:
	rm -rf build
