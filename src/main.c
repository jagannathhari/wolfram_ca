#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <raylib.h>
#define W 800
#define H 800

#define TITLE "Wolfram Celluar Automation"
#define SIZE 10
#define FPS 24

unsigned char get_state(unsigned char neiougher, unsigned char rule) {
    return (rule & (1 << (8 - neiougher - 1))) > 0;
}

void update_state(unsigned char *current_state, unsigned char *next_state,
                  int cols, int rule) {
    unsigned char neioughors;
    for (int i = 1; i <= cols; i++) {
        neioughors = 0;
        if (current_state[i - 1])
            neioughors = neioughors | 4;
        if (current_state[i])
            neioughors = neioughors | 2;
        if (current_state[i + 1])
            neioughors = neioughors | 1;
        next_state[i] = get_state(neioughors, rule);
    }
}

void random_fill(unsigned char *arr, int len) {
    for (int i = 1; i <= len; i++) {
        arr[i] = GetRandomValue(0, 1);
    }
}

int main() {

    int rows = H / SIZE;
    int cols = W / SIZE;
    int rule = 193;
    unsigned char **grid = malloc(sizeof(unsigned char *) * rows);
    unsigned char *state = calloc(cols + 2, sizeof(unsigned char));
    unsigned char *temp;
    for (int i = 0; i < rows; i++) {
        grid[i] = calloc(cols + 2, sizeof(unsigned char));
    }

    grid[rows - 1][cols] = 1;
    InitWindow(W, H, TITLE);
    SetTargetFPS(FPS);

    while (!WindowShouldClose()) {

        // Get random rule and fill random location
        if (IsKeyReleased(KEY_R)) {
            rule = GetRandomValue(0, 254);
            random_fill(grid[rows - 1], cols);
        }
        if (IsKeyReleased(KEY_J) && rule < 254) {
            ++rule;
            memset(grid[rows - 1], 0, sizeof(unsigned char) * cols + 2);
            grid[rows - 1][cols] = 1;
        }
        if (IsKeyReleased(KEY_K) && rule > 0) {
            memset(grid[rows - 1], 0, sizeof(unsigned char) * cols + 2);
            grid[rows - 1][cols] = 1;
            --rule;
        }

        ClearBackground(WHITE);
        BeginDrawing();
        for (int i = 0; i < rows; i++) {
            for (int j = 1; j <= cols; j++) {
                if (grid[i][j]) {
                    DrawRectangle((j - 1) * SIZE, i * SIZE, SIZE, SIZE, RED);
                }
            }
        }
        EndDrawing();

        update_state(grid[rows - 1], state, cols, rule);
        temp = grid[0];
        for (int i = 1; i < rows; i++) {
            grid[i - 1] = grid[i];
        }
        grid[rows - 1] = state;
        state = temp;
    }

    CloseWindow();
}
