# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++17

# Include directories
INCLUDES = -I. -I./common -I./discount -I./io -I./shipping -I./shipping/shippingOption -I./transaction -I./validation

# Source files
SRCS = $(wildcard *.cpp) $(wildcard common/*.cpp) $(wildcard discount/*.cpp) $(wildcard io/*.cpp) $(wildcard shipping/*.cpp) $(wildcard shipping/shippingOption/*.cpp) $(wildcard transaction/*.cpp) $(wildcard validation/*.cpp)

# Header files
HDRS = $(wildcard *.h) $(wildcard common/*.h) $(wildcard discount/*.h) $(wildcard io/*.h) $(wildcard shipping/*.h) $(wildcard shipping/shippingOption/*.h) $(wildcard transaction/*.h) $(wildcard validation/*.h)

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = transaction_discounts

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^

%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@
