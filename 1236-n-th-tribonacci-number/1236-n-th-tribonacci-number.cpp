class Solution {
public:
    int dp[38];
    int N;
    int rec(int level){
         if(level==0)return 0;
        if(level==1)return 1;
        if(level==2)return 1;

        if(dp[level]!=-1)return dp[level];

        int ans = rec(level-1)+rec(level-2)+rec(level-3);
        return dp[level]=ans;

    }
    int tribonacci(int n) {
        memset(dp,-1,sizeof(dp));
        N=n;
        return rec(n);
    }
};