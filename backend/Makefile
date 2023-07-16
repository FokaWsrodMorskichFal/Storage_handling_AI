CXX       := g++
CXX_FLAGS := -std=c++17 -ggdb

BIN     := bin
SRC     := src
INCLUDE_DIRS := $(shell find include -type d) lib
LIBRARIES   :=
EXECUTABLE  := storage-handling-ai.exe

SRC_FILES := $(shell find $(SRC) -name '*.cpp')

INCLUDE := $(addprefix -I ,$(INCLUDE_DIRS))

$(shell mkdir -p $(BIN))

all: clean $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC_FILES)
	$(CXX) $(CXX_FLAGS) $(INCLUDE) $(LIB) $^ -o $@  $(LIBRARIES)

clean:
	-rm -f $(BIN)/*
