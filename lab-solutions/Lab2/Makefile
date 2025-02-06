# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Iheaders
LDFLAGS = -lm

# Directories
SRC_DIR = src
MAIN_DIR = main
HEADERS_DIR = headers

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
MAIN_SRCS = $(wildcard $(MAIN_DIR)/Task*.cpp)
OBJS = $(SRCS:.cpp=.o)

# Targets (executables for each main file)
TARGETS = $(MAIN_SRCS:.cpp=)

# Default target (builds all tasks)
all: $(TARGETS)

# Rule to build a specific task (e.g., make Task1)
%: $(MAIN_DIR)/%.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $< $(OBJS) $(LDFLAGS)

# Rule to build object files from src/
$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS_DIR)/%.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJS) $(TARGETS)

.PHONY: all clean