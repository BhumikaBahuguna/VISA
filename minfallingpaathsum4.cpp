#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to compute minimum falling path sum using space optimization
int getMinPathSum(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> prev(m, 0), cur(m, 0);

    // Base case: first row
    for (int j = 0; j < m; j++) prev[j] = matrix[0][j];

    // Build row by row
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int u = matrix[i][j] + prev[j];

            int ld = matrix[i][j];
            if (j - 1 >= 0) ld += prev[j - 1];
            else ld += 1e8;

            int rd = matrix[i][j];
            if (j + 1 < m) rd += prev[j + 1];
            else rd += 1e8;

            cur[j] = min(u, min(ld, rd));
        }
        prev = cur; // move current row to previous
    }

    // Answer = min element in last row
    int mini = 1e8;
    for (int j = 0; j < m; j++) {
        mini = min(mini, prev[j]);
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
