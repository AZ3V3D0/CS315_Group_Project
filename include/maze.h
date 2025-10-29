#ifndef MAZE_H
#define MAZE_H

// =========================================
// Maze Header File
// Defines the Maze data structure and function prototypes
// =========================================

// Define the maximum allowed maze dimensions
#define MAX_ROWS 700
#define MAX_COLS 700

// Structure that stores the maze grid and useful metadata
typedef struct {
    char grid[MAX_ROWS][MAX_COLS];  // 2D array representing maze layout
    int rows;                       // Total number of rows
    int cols;                       // Total number of columns
    int startRow, startCol;         // Starting position (S)
    int goalRow, goalCol;           // Goal position (G)
} Maze;

// Function prototypes
// Loads a maze from a text file into the Maze struct
int loadMaze(const char *filename, Maze *maze);

// Prints the maze to the terminal
void printMaze(const Maze *maze);

#endif
