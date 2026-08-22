class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(n==1 && m==1)return (grid[0][0]==0)?1:-1;
        if(grid[0][0]==1 || grid[n-1][m-1]==1)return -1;
        vector<int>dx{0,1,1,1,0,-1,-1,-1};
        vector<int>dy{-1,-1,0,1,1,1,0,-1};
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0][0]=1;
        int d=1;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto it =q.front();
                q.pop();
                int x =it.first;
                int y=it.second;
                for(int z=0;z<8;z++){
                    int nx=x+dx[z];
                    int ny=y+dy[z];
                    if(nx>=0 && nx<n && ny>=0 && ny<m){
                        if(!vis[nx][ny] && grid[nx][ny]==0){
                            vis[nx][ny]=1;
                            q.push({nx,ny});
                            if(nx==n-1 && ny==m-1)return d+1;
                        }
                    }
                }
            }
            d++;
        }
        return -1;
    }
};