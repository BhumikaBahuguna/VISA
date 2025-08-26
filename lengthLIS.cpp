class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        int len=1;
        int ind;
        for(int i=1;i<n;i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
                len++;
            }else{
                ind=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
            temp[ind]=nums[i];
            }
        }
        return len;
    }
};
