CXX       := g++
CXX_FLAGS := -std=c++17 -ggdb

BIN     := bin
SRC     := src
INCLUDE := -I include \
		-I include/crossers \
		-I include/crossSelectors \
		-I include/mutators \
		-I lib

LIBRARIES   :=
EXECUTABLE  := storage-handling-ai.exe


all: clean $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) $(INCLUDE) $^ -o $@  $(LIBRARIES)

clean:
	-rm $(BIN)/*
