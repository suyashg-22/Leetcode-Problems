class Solution {
public:
    int f(vector<int>nums,int goal){
        int n = nums.size();
        int l =0;
        int r =0;
        int sum =0;
        int cnt =0;
        while(r<n){
            sum+=nums[r];
            while(sum>goal ){
                sum-=nums[l];
                l+=1;
            }
            cnt+=r-l+1;
            r+=1;
        }
        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if(goal==0){
            return f(nums,0);
        }
        return f(nums,goal)-f(nums,goal-1);
    }
};