class Solution {
private:
    void dfs(int i ,int j,vector<vector<int>>& grid,vector<vector<int>>&vis,int delr[],int delc[]){
        vis[i][j]=1;
        int row = grid.size();
        int col = grid[0].size();
        for(int k=0;k<4;k++){
            int newr = i+delr[k];
            int newc = j+delc[k];
            if(newr>=0 && newr<row && newc>=0 && newc<col && vis[newr][newc]==0 && grid[newr][newc]==1){
                dfs(newr,newc,grid,vis,delr,delc);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n =grid.size();
       int m = grid[0].size();
       int delr[]={-1,0,1,0};
       int delc[]={0,1,0,-1};
       vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(i==0 || i==n-1){
                for(int j=0;j<m;j++){
                    if(vis[i][j]==0 && grid[i][j]==1){
                        vis[i][j]=1;
                         dfs(i,j,grid,vis,delr,delc);
                    }
                }
            }    
        }
        for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(j==0 || j==m-1){
                        if(vis[i][j]==0 && grid[i][j]==1){
                            vis[i][j]=1;
                            dfs(i,j,grid,vis,delr,delc);
                        }
                    }
                }   
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]==1){
                    cnt+=1;
                }
            }
        }
        return cnt;
    }
    
};