
.PHONY: buildtools

ROOT_DIR=$(realpath $(dir $(lastword $(MAKEFILE_LIST))))
EMSDK_DIR=$(ROOT_DIR)/buildtools/emsdk
export EM_CONFIG=$(EMSDK_DIR)/.emscripten
export EM_CACHE=$(EMSDK_DIR)/.emscripten_cache
export EMSCRIPTEN=$(EMSDK_DIR)/emscripten/incoming

CC=$(EMSCRIPTEN)/emcc
CXX=$(EMSCRIPTEN)/em++

LDFLAGS=-s WASM=1 # linker flags
CPPFLAGS=-s WASM=1 # shared c++ and c compiler flags
CXXFLAGS= # c++ compiler flags
CFLAGS= # c compiler flags

build: hello.html

clean:
	rm -f *.wasm.js
	rm -f *.o

#
# Download buildtools
#
buildtools: buildtools/emsdk

buildtools/emsdk: buildtools/
	curl https://s3.amazonaws.com/mozilla-games/emscripten/releases/emsdk-portable.tar.gz -o buildtools/emsdk-portable.tar.gz
	mkdir -p buildtools/emsdk
	tar -xzf buildtools/emsdk-portable.tar.gz -C buildtools/emsdk --strip-components=1
	rm buildtools/emsdk-portable.tar.gz
	buildtools/emsdk/emsdk update
	buildtools/emsdk/emsdk install clang-incoming-64bit emscripten-incoming-64bit sdk-incoming-64bit
	buildtools/emsdk/emsdk activate --embedded clang-incoming-64bit emscripten-incoming-64bit sdk-incoming-64bit
	buildtools/emsdk/emsdk construct_env

#
# Specific target
#
hello.html: hello.c

#
# Generic build targets
#
%.html:
	$(CC) $(LDFLAGS) $^ -o $@

%.wasm.js:
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<
