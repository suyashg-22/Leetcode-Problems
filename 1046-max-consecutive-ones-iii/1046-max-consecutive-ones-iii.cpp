class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt =k;
        int l =0;
        int r =0;
        int maxi =0;
        while(r<n){
            if(cnt==0 && nums[r]==0){
                maxi=max(maxi,r-l);
                while(nums[l]==1){
                    l+=1;
                }
                l+=1;
                cnt+=1;
            }

            if(nums[r]==0)cnt-=1;
            r+=1;
            
        }
        maxi =max(maxi,n-l);
        return maxi;
    }
};