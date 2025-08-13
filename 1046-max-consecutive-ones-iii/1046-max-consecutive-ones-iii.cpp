class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n= nums.size();
        int l =0;
        int r =0;
        int maxi =0;
        int zeros =0;
        while(r<n){
            if(nums[r]==0){
                zeros+=1;
            }
            if(zeros>k){
                if(nums[l]==0)zeros-=1;
                l+=1;
            }
            maxi =max(maxi,r-l+1);
            r+=1;
        }
        return maxi;
    }
};