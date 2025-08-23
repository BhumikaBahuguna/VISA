#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n;
    vector<int>prices(n);
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }
    cin>>q;
    vector<int>results;
    while(q--){
        int pos;
        long long amount;
        cin>>pos>>amount;
        pos--;
        int count=0;
        for(int i=0;i<n;i++){
            if(prices[i]<=amount){
                count++;
                amount-=prices[i];
            }else{
                break;
            }
        }
        results.push_back(count);
    }
    for(int c : results)
    cout << c << endl;
    return 0;
}