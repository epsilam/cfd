CXX      := g++
CXXFLAGS := -Wall -std=c++2a
LIBS     := -pthread
SRCDIR   := src
OBJDIR   := obj
BINDIR   := bin
TARGET   := $(BINDIR)/main

# Filename extension of source files
SRCEXT   := cc

SOURCES  := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS  := $(patsubst $(SRCDIR)/%.$(SRCEXT),$(OBJDIR)/%.o,$(SOURCES))

# Link
$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CXX) $^ -o $(TARGET) $(LIBS)

# Compile source files
$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEXT) 
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -rf $(BINDIR) $(OBJDIR) $(VIDDIR)

run: $(TARGET)
	./$(TARGET)

debug: $(TARGET)
	valgrind ./$(TARGET)

# Video creation
VIDDIR   := vid
VID      := $(VIDDIR)/cfd.mkv

video: $(TARGET)
	@mkdir -p $(VIDDIR)
	echo "Creating video..."
	./$(TARGET) | ffmpeg -vcodec ppm -f image2pipe -i pipe:0 ./$(VID)
	echo "Video created"
