class Solution {
public:
    int n;
    int m;
    int dp[201][201];
    int rec(int r,int c,vector<vector<int>>&grid){
        if(r<0 && c<0)return INT_MAX;
        if(r==0 && c==0)return grid[0][0];
        if(dp[r][c]!=-1)return dp[r][c];

        int ans = INT_MAX;
        if(r>0){
            ans = grid[r][c]+rec(r-1,c,grid);
        }
        if(c>0){
            ans = min(ans,grid[r][c]+rec(r,c-1,grid));
        }
        return dp[r][c]=ans;
    }

    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return rec(n-1,m-1,grid);
    }
};