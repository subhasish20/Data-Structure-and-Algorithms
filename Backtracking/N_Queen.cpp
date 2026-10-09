
#include <iostream>
using namespace std;

constexpr int N = 4;

// Check whether placing a queen at board[row][col] is safe.
bool isSafe(const char board[N][N], int row, int col) {
    // Check the column above the current position.
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }

    // Check the upper-left diagonal.
    for (int i = row - 1, j = col - 1;
         i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    // Check the upper-right diagonal.
    for (int i = row - 1, j = col + 1;
         i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

// Print the chessboard.
void printBoard(const char board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

// Solve the N-Queens problem using backtracking.
void solveNQueen(char board[N][N], int row, int& count) {
    // All queens have been placed successfully.
    if (row == N) {
        cout << "Solution " << ++count << ":\n";
        printBoard(board);
        return;
    }

    // Try placing a queen in each column of this row.
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 'Q';  // Place the queen.

            solveNQueen(board, row + 1, count);

            board[row][col] = '*';  // Backtrack.
        }
    }
}

int main() {
    char board[N][N];
    int count = 0;

    // Initialize every cell as empty.
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = '*';
        }
    }

    // Start placing queens from the first row.
    solveNQueen(board, 0, count);

    cout << "Total solutions: " << count << '\n';

    return 0;
}
