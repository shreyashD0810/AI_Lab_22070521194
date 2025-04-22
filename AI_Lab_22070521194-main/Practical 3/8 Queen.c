#include <stdbool.h>
#include <stdio.h>

#define SIZE 8

void displayBoard(int chessboard[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", chessboard[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

bool isPositionSafe(int chessboard[SIZE][SIZE], int row, int col) {
    for (int i = 0; i < col; i++) {
        if (chessboard[row][i]) {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (chessboard[i][j]) {
            return false;
        }
    }
    for (int i = row, j = col; j >= 0 && i < SIZE; i++, j--) {
        if (chessboard[i][j]) {
            return false;
        }
    }
    return true;
}

bool placeQueens(int chessboard[SIZE][SIZE], int col) {
    if (col >= SIZE) {
        return true;
    }
    for (int i = 0; i < SIZE; i++) {
        if (isPositionSafe(chessboard, i, col)) {
            chessboard[i][col] = 1;
            if (placeQueens(chessboard, col + 1)) {
                return true;
            }
            chessboard[i][col] = 0;
        }
    }
    return false;
}

void solveQueensPuzzle() {
    int chessboard[SIZE][SIZE] = {0};
    if (!placeQueens(chessboard, 0)) {
        printf("No solution available.\n");
        return;
    }
    displayBoard(chessboard);
}

int main() {
    solveQueensPuzzle();
    return 0;
}
