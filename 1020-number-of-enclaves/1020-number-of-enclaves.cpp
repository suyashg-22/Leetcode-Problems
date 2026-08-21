class Solution {
public:
    vector<int>dx{0,1,0,-1};
    vector<int>dy{-1,0,1,0};
    void dfs(int x,int y,int n,int m,vector<vector<int>>&arr){
        arr[x][y]=0;
        for(int z=0;z<4;z++){
            int nx=x+dx[z];
            int ny=y+dy[z];
            if(nx<n && nx>=0 && ny>=0 && ny<m){
                if(arr[nx][ny]==1){
                    dfs(nx,ny,n,m,arr);
                }
            }
        }
        return;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n =grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 ||j==m-1){
                    if(grid[i][j]==1)dfs(i,j,n,m,grid);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)ans++;
            }
        }
        return ans;
    }
};