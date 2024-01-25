# # This makefile builds all test files contained in the `tests/collections` folder into their respective executables.

# # Get the current working directory.
# CURDIR := $(shell pwd)

# # Define the list of test files.
# TEST_FILES := $(wildcard $(CURDIR)/tests/collections/*.test.c)

# # Build all test files.
# $(foreach TEST_FILE, $(TEST_FILES), $(MAKE) -C $(CURDIR)/tests/collections $(TEST_FILE) -I $(CURDIR)/headers)
