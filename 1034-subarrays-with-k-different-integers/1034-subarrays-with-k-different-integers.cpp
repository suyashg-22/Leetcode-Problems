class Solution {
public:
    int f(vector<int>&nums,int k){
        int n =nums.size();
        int l =0;
        int r =0;
        unordered_map<int,int>mpp;
        int cnt =0;
        while(r<n){
            mpp[nums[r]]+=1;
            while(mpp.size()>k){
                mpp[nums[l]]-=1;
                if(mpp[nums[l]]==0)mpp.erase(nums[l]);
                l+=1;
            }
            cnt+=r-l+1;
            r+=1;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums,k)-f(nums,k-1);
    }
};