CC = gcc
CFLAGS = -Iinclude -Wall -Wextra
SRC = $(filter-out src/generate_maze.c, $(wildcard src/*.c))
OBJ = $(SRC:.c=.o)
EXEC = maze_solver

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

run: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(OBJ) $(EXEC)
