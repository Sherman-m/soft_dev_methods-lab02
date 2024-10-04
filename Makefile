CLANG_FORMAT ?= clang-format
CLANG_TIDY ?= clang-tidy
CLANG ?= clang++
GAME_CODE ?=
PROG_TARGET ?= lab02

CMAKE_DEBUG_FLAGS += -DCMAKE_BUILD_TYPE=Debug $(CMAKE_COMMON_FLAGS)
CMAKE_RELEASE_FLAGS += -DCMAKE_BUILD_TYPE=Release $(CMAKE_COMMON_FLAGS)

.PHONY: all
all: build 

# Run cmake
.PHONY: cmake-debug
cmake-debug: check-lint 
	cmake -B build_debug $(CMAKE_DEBUG_FLAGS)

.PHONY: cmake-release
cmake-release: check-lint 
	cmake -B build_release $(CMAKE_RELEASE_FLAGS)

build_debug/CMakeCache.txt: cmake-debug
build_release/CMakeCache.txt: cmake-release

# Build using cmake
.PHONY: build-debug build-release
build-debug build-release: build-%: build_%/CMakeCache.txt 
	cmake --build build_$* -j $(NPROCS) --target $(PROG_TARGET) 

# Start games
.PHONY: start-debug start-release
start-debug start-release: start-%: build-%
	./build_$*/$(PROG_TARGET) $(GAME_CODE)

# Linters
.PHONY: 
check-lint:
	find src -name '*pp' -type f | xargs $(CLANG_TIDY) --extra-arg=-std=c++20
	find src -name '*pp' -type f | xargs $(CLANG_FORMAT) --Werror --dry-run

# Linters
.PHONY: 
lint:
	find src -name '*pp' -type f | xargs $(CLANG_TIDY) --extra-arg=-std=c++20 --fix
	find src -name '*pp' -type f | xargs $(CLANG_FORMAT) -i

# Clean
.PHONY: clean
clean:
	rm -rf build_*

# CodeClimate
.PHONY: codeclimate
codeclimate:
	codeclimate analyze src

