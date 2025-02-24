CCFLAGS = -DMAP -Wall -Werror -std=c++11 # -ansi
COMP = g++
EDL = g++
SRC = $(wildcard src/*.cpp) app/main.cpp
OBJ = $(SRC:.cpp=.o)
EXE = exe
EFFACE = clean
RM = @rm
RMFLAGS = -f

$(EXE): $(OBJ)
	$(COMP) -o $(EXE) $(OBJ)

$(OBJ): %.o: %.cpp 
	$(COMP) $(CCFLAGS) -c $< -o $@

$(EFFACE):
	$(RM) $(RMFLAGS) $(OBJ) $(EXE) core

run: $(EXE)
	./$(EXE)

.PHONY: clean run
