# ==============================
#   PC Control Project Makefile
# ==============================

# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -I Command/inc -I Server/inc -I ActionHandler/inc -I ResponseGenerator/inc -I Logging/inc

# Directories
SRC_DIRS := Server/src Command/src ActionHandler/src ResponseGenerator/src Logging/src
OBJ_DIR := build

# Target executable
TARGET := out

# Source files
SRCS := $(wildcard $(addsuffix /*.cpp, $(SRC_DIRS))) main.cpp
OBJS := $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(notdir $(SRCS)))

# Default rule
all: $(TARGET)

# Link all object files
$(TARGET): $(OBJS)
	@echo "Linking..."
	$(CXX) $(OBJS) -o $(TARGET)
	@echo "✅ Build complete: $(TARGET)"

# Compile source files from subdirectories
$(OBJ_DIR)/%.o: */src/%.cpp | $(OBJ_DIR)
	@echo "Compiling $< ..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile main.cpp separately
$(OBJ_DIR)/main.o: main.cpp | $(OBJ_DIR)
	@echo "Compiling main.cpp ..."
	$(CXX) $(CXXFLAGS) -c main.cpp -o $(OBJ_DIR)/main.o

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean build artifacts
clean:
	rm -rf $(OBJ_DIR) $(TARGET)
	@echo "🧹 Cleaned up build files."
