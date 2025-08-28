#include<bits/stdc++.h>
using namespace std;
    int maxProfit(vector<int>& inventory, int orders) {
        sort(inventory.begin(), inventory.end(), greater<int>());
        inventory.push_back(0);
        long long res = 0;
        int k = 1;
        const int MOD = 1000000007;
        
        for (int i = 0; i < inventory.size() - 1; i++) {
            if (inventory[i] > inventory[i + 1]) {
                if (k * (inventory[i] - inventory[i + 1]) < orders) {
                    long long diff = inventory[i] - inventory[i + 1];
                    res += k * (inventory[i] + inventory[i + 1] + 1) * diff / 2;
                    orders -= k * diff;
                } else {
                    int q = orders / k;
                    int r = orders % k;
                    res += k * (long long)(inventory[i] + (inventory[i] - q + 1)) * q / 2;
                    res += r * (long long)(inventory[i] - q);
                    return res % MOD;
                }
            }
            k++;
        }
        return res % MOD;
    }
int main(){
    int n,orders;
    cout<<"Enter number of balls : ";
    cin>>n;
    vector<int> inventory(n);
    cout<<"Enter the values of balls : ";
    for(int i=0;i<n;i++){
        cin>>inventory[i];
    }
    cout<<"Enter number of orders : ";
    cin>>orders;
    cout<<"Max Profit : "<<maxProfit(inventory,orders);
    return 0;
}