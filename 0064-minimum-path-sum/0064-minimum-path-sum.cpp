class Solution {
public:
    int dp[201][201];
    int rec(int i,int j,vector<vector<int>>&arr,int n,int m){
        if(i==n-1 && j==m-1)return arr[n-1][m-1];
        if(dp[i][j]!=-1)return dp[i][j];
        int ans =1e9;
        int x = arr[i][j];
        if(j+1<m)ans=min(ans,x+rec(i,j+1,arr,n,m));
        if(i+1<n)ans=min(ans,x+rec(i+1,j,arr,n,m));
        return dp[i][j]=ans;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return rec(0,0,grid,n,m);
    }
};