#include<stdio.h>

#define N 4 // board size and no of queen

// Function to check if placing a queen at board[row][col] is safe
int isSafe(char board[N][N], int row, int col) {
    int i, j;

    // Check column above
    for (i = 0; i < row; i++) {
        if (board[i][col] == 'Q')
            return 0;
    }

    // Check upper-left diagonal
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q')
            return 0;
    }

    // Check upper-right diagonal
    for (i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 'Q')
            return 0;
    }

    return 1; // Safe position
}

// Function to print the board
void printBoard(char board[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Recursive function to solve N-Queen problem
void solveNQueen(char board[N][N], int row) {
    // Base case: All queens placed
    if (row == N) {
        printBoard(board);
        return;
    }

    int col;
    for (col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 'Q'; // Place queen
            solveNQueen(board, row + 1); // Recurse for next row
            board[row][col] = '*'; // Backtrack
        }
    }
}

int main() {
    char board[N][N];
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            board[i][j] = '*';
        }
    }

    // Solve N-Queen
    solveNQueen(board, 0);
    return 0;
}