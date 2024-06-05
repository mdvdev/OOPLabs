ifeq ($(shell uname), Linux)
CC 	:= gcc
CXX := g++
else
CC 	:= clang
CXX	:= clang++
endif

SRC_DIR 	:= src
BUILD_DIR 	:= build
INCLUDE_DIR := include

CXXFLAGS := -g -Wall -Wextra -ansi -pedantic -std=c++20
CPPFLAGS := -I$(INCLUDE_DIR) -MMD

TARGET_EXEC := $(BUILD_DIR)/bstree

SRCMODULES := $(wildcard $(SRC_DIR)/*.cpp)
OBJMODULES := $(SRCMODULES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

.PHONY: clean all

all: $(TARGET_EXEC)

run: $(TARGET_EXEC)
	$(TARGET_EXEC)

$(TARGET_EXEC): $(OBJMODULES)
	mkdir -p $(BUILD_DIR)
	$(CXX) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

ifneq (clean, $(MAKECMDGOALS))
-include $(OBJMODULES:.o=.d)
endif

