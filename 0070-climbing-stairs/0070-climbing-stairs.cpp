class Solution {
public:
    int dp[46];
    int rec(int level,int n){
        if(level>n)return 0;
        if(level==n)return 1;

        if(dp[level]!=-1){
            return dp[level];
        }
        int ways =0;
        for(int choice=1;choice<=2;choice++){
            if(level+choice<=n){
                ways += rec(level+choice,n);
            }
        }
        dp[level]=ways;
        return ways;
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return rec(0,n);
    }
};