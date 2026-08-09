class Solution {
public:
    int dp[101][101];
    int rec(int i,int j,int n,int m,vector<vector<int>>&arr){
        if(i==n-1 && j==m-1)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        if(j+1<m && arr[i][j+1]!=1)ans+= rec(i,j+1,n,m,arr);
        if(i+1<n && arr[i+1][j]!=1)ans+= rec(i+1,j,n,m,arr);
        return dp[i][j]=ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n =obstacleGrid.size();
        int m =obstacleGrid[0].size();
        if(obstacleGrid[n-1][m-1]==1 ||obstacleGrid[0][0]==1 )return 0;
        memset(dp,-1,sizeof(dp));
        return rec(0,0,n,m,obstacleGrid);
    }
};