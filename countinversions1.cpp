#include<bits/stdc++.h>
using namespace std;
int countinversions(vector<int>&nums){
    int n=nums.size();
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i]>nums[j]){
                cnt+=1;
            }
        }
    }
    return cnt;
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<countinversions(nums)<<endl;
    return 0;
}