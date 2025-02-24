CCFLAGS = -DMAP -Wall -Werror -std=c++11 -ansi
COMP = g++
EDL = g++
SRC = main.cpp Lexer.cpp Symbole.cpp Automate.cpp State.cpp 
OBJ = $(SRC:.cpp=.o)
EXE = exe
EFFACE = clean
RM = @rm
RMFLAGS = -f

$(EXE) : obj
	$(COMP) -o $(EXE) $(OBJ)

obj: $(SRC)
	$(COMP) -c $(SRC) $(CCFLAGS)

$(EFFACE):
	$(RM) $(RMFLAGS) $(OBJ) $(EXE) core

run : $(EXE)
	./$(EXE)

.PHONY : clean run


