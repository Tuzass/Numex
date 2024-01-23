# Compiler options
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Directories
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

# Source files
SRC = $(wildcard $(SRC_DIR)/*.cpp)

# Object files
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Include directories
INC = -I$(INC_DIR)

# Target executable
TARGET = $(BIN_DIR)/numex

# Build rule
all: create_dirs $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(INC) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

# Rule to create obj and bin directories
create_dirs:
	@if not exist $(OBJ_DIR) @mkdir $(OBJ_DIR)
	@if not exist $(BIN_DIR) @mkdir $(BIN_DIR)

# Clean rule
clean:
	@if exist "$(OBJ_DIR)" rmdir /Q /S "$(OBJ_DIR)"
	@if exist "$(BIN_DIR)" rmdir /Q /S "$(BIN_DIR)"