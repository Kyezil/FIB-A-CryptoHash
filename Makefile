CXX = g++
CXXFLAGS = -O3 -Wshadow -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare
LDFLAGS =

SRCDIR = sources
OBJDIR = build
BINDIR = .

SRC = $(wildcard $(SRCDIR)/*.cc)
#INC = $(wildcard $(SRCDIR)/*.h)
OBJ = $(SRC:$(SRCDIR)/%.cc=$(OBJDIR)/%.o)
TARGET = cryptohash.exe


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

clean:
	rm $(OBJ)
	@echo "Cleanup complete!"

remove: clean
	rm $(BINDIR)/$(TARGET)
	@echo "Executable removed!"
