class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n =mat.size();
        int m= mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,-1));
        queue<vector<int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j,0});
                    vis[i][j]=0;
                }
            }
        }
        vector<int>dx{0,1,0,-1};
        vector<int>dy{-1,0,1,0};
        while(!q.empty()){
            auto it =q.front();
            int x=it[0];
            int y=it[1];
            int d=it[2];
            q.pop();
            for(int z=0;z<4;z++){
                int nx=x+dx[z];
                int ny=y+dy[z];
                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    if(vis[nx][ny]==-1 && mat[nx][ny]==1){
                        q.push({nx,ny,d+1});
                        vis[nx][ny]=d+1;
                    }
                }
            }
        }
        return vis;
    }
};