class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        int ans =-1;
        int l=0;
        int r=0;
        long long sum=0;
        sort(nums.begin(),nums.end());
        while(r<n){
            sum+=nums[r];
            int x = nums[r];
            while(l<r && x>(k+sum)/(r-l+1)){
                sum-=nums[l];
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};