#include <stdio.h>
#include "maze.h"

// =========================================
// Main Function
// Loads a maze from file and prints it on the screen
// =========================================
int main(void) {
    Maze maze;  // Declare a Maze struct instance

    // Attempt to load the maze file
    if (!loadMaze("mazes/maze4.txt", &maze)) {
        return 1; // Exit if file cannot be read
    }

    // Confirm success and display maze
    printf("✅ Maze loaded successfully!\n\n");
    printMaze(&maze);

    // Display start and goal coordinates
    printf("\nStart: (%d, %d)\n", maze.startRow, maze.startCol);
    printf("Goal:  (%d, %d)\n", maze.goalRow, maze.goalCol);

    return 0;
}
