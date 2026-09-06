class Solution {
public:
    int dp[101][101];
    int rec(int x,int y,vector<vector<int>>&arr,int n,int m){
        if(x==n-1 && y==m-1)return 1;
        if(dp[x][y]!=-1)return dp[x][y];
        int ans=0;
        if(x+1<n && arr[x+1][y]==0)ans+=rec(x+1,y,arr,n,m);
        if(y+1<m && arr[x][y+1]==0)ans+=rec(x,y+1,arr,n,m);
        return dp[x][y]=ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n= obstacleGrid.size();
        int m= obstacleGrid[0].size();
        if(n==1 && m==1 && obstacleGrid[0][0]==0)return 1;
        if(obstacleGrid[0][0]==1 || obstacleGrid[n-1][m-1]==1)return 0;
        memset(dp,-1,sizeof(dp));
        return rec(0,0,obstacleGrid,n,m);
    }
};