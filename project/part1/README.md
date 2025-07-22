# Makefile for Part 1 – Convex Hull Static Implementation

CXX = g++
CXXFLAGS = -std=c++17 -Iinclude -Wall -Wextra -O2

# Source files and target executable
PART1_SRCS = src/main.cpp src/geom/Hull.cpp
PART1_TARGET = ch_part1

.PHONY: all clean

all: $(PART1_TARGET)

$(PART1_TARGET): $(PART1_SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(PART1_TARGET) *.o

# Usage:
# To build Part 1:
#   make
#
# To run Part 1 with input file:
#   ./ch_part1 < test_part1.txt
#
# To clean binaries:
#   make clean