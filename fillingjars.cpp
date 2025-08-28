long long solve(int n, vector<vector<int>> operations) {
    int s = operations.size();
    long long sum = 0;
    for (int i = 0; i < s; i++) {
        long long r1 = operations[i][0];
        long long r2 = operations[i][1];
        long long x  = operations[i][2];
        sum += (r2 - r1 + 1) * x;
    }
    return sum / n; // integer division is fine (problem wants floor avg)
}
