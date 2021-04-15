CXX      := g++
CXXFLAGS := -Wall -std=c++2a
LIBS     := -pthread
SRCDIR   := src
OBJDIR   := obj
BINDIR   := bin
TARGET   := $(BINDIR)/main
ERRLOG   := errorlog.txt

# Video directory, name, and filename extension
VIDDIR   := vid
VIDNAME  := cfdvideo
VIDEXT   := mkv

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
	rm -rf $(BINDIR) $(OBJDIR) $(ERRLOG)

cleanvid:
	rm -rf $(VIDDIR)

run: $(TARGET)
	./$(TARGET)

debug: $(TARGET)
	valgrind ./$(TARGET)

# Video creation
video: $(TARGET)
	@mkdir -p $(VIDDIR)
	@echo "Creating video..."
	$(eval VIDFILE := $(VIDDIR)/$(VIDNAME)$(shell date +'_%y.%m.%d_%H:%M:%S').$(VIDEXT))
	./$(TARGET) 2> $(ERRLOG) | ffmpeg -vcodec ppm -f image2pipe -i pipe:0 ./$(VIDFILE)
	@echo "Video created"
