# Makefile

# Compiler

CXX = g++

# Compiler flags

CXXFLAGS = -std=c++11 -Wall -Wextra

# Executable name

TARGET = ZooKeeper

# Source files

SRCS = main.cpp Zoo.cpp Kangaroo.cpp Panda.cpp Animal.cpp Zookeeper.cpp Staff.cpp Person.cpp 

# Build and run tests

.PHONY: all

all:

    $(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

    ./$(TARGET)

# Clean rule

.PHONY: clean

clean:

    rm -f $(TARGET)