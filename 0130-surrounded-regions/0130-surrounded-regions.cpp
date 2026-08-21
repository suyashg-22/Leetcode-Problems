class Solution {
public:
    vector<int>dx{0,1,0,-1};
    vector<int>dy{-1,0,1,0};
    void dfs(int x,int y,vector<vector<int>>&vis,int n,int m,vector<vector<char>>&arr){
        vis[x][y]=1;
        arr[x][y]='*';
        for(int z=0;z<4;z++){
            int nx=x+dx[z];
            int ny=y+dy[z];
            if(nx<n && nx>=0 && ny>=0 && ny<m){
                if(vis[nx][ny]==-1 && arr[nx][ny]=='O'){
                    dfs(nx,ny,vis,n,m,arr);
                }
            }
        }
        return;
    }
    void solve(vector<vector<char>>& board) {
        int n= board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 ||j==m-1){
                    if(board[i][j]=='O'&&vis[i][j]==-1){
                        dfs(i,j,vis,n,m,board);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='*'){
                    board[i][j]='O';
                }
                else board[i][j]='X';
            }
        }
        return;
    }
};