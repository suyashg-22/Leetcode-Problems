class Solution {
public:
    int dp[46];
    int rec(int level,int n){
        if(level==n)return 1;
        if(dp[level]!=-1)return dp[level];
        int ans=0;
        ans+=rec(level+1,n);
        if(level+2<=n){
            ans+=rec(level+2,n);
        }
        return dp[level]=ans;
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return rec(0,n);
    }
};