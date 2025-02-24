CXX = g++
CXXFLAGS = -Iheaders -Wall -std=c++17 -O3 -g -Wno-sign-compare

SRC_DIR = src
APP_DIR = app
OBJ_DIR = obj
BIN_DIR = bin
RES_DIR = resources

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
APP_SOURCES = $(wildcard $(APP_DIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
APP_OBJECTS = $(APP_SOURCES:$(APP_DIR)/%.cpp=$(OBJ_DIR)/%.o)
EXECUTABLE = $(BIN_DIR)/executable
RESOURCES = 

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(APP_OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(OBJECTS) $(APP_OBJECTS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(APP_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

run: $(EXECUTABLE)
	./$(EXECUTABLE) $(RESOURCES)

rebuild_run: clean all run

lldb: $(EXECUTABLE)
	lldb ./$(EXECUTABLE) $(RESOURCES)

.PHONY: clean all run