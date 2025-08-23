#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n;
    vector<int>prices(n);
    for(int i=0;i<n;i++) cin >>prices[i];
    vector<long long>prefix(n);
    prefix[0]=prices[0];
    for(int i=1;i<n;i++) prefix[i]=prefix[i-1]+prices[i];
    cin>>q;
    vector<int>results;
    while(q--){
        int pos;
        long long amount;
        cin >>pos >>amount;
        pos--;
        if (pos >= n) {
            results.push_back(0);
            continue;
        }
        long long left_sum=(pos==0?0:prefix[pos-1]);
        int l=pos,r=n-1;
        int ans=pos-1;
        if (prices[pos] > amount) {
            results.push_back(0);
            continue;
        }
        while(l<=r){
            int mid=l+(r-l)/2;
            if(prefix[mid] - left_sum <= amount){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        results.push_back(ans - pos + 1);
    }
    for(int c : results) cout << c << endl;
    return 0;
}