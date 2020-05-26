# Nathaniel Collier
# 2/2/2007
# Crazy8 Game Makefile
CC = g++

EXE_FILE = blackjack.exe

C_FLAGS =  -g3 -O0

L_FLAGS = 

C_FILES = blackjack.cpp 

H_FILES = 

LIB_DIR = $(NAC_LIB_DIR)
LIB_FILES = nstring nfunc ncolor
L_FILES := $(patsubst %, $(LIB_DIR)/lib%.a, $(LIB_FILES))

O_FILES := $(patsubst %.cpp,o/%.o,$(C_FILES))

all: 
	make -s $(EXE_FILE)

$(EXE_FILE): $(O_FILES)
	$(CC)  -o $(EXE_FILE) $(O_FILES) $(L_FILES) $(L_FLAGS)
	echo "Done compiling $(EXE_FILE).";
	chmod 777 $(EXE_FILE)
	chmod 777 $(O_FILES)

clean:
	rm -f $(O_FILES) $(EXE_FILE)

o/%.o: %.cpp
	echo "  Compiling $@....";
	$(CC) -c $(C_FLAGS) $< -o $@

