#include <stdio.h>
#include <time.h>      // clock(), CLOCKS_PER_SEC
#include "maze.h"
#include "dfs.h"

static int in_bounds(const Maze *m, int r, int c) {
    return r >= 0 && r < m->rows && c >= 0 && c < m->cols;
}

static int passable(const Maze *m, int r, int c) {
    char ch = m->grid[r][c];
    return (ch == '.' || ch == 'S' || ch == 'G');
}

/*
 * Recursive DFS helper:
 *  - visited: 2D int array (0/1) to avoid revisiting cells
 *  - visited_count: increments each time we VISIT a new cell
 *  - When it backtracks along a successful route, it writes '*'
 *    into the maze grid (but never overwrites S or G).
 */
static int dfs_util(Maze *m, int r, int c, int visited[MAX_ROWS][MAX_COLS], long *visited_count) {
    if (!in_bounds(m, r, c) || !passable(m, r, c)) return 0;
    if (visited[r][c]) return 0;

    visited[r][c] = 1;
    (*visited_count)++;

    // Goal check
    if (r == m->goalRow && c == m->goalCol) {
        return 1; // found G
    }

    // 4-directional moves: Up, Right, Down, Left
    static const int dr[4] = {-1, 0, 1,  0};
    static const int dc[4] = { 0, 1, 0, -1};

    for (int k = 0; k < 4; k++) {
        int nr = r + dr[k], nc = c + dc[k];
        if (dfs_util(m, nr, nc, visited, visited_count)) {
            // On the way back (only along the successful branch), mark path
            if (!(r == m->startRow && c == m->startCol) && !(r == m->goalRow && c == m->goalCol)) {
                m->grid[r][c] = '*';
            }
            return 1;
        }
    }

    return 0; // dead end
}

int solveMazeDFS(Maze *maze) {
    // Safety checks
    if (!in_bounds(maze, maze->startRow, maze->startCol) || !in_bounds(maze, maze->goalRow,  maze->goalCol)) {
        fprintf(stderr, "[DFS] Invalid start/goal coordinates.\n");
        return 0;
    }

    int visited[MAX_ROWS][MAX_COLS] = {0};
    long visited_count = 0;

    clock_t t0 = clock();
    int found = dfs_util(maze, maze->startRow, maze->startCol, visited, &visited_count);
    clock_t t1 = clock();

    double elapsed_sec = (double)(t1 - t0) / CLOCKS_PER_SEC;

    // Report
    if (found) {
        printf("\n[DFS] Maze with path (*):\n");
        printMaze(maze);
    }

    printf("\n-------------------------------------------\n");
    printf("[DFS] Result: %s\n", found ? "PATH FOUND" : "NO PATH");
    printf("[DFS] Cells visited: %ld\n", visited_count);
    printf("[DFS] Time: %.6f s\n", elapsed_sec);
    printf("-------------------------------------------\n");

    return found;
}
