# Compiler
CXX = g++

# Directories
INCLUDE_DIR = include
SRC_DIR = src

# Files
MAIN = main.cpp
SOURCES = $(SRC_DIR)/sorting.cpp
EXECUTABLE = sorting

# Compilation flags
CXXFLAGS = -I$(INCLUDE_DIR)

# Build target
$(EXECUTABLE): $(MAIN) $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) $(MAIN) $(SOURCES)

# Clean target
clean:
	rm -f $(EXECUTABLE)
