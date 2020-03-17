SRC_DIR := ./src
OBJ_DIR := ./obj
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
LDFLAGS := -L.\libraries\lib -I.\libraries\include -lfreeglut -lopengl32 -lgdi32 -lglu32

assignment1.exe: $(SRC_FILES)
	echo $(SRC_FILES)
	g++ -o $@ $^ $(LDFLAGS)
