class Solution {
public:
    vector<int>dx{0,1,0,-1};
    vector<int>dy{-1,0,1,0};
    void dfs(int x,int y,vector<vector<int>>&vis,vector<vector<int>>&arr,int n,int m){
        vis[x][y]=1;
        arr[x][y]=2;
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && nx<n && ny<m && ny>=0){
                if(arr[nx][ny]==0 && !vis[nx][ny]){
                    dfs(nx,ny,vis,arr,n,m);
                }
            }
        }
        return;
    }
    void dfs2(int x,int y,vector<vector<int>>&vis,vector<vector<int>>&arr,int n,int m){
        vis[x][y]=1;
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && nx<n && ny<m && ny>=0){
                if(arr[nx][ny]==0 && !vis[nx][ny]){
                    dfs2(nx,ny,vis,arr,n,m);
                }
            }
        }
        return;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(grid[i][j]==0 && !vis[i][j]){
                        dfs(i,j,vis,grid,n,m);
                    }
                }
            }
        }
        vector<vector<int>>vis2(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 && !vis2[i][j]){
                    ans+=1;
                    dfs2(i,j,vis2,grid,n,m);
                }
            }
        }
        return ans;
    }
};