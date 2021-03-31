# arguments when calling make run
RUNARGS :=

CXX := g++
CXXFLAGS := -Wall -std=c++2a
LIBS := -pthread
SRCDIR := src
OBJDIR := obj
BINDIR := bin
TARGET := $(BINDIR)/main

# filename extension of source files
SRCEXT := cc

SOURCES := $(wildcard $(SRCDIR)/*.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%.$(SRCEXT),$(OBJDIR)/%.o,$(SOURCES))

# Link
$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CXX) $^ -o $(TARGET) $(LIBS)

# Compile source files
$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -rf $(BINDIR) $(OBJDIR)

run: $(TARGET)
	./$(TARGET) $(RUNARGS)

debug: $(TARGET)
	valgrind ./$(TARGET) $(RUNARGS)
