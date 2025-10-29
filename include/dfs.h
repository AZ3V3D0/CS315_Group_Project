#ifndef DFS_H
#define DFS_H

#include "maze.h"

/*
 * solveMazeDFS
 *  - Runs a Depth-First Search from S to G on the given maze.
 *  - Marks the discovered path with '*' (S and G are preserved).
 *  - Prints performance metrics (cells visited, elapsed time).
 *  - Returns 1 if a path is found, 0 otherwise.
 */
int solveMazeDFS(Maze *maze);

#endif
