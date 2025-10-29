#include <stdio.h>
#include "maze.h"

// =========================================
// loadMaze()
// Reads a maze from a text file and stores it in a Maze struct
// Returns 1 if successful, 0 if an error occurs
// =========================================
int loadMaze(const char *filename, Maze *maze) {
    FILE *file = fopen(filename, "r");  // Open the file in read mode
    if (!file) {
        perror("Error opening maze file");  // Print system error message
        return 0;
    }

    maze->rows = 0;
    char line[MAX_COLS];  // Buffer for reading each line

    // Read the maze file line by line
    while (fgets(line, sizeof(line), file)) {
        int col = 0;

        // Read each character in the current line
        for (; line[col] != '\n' && line[col] != '\0'; col++) {
            maze->grid[maze->rows][col] = line[col];  // Store character in maze grid

            // Detect the start (S) and goal (G) positions
            if (line[col] == 'S') {
                maze->startRow = maze->rows;
                maze->startCol = col;
            } else if (line[col] == 'G') {
                maze->goalRow = maze->rows;
                maze->goalCol = col;
            }
        }

        // Store the number of columns and increase row count
        maze->cols = col;
        maze->rows++;
    }

    fclose(file);  // Close the file after reading
    return 1;      // Indicate success
}

// =========================================
// printMaze()
// Prints the maze grid to the terminal
// =========================================
void printMaze(const Maze *maze) {
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++)
            putchar(maze->grid[i][j]);  // Print each cell
        putchar('\n');  // Newline after each row
    }
}
