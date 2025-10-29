#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WALL '#'
#define PATH '.'

int dirs[4][2] = { {0,2}, {0,-2}, {2,0}, {-2,0} };

void carve(int y, int x, int h, int w, char maze[h][w]) {
    int order[4] = {0,1,2,3};
    for (int i=0; i<4; i++) { // randomize directions
        int j = rand()%4;
        int tmp = order[i]; order[i] = order[j]; order[j] = tmp;
    }

    for (int i=0; i<4; i++) {
        int ny = y + dirs[order[i]][0];
        int nx = x + dirs[order[i]][1];

        if (ny>0 && ny<h-1 && nx>0 && nx<w-1 && maze[ny][nx]==WALL) {
            maze[y + dirs[order[i]][0]/2][x + dirs[order[i]][1]/2] = PATH;
            maze[ny][nx] = PATH;
            carve(ny, nx, h, w, maze);
        }
    }
}

void generateMaze(int w, int h, const char *filename) {
    char maze[h][w];
    for (int y=0; y<h; y++)
        for (int x=0; x<w; x++)
            maze[y][x] = WALL;

    srand(time(NULL));
    maze[1][1] = PATH;
    carve(1, 1, h, w, maze);

    maze[1][1] = 'S';
    maze[h-2][w-2] = 'G';

    FILE *f = fopen(filename, "w");
    for (int y=0; y<h; y++) {
        for (int x=0; x<w; x++)
            fputc(maze[y][x], f);
        fputc('\n', f);
    }
    fclose(f);
    printf("Complex maze saved to %s\n", filename);
}

int main() {
    generateMaze(9,7,"mazes/maze1.txt");
    generateMaze(15,15,"mazes/maze2.txt");
    generateMaze(25,25,"mazes/maze3.txt");
    generateMaze(61,61,"mazes/maze4.txt");
    generateMaze(601,601,"mazes/maze5.txt"); // HUGE maze
    return 0;
}
