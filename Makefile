# Directories
SRC_DIR = src
COMMON_DIR = $(SRC_DIR)/common
DATA_STRUCT_DIR = $(SRC_DIR)/data_structures
TEST_DIR = $(SRC_DIR)/test

BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
BIN_DIR = $(BUILD_DIR)/bin

INCLUDE_DIRS = \
				$(SRC_DIR) \
				$(COMMON_DIR) \
				$(DATA_STRUCT_DIR)

# Toolchain
CC = clang

CPPCHECK = cppcheck
FORMAT = clang-format

RM = rm -rf

# Flags
TEST_DEFINE = $(addprefix -DTEST=,$(TEST))

WFLAGS = \
			-Wall -Wextra -Werror -Wshadow -Wundef \
			-Wdouble-promotion -Wformat-truncation -Wconversion
CFLAGS = \
			$(WFLAGS) \
			$(TEST_DEFINE) \
			-g \
			$(addprefix -I , $(INCLUDE_DIRS))

# Files
TARGET_NAME = dsa

# determine if the target is the full project software or a test function
ifneq ($(TEST),)
ifeq ($(findstring test_,$(TEST)),)
$(error "TEST=$(TEST) is invalid (test function must start with test_)")
else
TARGET_NAME=test/$(TEST)
endif
endif

TARGET = $(BIN_DIR)/$(TARGET_NAME)

ifndef TEST
MAIN_FILE = $(SRC_DIR)/main.c
else
MAIN_FILE = $(TEST_DIR)/test.c

# touch test.c to force rebuild everytime (for when TEST macro constant changes)
$(shell touch $(TEST_DIR)/test.c)
endif

SOURCES_WITH_HEADERS = \
						$(DATA_STRUCT_DIR)/linked_list.c

SOURCES = \
			$(MAIN_FILE) \
			$(SOURCES_WITH_HEADERS)

HEADERS = \
			$(COMMON_DIR)/defines.h \
			$(SOURCES_WITH_HEADERS:.c=.h)

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
HEADERS_FORMAT_CPPCHECK = $(HEADERS)

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
	$(FORMAT) -i $(SOURCES_FORMAT_CPPCHECK) $(HEADERS_FORMAT_CPPCHECK)

test:
	@echo Building all tests...
	@tools/build_tests.sh
