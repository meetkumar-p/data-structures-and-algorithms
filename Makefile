# Directories
SRC_DIR = src
COMMON_DIR = $(SRC_DIR)/common

BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
BIN_DIR = $(BUILD_DIR)/bin

INCLUDE_DIRS = \
				$(SRC_DIR)

# Toolchain
CC = clang

CPPCHECK = cppcheck
FORMAT = clang-format

RM = rm -rf

# Flags
WFLAGS = \
			-Wall -Wextra -Werror -Wshadow -Wundef \
			-Wdouble-promotion -Wformat-truncation -Wconversion
CFLAGS = \
			$(WFLAGS) \
			-g \
			$(addprefix -I , $(INCLUDE_DIRS))

# Files
TARGET_NAME = dsa

TARGET = $(BIN_DIR)/$(TARGET_NAME)

MAIN_FILE = $(SRC_DIR)/main.c

SOURCES = \
			$(MAIN_FILE)

OBJECT_NAMES = $(patsubst %.s, %.o, $(patsubst %.c, %.o, $(SOURCES)))
OBJECTS = $(patsubst %, $(OBJ_DIR)/%, $(OBJECT_NAMES))

# Static Analysis
CPPCHECK_FLAGS = \
					--quiet \
					--enable=all \
					--error-exitcode=1 \
					--inline-suppr \
					--suppress=missingIncludeSystem \
					--suppress=unmatchedSuppression \
					--suppress=unusedFunction \
					--suppress=checkersReport \
					--suppress=preprocessorErrorDirective

SOURCES_FORMAT_CPPCHECK = $(SOURCES)

# Build
# Compiling
$(OBJ_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $^

# Linking
$(TARGET): $(OBJECTS)
	mkdir -p $(dir $@)
	$(CC) \
			$(CFLAGS) \
			-o $@ $^

# Phonies
.PHONY: all cppcheck clean format test

all: $(TARGET)

cppcheck:
	$(CPPCHECK) \
					$(CPPCHECK_FLAGS) \
					$(addprefix -I, $(INCLUDE_DIRS)) \
					$(SOURCES_FORMAT_CPPCHECK)

clean:
	$(RM) $(BUILD_DIR)

format:
	$(FORMAT) -i $(SOURCES_FORMAT_CPPCHECK)
