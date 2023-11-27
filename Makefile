CXX = g++
CXXFLAGS = -std=c++17 -Wall
SRCDIR = ChocAn
OBJDIR = obj
BINDIR = bin
TARGET = ChocAn

SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

all: $(BINDIR)/$(TARGET)

$(BINDIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	@mkdir -p $(BINDIR)/filesystem
	@cp $(SRCDIR)/providerDirectory.csv $(BINDIR)/filesystem
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: all clean