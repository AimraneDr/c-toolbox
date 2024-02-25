CC = clang
CFLAGS = -Wall -g

LIB_NAME = toolbox
BUILD_DIR = /usr/lib
OBJ_DIR = obj/src

DEFINES = -D_DEBUG
INCLUDE_PATH = -Iinclude
LINKER_FLAGS = -lX11

SRC :=  $(wildcard $(shell find ./src -name '*.c'))
OBJ := $(patsubst ./src/%.c, $(OBJ_DIR)/%.o, $(SRC))

all : scaffold $(LIB_NAME)

scaffold :
	@echo scaffolding ... 
	@mkdir -p $(dir $(OBJ))

$(LIB_NAME): $(OBJ)
	@echo building $(LIB_NAME) ...
	@sudo $(CC) $(CFLAGS) -shared -o $(BUILD_DIR)/lib$@.so $^ $(LINKER_FLAGS)
	@echo done.

$(OBJ_DIR)/%.o: ./src/%.c
	@echo compiling $@...
	@$(CC) $(CFLAGS) -fPIC -c -o $@ $< $(INCLUDE_PATH) $(DEFINES)

clean:
	@echo cleaning ...
	sudo rm $(BUILD_DIR)/lib$(LIB_NAME).so*
	rm -rf $(OBJ_DIR)/*

.PHONY: all scaffold clean
