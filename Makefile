# ==============================================================
# Makefile for the Maze Solver Project
# Authors: Afonso Azevedo, Aleksandar Mihajlovic, Luke Doherty

# Description:
#   This Makefile compiles both:
#     1. The Maze Solver executable (maze_solver)
#     2. The Maze Generator executable (maze_generator)
#   It also provides clean and run targets for convenience.

# Resources: YouTube videos, Google Search, ChatGPT by OpenAi, Google Gemini.
# ==============================================================


# --------------------------------------------------------------
# Compiler and Flags
# --------------------------------------------------------------

CC = gcc
CFLAGS = -Iinclude -Wall -Wextra
# -Iinclude   → add the "include" directory for header files
# -Wall       → enable common warnings
# -Wextra     → enable additional warnings


# --------------------------------------------------------------
# Source Files
# --------------------------------------------------------------

SRC_SOLVER = $(filter-out src/generate_maze.c, $(wildcard src/*.c))
# All source files except generate_maze.c (since that one has its own main())

SRC_GENERATOR = src/generate_maze.c
# Separate variable for the maze generator source file


# --------------------------------------------------------------
# Object Files
# --------------------------------------------------------------

OBJ_SOLVER = $(SRC_SOLVER:.c=.o)
OBJ_GENERATOR = $(SRC_GENERATOR:.c=.o)
# Each .c file becomes its .o version automatically


# --------------------------------------------------------------
# Executables
# --------------------------------------------------------------

EXEC_SOLVER = maze_solver
EXEC_GENERATOR = maze_generator
# Two different executables: one for solving, one for generating


# --------------------------------------------------------------
# Default Target (builds both programs)
# --------------------------------------------------------------

all: $(EXEC_SOLVER) $(EXEC_GENERATOR)
# When you type "make", both executables will be built


# --------------------------------------------------------------
# Build Rules
# --------------------------------------------------------------

$(EXEC_SOLVER): $(OBJ_SOLVER)
	$(CC) $(OBJ_SOLVER) -o $(EXEC_SOLVER)
# Links all solver object files into one executable

$(EXEC_GENERATOR): $(OBJ_GENERATOR)
	$(CC) $(OBJ_GENERATOR) -o $(EXEC_GENERATOR)
# Compiles and links the maze generator separately


# --------------------------------------------------------------
# Run Targets
# --------------------------------------------------------------

run: $(EXEC_SOLVER)
	./$(EXEC_SOLVER)
# Builds (if needed) and runs the solver

run-generator: $(EXEC_GENERATOR)
	./$(EXEC_GENERATOR)
# Builds (if needed) and runs the generator


# --------------------------------------------------------------
# Clean Target
# --------------------------------------------------------------

clean:
	rm -f $(OBJ_SOLVER) $(OBJ_GENERATOR) $(EXEC_SOLVER) $(EXEC_GENERATOR)
# Removes:
# - All object files (.o)
# - Both executables (maze_solver and maze_generator)
# Usage:
#   make clean


# --------------------------------------------------------------
# End of Makefile
# --------------------------------------------------------------
