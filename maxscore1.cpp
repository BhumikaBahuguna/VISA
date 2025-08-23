#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,x,score=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
cin>>k;
int mx=arr[0];
x=0;
while(k!=0){
    mx=arr[0];
for(int i=0;i<n;i++){
    if(arr[i]>mx){
        mx=arr[i];
        x=i;
    }
}
score+=mx;
arr[x]=ceil(mx/3.0);
k--;
}
cout<<"max score : "<<score;
return 0;
}
