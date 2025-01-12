ifeq ($(OS),Windows_NT)
    TARGET = $(BUILD_DIR)/algebruh.exe
else
    TARGET = $(BUILD_DIR)/algebruh
endif

CXX = g++
CXXFLAGS = -std=c++17 -Iinclude -Wall -Wextra -pedantic

SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

SRCS = main.cpp $(SRC_DIR)/area.cpp $(SRC_DIR)/quadratic.cpp $(SRC_DIR)/stoichiometry.cpp

OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean
