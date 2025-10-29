#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random maze
void generateMaze(int width, int height, float wallDensity, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error creating maze file");
        return;
    }

    srand(time(NULL)); // Seed randomness with current time

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Create border walls around the maze
            if (y == 0 || y == height - 1 || x == 0 || x == width - 1) {
                fputc('#', file);
            } else {
                // Randomly choose between wall or open path
                float r = (float)rand() / RAND_MAX;
                if (r < wallDensity)
                    fputc('#', file);
                else
                    fputc('.', file);
            }
        }
        fputc('\n', file);
    }

    // Place Start (S) and Goal (G)
    int startRow = 1;
    int startCol = 1;
    int goalRow = height - 2;
    int goalCol = width - 2;

    // Reopen file to overwrite start/goal positions
    fclose(file);
    file = fopen(filename, "r+");

    int indexS = startRow * (width + 1) + startCol; // +1 for newline
    int indexG = goalRow * (width + 1) + goalCol;

    fseek(file, indexS, SEEK_SET);
    fputc('S', file);

    fseek(file, indexG, SEEK_SET);
    fputc('G', file);

    fclose(file);
    printf("Maze generated and saved to %s\n", filename);
}

// Example usage
int main() {
    generateMaze(9, 7, 0.2, "mazes/maze1.txt");    // Small
    generateMaze(15, 15, 0.25, "mazes/maze2.txt"); // Medium
    generateMaze(25, 25, 0.3, "mazes/maze3.txt");  // Big
    generateMaze(60, 60, 0.35, "mazes/maze4.txt"); // Really Big
    return 0;
}
