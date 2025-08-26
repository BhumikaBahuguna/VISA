#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    double median;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    sort(nums.begin(),nums.end());
    if(n%2==1){
        median=nums[n/2];
    }else{
        median=(nums[n/2]+nums[n/2-1])/2.0;
    }
    cout<<fixed<<setprecision(1)<<median<<endl;
    return 0;
}