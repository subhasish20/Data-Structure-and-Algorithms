#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Initialize a 3x3 matrix (3 rows, 3 columns)
    vector<vector<int>> matrix(3, vector<int>(3));

    // Optionally, fill it with values
    // For example, filling it with values 1-9 in row-major order
    int value = 1;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrix[i][j] = value++;
        }
    }

    // Display the matrix
    cout << "The 3x3 matrix is:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
