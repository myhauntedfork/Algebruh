ifeq ($(OS),Windows_NT)
    TARGET = $(DIST_DIR)/algebruh.exe
else
    TARGET = $(DIST_DIR)/algebruh
endif

CXX = g++
CXXFLAGS = -std=c++17 -Iinclude -Wall -Wextra -pedantic

SRC_DIR = src
SRC_MATH_DIR = Math
SRC_CHEM_DIR = Chemistry
INCLUDE_DIR = include
OBJ_DIR = obj
DIST_DIR = dist

# Correct paths and organize object files in obj folder
SRCS = $(SRC_DIR)/main.cpp \
       $(SRC_DIR)/$(SRC_MATH_DIR)/area.cpp \
       $(SRC_DIR)/$(SRC_MATH_DIR)/quadratic.cpp \
       $(SRC_DIR)/$(SRC_CHEM_DIR)/stoichiometry.cpp

OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

all: $(OBJ_DIR) $(DIST_DIR) $(TARGET)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(DIST_DIR):
	mkdir -p $(DIST_DIR)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@) # Ensure subdirectories in obj exist
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(DIST_DIR)

.PHONY: all clean
