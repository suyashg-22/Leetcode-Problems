class Solution {
public:
    int f(vector<int>&nums,int k){
        int cnt =0;
        int l =0;
        int r =0;
        int ans =0;
        int n =nums.size();
        while(r<n){
            if(nums[r]%2==1)cnt+=1;
            while(cnt>k){
                if(nums[l]%2==1)cnt-=1;
                l+=1;
            }

            if(cnt<=k)ans+=r-l+1;
            r+=1;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        // if(k==1){
        //     return f(nums,k);
        // }
        return f(nums,k)-f(nums,k-1);
    }
};