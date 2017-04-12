CXX = g++ -std=c++11
CXXFLAGS = -O3 -Wshadow -Wall -Wextra -Wno-uninitialized -Wno-sign-compare
LDFLAGS =

SRCDIR = sources
OBJDIR = build
BINDIR = .

SRC = $(wildcard $(SRCDIR)/*.cc)
#INC = $(wildcard $(SRCDIR)/*.h)
OBJ = $(SRC:$(SRCDIR)/%.cc=$(OBJDIR)/%.o)
TARGET = cryptohash.exe

all: $(BINDIR)/$(TARGET)  generator

$(BINDIR)/$(TARGET) : $(OBJ)
	mkdir -p $(BINDIR)
	$(CXX) -o $(BINDIR)/$(TARGET) $(LDFLAGS) $(OBJ)
	@echo "Linking complete !"

$(OBJ): $(OBJDIR)/%.o : $(SRCDIR)/%.cc
	mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"


debug: CXXFLAGS += -D_GLIBCXX_DEBUG -pg
debug: $(BINDIR)/$(TARGET)

GENSRC = $(wildcard $(SRCDIR)/generator/*.cc)
generator: $(GENSRC)
	$(CXX) -o $(BINDIR)/gen.exe $<

clean:
	rm $(OBJ)
	@echo "Cleanup complete!"

remove: 
	rm $(BINDIR)/$(TARGET) gen.exe
	@echo "Executable removed!"
