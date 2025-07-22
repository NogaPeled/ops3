# Makefile for Part 2 – Dynamic Convex Hull with Profiling

CXX = g++
CXXFLAGS = -std=c++17 -Iinclude -Wall -Wextra -O2

# Source files and target executable
PART2_SRCS = src/main.cpp src/core/State.cpp src/geom/Hull.cpp
PART2_TARGET = ch_part2

.PHONY: all clean

all: $(PART2_TARGET)

$(PART2_TARGET): $(PART2_SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(PART2_TARGET) *.o

# Usage:
# To build Part 2:
#   make
#
# To run Part 2 with vector implementation test input:
#   ./ch_part2 < test_part2_vector.txt
#
# To run Part 2 with list implementation test input:
#   ./ch_part2 < test_part2_list.txt
#
# To clean binaries:
#   make clean
