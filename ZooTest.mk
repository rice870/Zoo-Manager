# Makefile

# Compiler

CXX = g++

# Compiler flags

CXXFLAGS = -std=c++11 -Wall -Wextra

# Executable name

TARGET = zookeeper

# Source files

SRCS = ZooTest.cpp Zoo.cpp Animal.cpp Panda.cpp Enclosure.cpp Facility.cpp Person.cpp Visitor.cpp 

# Build and run tests

.PHONY: all

all:

	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET) 

	./$(TARGET)

# Clean rule

.PHONY:
	clean

clean:

	rm -f $(TARGET)]