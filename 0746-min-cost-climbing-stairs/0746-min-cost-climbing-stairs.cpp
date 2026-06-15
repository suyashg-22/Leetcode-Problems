class Solution {
public:
    int n;
    int dp[1002];
    int rec(int level,vector<int>&arr){
        if(level>=n)return 0;
        if(dp[level]!=-1)return dp[level];

        int ans = 1e9;
        if(level==0){
            ans=min(ans,rec(level+1,arr));
        }
        ans=min(ans,arr[level]+rec(level+1,arr));
        ans=min(ans,arr[level]+rec(level+2,arr));
        return dp[level]=ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        this->n=cost.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,cost);
    }
};