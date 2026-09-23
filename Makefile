CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

BUILD_DIR = build
TARGET = $(BUILD_DIR)/project1

SRCS = main.cpp config.cpp node.cpp
OBJS = $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

$(BUILD_DIR)/%.o: %.cpp config.hpp node.hpp nodeinfo.hpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: clean