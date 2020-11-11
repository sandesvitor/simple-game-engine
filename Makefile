BIN := game
SRCDIR := ./src
OBJDIR := ./obj
SRCFILES := $(wildcard $(SRCDIR)/*.cpp) $(wildcard &(SRCDIR)/*/*.cpp)
OBJFILES := $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCFILES))
LDFlAGS := -lSDL2 -lSDL2_image
CPPFLAGS := -std=c++14 -m64 -g -Wall -I .
CXXFLAGS :=

$(BIN): $(OBJFILES)
	@echo "==============================="
	@echo "Linking the target $@"
	@echo "==============================="
	g++ -o $@ $^ $(LDFlAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	g++ -c $(CPPFLAGS) -o $@ $<


clean:
	@echo "==============================="
	@echo "Removing .o files and $(BIN)"
	@echo "==============================="
	rm obj/*o $(BIN)