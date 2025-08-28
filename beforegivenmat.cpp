// C++ code to Compute before Matrix using user input
#include <bits/stdc++.h>
using namespace std;

// Function to compute before matrix
vector<vector<int>> computeBeforeMatrix(vector<vector<int>>& after) {
    int n = after.size(), m = after[0].size();
    
    // Declaring a 2d array to store
    // the values of the before Matrix
    vector<vector<int>> before(n, vector<int>(m, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0)
                before[0][0] = after[0][0];
            else if (i == 0)
                before[i][j] = after[i][j] - after[i][j - 1];
            else if (j == 0)
                before[i][j] = after[i][j] - after[i - 1][j];
            else
                before[i][j] = after[i][j] + after[i - 1][j - 1]
                              - after[i - 1][j] - after[i][j - 1];
        }
    }
    return before;
}

int main() {
    int n, m;
    cin >> n >> m; // user gives size of matrix
    
    vector<vector<int>> after(n, vector<int>(m));
    
    // Taking input for after[][] matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> after[i][j];
        }
    }
    
    // Computing before matrix
    vector<vector<int>> ans = computeBeforeMatrix(after);
    
    // Printing before matrix
    for (auto u : ans) {
        for (int x : u)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
