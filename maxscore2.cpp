#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>&arr,int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;
    vector<int>L(n1),R(n2);
    for(int i=0;i<n1;i++) L[i]=arr[l+i];
    for(int i=0;i<n2;i++) R[i]=arr[m+1+i];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i]>=R[j])
            arr[k++]=L[i++];
        else    
            arr[k++]=R[j++];
    }
    while(i<n1) arr[k++]=L[i++];
    while(j<n2) arr[k++]=R[j++];
}
void mergesort(vector<int>&arr,int l,int r){
    if(l<r){
        int m=l+(r-l)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
void insertsorted(vector<int>&arr,int n){
    int val=arr[0];
    int i=1;
    while(i<n &&arr[i]>val){
        arr[i-1]=arr[i];
        i++;
    }
    arr[i-1]=val;
}
int main(){
    int n,k;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>k;
    mergesort(arr,0,n-1);
    long long score=0;
    while(k--){
        int val=arr[0];
        score+=val;
        arr[0]=ceil(val/3.0);
        insertsorted(arr,n);
    }
    cout<<"Max Score: "<<score<<endl;
    return 0;
}