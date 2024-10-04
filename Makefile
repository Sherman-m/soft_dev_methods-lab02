CLANG_FORMAT ?= clang-format
CLANG_TIDY ?= clang-tidy
CLANG ?= clang++
GAME_CODE ?=

.PHONY: all
all: build 

# Start
.PHONY: start
start: build
	./build/game $(GAME_CODE)

# Build 
.PHONY: build
build: format 
	mkdir -p build
	find src -name '*pp' -type f | xargs $(CLANG) -std=c++20 -o ./build/game

# Format
.PHONY: format
format:
	find src -name '*pp' -type f | xargs $(CLANG_TIDY) --extra-arg=-std=c++20 --fix
	find src -name '*pp' -type f | xargs $(CLANG_FORMAT) -i

.PHONY: clean
clean:
	rm -rf build

