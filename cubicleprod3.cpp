#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n;
    vector<int>prices(n);
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }
    vector<long long>prefix(n);
    prefix[0]=prices[0];
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+prices[i];
    }
    cin>>q;
    vector<int>results;
    while(q--){
        int pos;
        long long amount;
        cin>>pos>>amount;
        pos--;
        if (pos >= n) {
            results.push_back(0);
            continue;
        }
        long long base=(pos==0?0:prefix[pos-1]);
        long long max_total=base+amount;
        auto it=upper_bound(prefix.begin(),prefix.end(),max_total);
        int right_index=it-prefix.begin()-1;
        if(right_index<pos){
            results.push_back(0);
        }else{
            results.push_back(right_index-pos+1);   
        }
    }
    for(int c : results){
        cout << c << endl;
    }
    return 0;
}