# Compiler options
CC=g++
CFLAGS=-c -Wall -std=c++11 -pedantic-errors
LDFLAGS=
EXECUTABLE_NAME=test

# Folders
SRC_DIRS := src
INC_DIRS := include
BIN=bin
OBJ=obj

##
## Don't change below here
##

# Files
SRC_FILES := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))
CFLAGS+=$(INC_FLAGS)

EXECUTABLE_FILES = $(EXECUTABLE_NAME:%=$(BIN)/%)
OBJECT_FILES     = $(SRC_FILES:%.cpp=$(OBJ)/%.o)
#     http://www.gnu.org/software/make/manual/make.html#Substitution-Refs

build: $(EXECUTABLE_FILES)

clean:
	rm -rf $(BIN) $(OBJ)

# http://www.gnu.org/software/make/manual/make.html#Phony-Targets
.PHONY: build clean

$(EXECUTABLE_FILES): $(OBJECT_FILES)
	mkdir -p $(@D)
	$(CC) $(LDFLAGS) -o $@ $^
	@# ^^^ http://www.gnu.org/software/make/manual/make.html#Automatic-Variables
	@echo "Build successful!"

# http://www.gnu.org/software/make/manual/make.html#Static-Pattern
$(OBJECT_FILES): $(OBJ)/%.o: %.cpp
	@echo Compiling $<
	mkdir -p $(@D)
	@# ^^^ http://www.gnu.org/software/make/manual/make.html#index-_0024_0028_0040D_0029
	$(CC) $(CFLAGS) -o $@ $<
