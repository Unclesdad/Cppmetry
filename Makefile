CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic
DBGFLAGS := -g -O0 -DDEBUG
RELFLAGS := -O2 -DNDEBUG

# Directories
SRC_DIR      := src
INC_DIR      := include
TEST_DIR     := tests
BUILD_DIR    := build
OBJ_DIR      := $(BUILD_DIR)/obj
TEST_OBJ_DIR := $(BUILD_DIR)/test_obj
BIN_DIR      := $(BUILD_DIR)/bin

# Targets
TARGET      := $(BIN_DIR)/cppmetry
TEST_TARGET := $(BIN_DIR)/run_tests

# Sources
# main.cpp excluded so tests can link cleanly
ALL_SRCS  := $(wildcard $(SRC_DIR)/*.cpp)
MAIN_SRC  := $(filter $(SRC_DIR)/main.cpp, $(ALL_SRCS))
LIB_SRCS  := $(filter-out $(SRC_DIR)/main.cpp, $(ALL_SRCS))

LIB_OBJS  := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(LIB_SRCS))
MAIN_OBJ  := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(MAIN_SRC))

TEST_SRCS := $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS := $(patsubst $(TEST_DIR)/%.cpp, $(TEST_OBJ_DIR)/%.o, $(TEST_SRCS))

DEPS := $(LIB_OBJS:.o=.d) $(MAIN_OBJ:.o=.d) $(TEST_OBJS:.o=.d)

# GTest via pkg-config
GTEST_CFLAGS := $(shell pkg-config --cflags gtest_main)
GTEST_LIBS   := $(shell pkg-config --libs gtest_main)

INCLUDES := -I$(INC_DIR)

# Phony targets
.PHONY: all build test clean debug release

all: build test

# Main binary
build: $(TARGET)

$(TARGET): $(LIB_OBJS) $(MAIN_OBJ) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

# Tests
test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(LIB_OBJS) $(TEST_OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ $(GTEST_LIBS) -o $@

$(TEST_OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp | $(TEST_OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(GTEST_CFLAGS) -MMD -MP -c $< -o $@

# Convenience variants
debug: CXXFLAGS += $(DBGFLAGS)
debug: all

release: CXXFLAGS += $(RELFLAGS)
release: all

# Directory creation
$(OBJ_DIR) $(TEST_OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

# Clean
clean:
	rm -rf $(BUILD_DIR)

-include $(DEPS)
