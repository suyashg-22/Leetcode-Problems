class Solution {
public:
    int dp[51][51][101];
    vector<int>dx{0,1,0,-1};
    vector<int>dy{-1,0,1,0};
    bool dfs(int i,int j,int h,vector<vector<int>>&arr,int n,int m){
        if(i==n-1 && j==m-1)return true;
        if(dp[i][j][h]!=-1)return dp[i][j][h];

        dp[i][j][h]=0;
        bool ans = false;
        for(int z=0;z<4;z++){
            int ni = i+dx[z];
            int nj = j+dy[z];
            if(ni>=0 && ni<n && nj>=0 && nj<m){
                if(h-arr[ni][nj]>=1){
                    if(dfs(ni,nj,h-arr[ni][nj],arr,n,m)){
                        ans=true;
                        break;
                    }
                }
            }
        }
        return dp[i][j][h]=ans;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        memset(dp,-1,sizeof(dp));
        int n = grid.size();
        int m = grid[0].size();
        health-= grid[0][0];
        if(health<1)return false;
        return dfs(0,0,health,grid,n,m);
    }
};