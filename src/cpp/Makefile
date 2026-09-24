# Cross-platform GNU Make build for Linux, MinGW, and MSYS2.
# Requires a C++23 compiler with <print> support (for example GCC 14+ or
# a recent Clang/libc++ installation).

CXX ?= c++
CPPFLAGS ?=
CXXFLAGS ?= -std=c++23 -Wall -Wextra -pedantic
LDFLAGS ?=
LDLIBS ?=

PROGRAM := ezprompt

ifeq ($(OS),Windows_NT)
  TARGET := $(PROGRAM).exe
  RM := del /Q
else
  TARGET := $(PROGRAM)
  RM := rm -f
endif

.PHONY: all clean run

all: $(TARGET)

$(TARGET): main.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)

main.o: main.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	-$(RM) main.o $(TARGET)
