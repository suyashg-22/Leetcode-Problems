class Solution {
public:
    int dp[101][101];
    int rec(int i,int j,int n,int m){
        if(i==n-1 && j==m-1)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        if(j+1<m)ans+= rec(i,j+1,n,m);
        if(i+1<n)ans+= rec(i+1,j,n,m);
        return dp[i][j]=ans;
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return rec(0,0,m,n);
    }
};