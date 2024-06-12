# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra

# Target executable names
TARGET1 = pt_1
TARGET2 = pt_2
TARGET3 = pt_3_4_5

# Source file paths
SRC_DIR = bfs_dfs_algorithms
SOURCES1 = $(SRC_DIR)/pt_1.cpp $(SRC_DIR)/data_structures.cpp
SOURCES2 = $(SRC_DIR)/pt_2.cpp $(SRC_DIR)/data_structures.cpp
SOURCES3 = $(SRC_DIR)/pt_3_4_5.cpp $(SRC_DIR)/data_structures.cpp

# Object files
OBJECTS1 = $(SOURCES1:.cpp=.o)
OBJECTS2 = $(SOURCES2:.cpp=.o)
OBJECTS3 = $(SOURCES3:.cpp=.o)

# Header files
HEADERS = $(SRC_DIR)/data_structures.h

# Default target
all: $(TARGET1) $(TARGET2) $(TARGET3)

# Rule to build the first target
$(TARGET1): $(OBJECTS1)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to build the second target
$(TARGET2): $(OBJECTS2)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to build the third target
$(TARGET3): $(OBJECTS3)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to build object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove generated files
clean:
	rm -f $(TARGET1) $(TARGET2) $(TARGET3) $(OBJECTS1) $(OBJECTS2) $(OBJECTS3)

# Phony targets
.PHONY: all clean
