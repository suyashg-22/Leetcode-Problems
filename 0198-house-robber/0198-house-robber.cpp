class Solution {
public:
    int dp[101];
    int rec(int level,vector<int>&arr,int n){
        if(level>=n)return 0;
        if(dp[level]!=-1)return dp[level];
        int ans= rec(level+1,arr,n);
        ans= max(ans,arr[level]+rec(level+2,arr,n));
        return dp[level]=ans;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,nums,n);
    }
};