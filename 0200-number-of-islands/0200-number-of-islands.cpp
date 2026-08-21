class Solution {
public:
    vector<int>dx{0,1,0,-1};
    vector<int>dy{-1,0,1,0};
    void dfs(int x,int y,int n,int m,vector<vector<char>>&arr,vector<vector<int>>&vis){
        vis[x][y]=1;
        for(int z=0;z<4;z++){
            int nx=x+dx[z];
            int ny=y+dy[z];
            if(nx<n && nx>=0 && ny>=0 && ny<m){
                if(arr[nx][ny]=='1' && vis[nx][ny]==-1){
                    dfs(nx,ny,n,m,arr,vis);
                }
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n =grid.size();
        int m =grid[0].size();
        int cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==-1 && grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,n,m,grid,vis);
                }
            }
        }
        return cnt;
    }
};