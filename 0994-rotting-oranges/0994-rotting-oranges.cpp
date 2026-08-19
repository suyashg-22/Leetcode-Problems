class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>dx{0,1,0,-1};
        vector<int>dy{-1,0,1,0};
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        int t=0;
        while(!q.empty()){
            int size=q.size();
            bool flag = false;
            for(int i=0;i<size;i++){
                auto it = q.front();
                q.pop();
                int x = it.first;
                int y = it.second;
                for(int z=0;z<4;z++){
                    int nx=x+dx[z];
                    int ny=y+dy[z];
                    if(nx>=0 && nx<n && ny>=0 && ny<m){
                        if(grid[nx][ny]==1 && vis[nx][ny]==0){
                            vis[nx][ny]=1;
                            q.push({nx,ny});
                            flag=true;
                        }
                    }
                }
            }
            if(flag)t++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0)return -1;
            }
        }
        return t;
    }
};