#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>k;
    priority_queue<int>pq(arr.begin(),arr.end());
    long long score=0;
    while(k--){
        int val=pq.top();
        pq.pop();
        score+=val;
        int reduced=ceil(val/3.0);
        pq.push(reduced);
    }
    cout<<"Max Score:"<<score<<endl;
    return 0;   
}