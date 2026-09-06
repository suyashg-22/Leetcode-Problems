class Solution {
public:
    vector<int>dx{0,1,0,-1};
    vector<int>dy{-1,0,1,0};
    void dfs(int x,int y,vector<vector<char>>&arr,vector<vector<int>>&vis,int n,int m){
        vis[x][y]=1;
        for(int z=0;z<4;z++){
            int nx = x+dx[z];
            int ny = y+dy[z];
            if(nx>=0 && nx<n && ny>=0 && ny<m){
                if(arr[nx][ny]=='1' && !vis[nx][ny]){
                    dfs(nx,ny,arr,vis,n,m);
                }
            }
        }
        return ;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n =grid.size();
        int m =grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(i,j,grid,vis,n,m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};