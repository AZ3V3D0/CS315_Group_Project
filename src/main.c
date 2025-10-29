#include <stdio.h>
#include "maze.h"
#include "dfs.h"   // <-- add this

int main(void) {
    Maze maze;

    if (!loadMaze("mazes/maze5.txt", &maze)) {
        return 1;
    }

    printf("Maze loaded successfully!\n\n");
    printMaze(&maze);

    printf("\nStart: (%d, %d)\n", maze.startRow, maze.startCol);
    printf("Goal:  (%d, %d)\n", maze.goalRow, maze.goalCol);

    // Run DFS and show metrics / path
    solveMazeDFS(&maze);

    return 0;
}
