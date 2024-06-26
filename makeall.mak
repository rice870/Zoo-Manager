# Makefile

# Compiler

CXX = g++

# Compiler flags

CXXFLAGS = -std=c++11 -Wall -Wextra

# Executable name

TARGET = zookeeper

# Source files

SRCS = main.cpp Zoo.cpp Enclosure.cpp Facility.cpp Panda.cpp Animal.cpp Visitor.cpp Person.cpp Staff.cpp Zookeeper.cpp Kangaroo.cpp Tortoise.cpp Elephant.cpp kiwi.cpp TicketTaker.cpp DrinkShop.cpp


# Build and run tests

.PHONY: all

all:

	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)
	./$(TARGET)

# Clean rule

.PHONY: clean

clean:

	rm -f $(TARGET)