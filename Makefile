CCFLAGS = -DMAP -Wall -Werror -std=c++11
COMP = g++
EDL = g++
SRC_DIR_APP = app
SRC_DIR_SRC = src
SRC = $(SRC_DIR_APP)/main.cpp $(SRC_DIR_SRC)/Lexer.cpp $(SRC_DIR_SRC)/Symbole.cpp $(SRC_DIR_SRC)/Automate.cpp $(SRC_DIR_SRC)/State.cpp
OBJ = $(SRC:.cpp=.o)
EXE = exe
EFFACE = clean
RM = @rm
RMFLAGS = -f

$(EXE): $(OBJ)
	$(COMP) -o $(EXE) $(OBJ)

%.o: %.cpp
	$(COMP) -c $< -o $@ $(CCFLAGS)

$(EFFACE):
	$(RM) $(RMFLAGS) $(OBJ) $(EXE) core

run: $(EXE)
	./$(EXE)

.PHONY: clean run



