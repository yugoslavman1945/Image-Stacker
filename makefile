# Makefile for Image Stacker Project

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

# Executable name
TARGET = image_stacker

# Source files
SRCS = main.cpp stacker.cpp
OBJS = $(SRCS:.cpp=.o)

# Default rule
all: $(TARGET)

$(TARGET): $(OBJS)
$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
$(CXX) $(CXXFLAGS) -c $&lt;

run: $(TARGET)
./$(TARGET)

clean:
rm -f $(TARGET) *.o
