
ROOT_DIR=$(realpath $(dir $(lastword $(MAKEFILE_LIST))))
EMSDK_DIR=$(ROOT_DIR)/buildtools/emsdk
export EM_CONFIG=$(EMSDK_DIR)/.emscripten
export EM_CACHE=$(EMSDK_DIR)/.emscripten_cache
export EMSCRIPTEN=$(EMSDK_DIR)/emscripten/incoming

CC=$(EMSCRIPTEN)/emcc
CXX=$(EMSCRIPTEN)/em++

# https://github.com/kripken/emscripten/wiki/WebAssembly
# TODO: https://github.com/kripken/emscripten/wiki/WebAssembly-Standalone
LDFLAGS=--bind # linker flags
LDFLAGS+=-s WASM=1 # compile as .wasm, this is the same as BINARYEN=1
LDFLAGS+=-s "BINARYEN_METHOD='native-wasm'" # only compile to native-wasm
LDFLAGS+=-s BINARYEN_IMPRECISE=1 # don't care about compatibility with asm.js
CPPFLAGS= # shared c++ and c compiler flags
CXXFLAGS=-std=c++11 --bind # c++ compiler flags
CFLAGS= # c compiler flags

#
# PHONY targets
#
.PHONY: build lint clean buildtools-update

build: hello.html

lint: .clang_complete

clean:
	rm -f hello.html hello.js hello.asm.js hello.wasm hello.wast
	rm -f *.o

buildtools-update:
	rm -rf buildtools
	make buildtools/emsdk

#
# Setup buildtools
#
buildtools/:
	mkdir buildtools

buildtools/emsdk: | buildtools/
	curl https://s3.amazonaws.com/mozilla-games/emscripten/releases/emsdk-portable.tar.gz -o buildtools/emsdk-portable.tar.gz
	mkdir buildtools/emsdk
	tar -xzf buildtools/emsdk-portable.tar.gz -C buildtools/emsdk --strip-components=1
	rm buildtools/emsdk-portable.tar.gz
	buildtools/emsdk/emsdk update
	buildtools/emsdk/emsdk install clang-incoming-64bit emscripten-incoming-64bit sdk-incoming-64bit
	buildtools/emsdk/emsdk activate --embedded clang-incoming-64bit emscripten-incoming-64bit sdk-incoming-64bit

.clang_complete:
	 @echo "-isystem$(EMSCRIPTEN)/system/include" > .clang_complete

#
# Specific target
#
hello.html: hello.o

#
# Generic build targets
#
%.html: | buildtools/emsdk
	$(CC) $(LDFLAGS) $^ -o $@

%.wasm.js: | buildtools/emsdk
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.cc | buildtools/emsdk
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

%.o: %.c | buildtools/emsdk
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<
