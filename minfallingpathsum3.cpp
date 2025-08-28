#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to compute minimum falling path sum using tabulation
int getMinPathSum(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    // Base case: first row is the same as matrix first row
    for (int j = 0; j < m; j++) dp[0][j] = matrix[0][j];

    // Fill DP table
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int u = matrix[i][j] + dp[i - 1][j];

            int ld = matrix[i][j];
            if (j - 1 >= 0) ld += dp[i - 1][j - 1];
            else ld += 1e8; // invalid → large number

            int rd = matrix[i][j];
            if (j + 1 < m) rd += dp[i - 1][j + 1];
            else rd += 1e8; // invalid → large number

            dp[i][j] = min(u, min(ld, rd));
        }
    }

    // Answer = min value in last row
    int mini = 1e8;
    for (int j = 0; j < m; j++) {
        mini = min(mini, dp[n - 1][j]);
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
