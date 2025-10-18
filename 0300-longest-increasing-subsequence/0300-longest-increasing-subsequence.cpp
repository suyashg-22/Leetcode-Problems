class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n =nums.size();
        vector<int>lis;
        for(int i=0;i<n;i++){
            if(lis.empty() || lis.back()<nums[i]){
                lis.push_back(nums[i]);
            }
            else{
                int ind = lower_bound(lis.begin(),lis.end(),nums[i]) - lis.begin();
                lis[ind] = nums[i];
            }
        }
        return lis.size();
    }
};