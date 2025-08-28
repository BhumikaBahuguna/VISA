class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        sort(inventory.begin(), inventory.end(), greater<int>());
        inventory.push_back(0);
        long long res = 0;
        int k = 1;
        const int MOD = 1000000007;
        
        for (int i = 0; i < inventory.size() - 1; i++) {
            if (inventory[i] > inventory[i + 1]) {
                long long current = inventory[i];
                long long next = inventory[i + 1];
                long long diff = current - next;
                
                if (k * diff < orders) {
                    // Sum of arithmetic series: k * (current + next + 1) * diff / 2
                    res = (res + k * (current + next + 1) * diff / 2) % MOD;
                    orders -= k * diff;
                } else {
                    int q = orders / k;
                    int r = orders % k;
                    // Sum of first q terms: k * (current + (current - q + 1)) * q / 2
                    res = (res + k * (current + (current - q + 1)) * q / 2) % MOD;
                    // Add remainder
                    res = (res + r * (current - q)) % MOD;
                    return res;
                }
            }
            k++;
        }
        return res;
    }
};
