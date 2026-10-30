class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int kk = 0;
        int l=0;
        int r=0;
        int ans =0;
        while(r<n){
            if(nums[r]==0)kk++;
            while(l<r && kk>k){
                if(nums[l]==0)kk--;
                l++;
            }
            if(kk<=k)ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};