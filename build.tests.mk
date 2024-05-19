CC = clang
CFLAGS = -Wall -Wextra -g
LFLAGS = -ltoolbox -L$(HOME)/Dev/libs/
IFLAGS = -Iinclude

OBJ_DIR = obj/tests
TEST_DIR = tests
BUILD_DIR = build/linux/tests

# Find all source and test files
TEST_SOURCES := $(wildcard $(TEST_DIR)/**/*.test.c)

# Generate corresponding object files
TEST_OBJECTS := $(patsubst $(TEST_DIR)/%.test.c,$(OBJ_DIR)/%.o,$(TEST_SOURCES))

# Generate corresponding test names and paths
TEST_EXECUTABLES := $(patsubst $(TEST_DIR)/%.test.c,$(BUILD_DIR)/%,$(TEST_SOURCES))

# Rule to build each object file from test
$(BUILD_DIR)/%.o: $(TEST_DIR)/%.test.c
	@echo compile objs...
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<

# Rule to build each test executable
$(BUILD_DIR)/%: $(BUILD_DIR)/%.o $(OBJECTS)
	@echo compile test program...
	@$(CC) $(CFLAGS) $(LFLAGS) -o $@ $^

# Rule to build all test executables
tests: $(TEST_EXECUTABLES)

.PHONY: clean
clean:
	@rm -rf $(BUILD_DIR)

# Add additional rules as needed