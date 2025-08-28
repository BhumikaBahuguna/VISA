#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubarraySum(vector<int> &arr) {
    int res = arr[0];        // max sum so far
    int maxEnding = arr[0];  // max sum ending here

    for (int i = 1; i < arr.size(); i++) {
        maxEnding = max(arr[i], maxEnding + arr[i]); // extend or start new
        res = max(res, maxEnding);                   // update result
    }
    return res;
}

int main() {
    int n;
    cin >> n;                // array size
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i]; // input elements
    cout << maxSubarraySum(arr);
    return 0;
}
