# target: prerequisites
 
DEBUG=1
EXECUTABLE_NAME=main
 
CC=gcc
CFLAGS= -Wall
LDFLAGS=

#OBJ= main.o

# Directories
SRC_DIR = src
BIN_DIR = bin

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst %.c, $(BIN_DIR)/%.o, $(notdir $(SRC_FILES)))

ifeq ($(DEBUG),1)
	CFLAGS += -g -O0
else
	CFLAGS = -O3
endif
 
COMPILER_CALL= $(CC) $(CFLAGS)

target: build	clean
 
#%.o: %.c
#	$(COMPILER_CALL) -c $< -o $@

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	$(COMPILER_CALL) -c $< -o $@

build: $(OBJ_FILES)
	$(COMPILER_CALL) $(OBJ_FILES) $(LDFLAGS) -o $(EXECUTABLE_NAME)

#execute:
#	./$(EXECUTABLE_NAME)

clean:
#	mv $(wildcard $(SRC_DIR)/*.o) ./$(BIN_DIR)/
#	mv ./src/*.o ./bin/
	mv $(EXECUTABLE_NAME) ./executable/$(EXECUTABLE_NAME)
