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
all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(INC) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)

