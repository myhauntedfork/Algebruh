ifeq ($(OS),Windows_NT)
    TARGET = $(BUILD_DIR)/algebruh.exe
else
    TARGET = $(BUILD_DIR)/algebruh
endif

CXX = g++
CXXFLAGS = -std=c++17 -Iinclude -Wall -Wextra -pedantic

SRC_DIR = src
SRC_MATH_DIR = Math
SRC_CHEM_DIR = Chemistry
INCLUDE_DIR = include
BUILD_DIR = build

# Correcting paths with slashes after folder variables
SRCS = $(SRC_DIR)/main.cpp \
       $(SRC_DIR)/$(SRC_MATH_DIR)/area.cpp \
       $(SRC_DIR)/$(SRC_MATH_DIR)/quadratic.cpp \
       $(SRC_DIR)/$(SRC_CHEM_DIR)/stoichiometry.cpp

# Adjusting object file generation to match corrected paths
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@) # Ensure subdirectories exist
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean
