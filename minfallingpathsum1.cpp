#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Recursive function to compute minimum falling path sum
int f(int i, int j, vector<vector<int>> &matrix) {
    if (j < 0 || j >= matrix[0].size()) return 1e8; // Out of bounds → return large positive
    if (i == 0) return matrix[0][j]; // Base case: first row
    
    int u = matrix[i][j] + f(i - 1, j, matrix);     // From above
    int ld = matrix[i][j] + f(i - 1, j - 1, matrix); // From left diagonal
    int rd = matrix[i][j] + f(i - 1, j + 1, matrix); // From right diagonal
    
    return min(u, min(ld, rd)); // Take minimum path
}

// Function to get minimum falling path sum
int getMinPathSum(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int mini = 1e8;

    // Try ending at every column in the last row
    for (int j = 0; j < m; j++) {
        mini = min(mini, f(n - 1, j, matrix));
    }
    return mini;
}

int main() {
    int n, m;
    cout << "Enter number of rows: ";
    cin >> n;
    cout << "Enter number of columns: ";
    cin >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    cout << "Enter the matrix elements row by row:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "\nThe matrix you entered:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int result = getMinPathSum(matrix);
    cout << "\nMinimum falling path sum: " << result << endl;

    return 0;
}
