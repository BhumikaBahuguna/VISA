#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>&arr,int low,int high){
    int pivot=arr[high];
    int i=low;
    for(int j=low;j<high;j++){
        if(arr[j]<=pivot){
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[i],pivot);
    return i;
}
int quickselect(vector<int>&arr,int low,int high,int k){
    if(low<=high){
        int pi=partition(arr,low,high);
        if(pi==k) return arr[pi];
        else if(pi>k) return quickselect(arr,low,pi-1,k);
        else return quickselect(arr,pi+1,high,k);
    }
    return -1;
}
double findmedian(vector<int>&arr){
    int n=arr.size();
    if(n%2==1){
        return quickselect(arr,0,n-1,n/2);
    }else{
        int m1=quickselect(arr,0,n-1,n/2-1);
        int m2=quickselect(arr,0,n-1,n/2);
        return (m1+m2)/2.0;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    double median=findmedian(nums);
    cout<<fixed<<setprecision(1)<<median<<endl;
    return 0;
}