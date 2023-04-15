CC = g++
CFLAGS = -std=c++17 -Wall -Wextra
CPPFLAGS = -Iinclude
LDFLAGS = -Llib
LDLIBS = -lm

TARGET = myapp
SRCDIR = src
BUILDDIR = build

SRCS = $(shell find $(SRCDIR) -name '*.cpp')
OBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.cpp=.o))

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(BUILDDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@
