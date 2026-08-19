class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int c = image[sr][sc];
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,-1));
        vis[sr][sc]=1;
        image[sr][sc]=color;
        q.push({sr,sc});
        vector<int>dx{0,1,0,-1};
        vector<int>dy{-1,0,1,0};
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto it =q.front();
                q.pop();
                int x = it.first;
                int y = it.second;
                for(int z=0;z<4;z++){
                    int nx=x+dx[z];
                    int ny=y+dy[z];
                    if(nx>=0 && nx<n && ny>=0 && ny<m){
                        if(vis[nx][ny]==-1 && image[nx][ny]==c){
                            vis[nx][ny]=1;
                            image[nx][ny]=color;
                            q.push({nx,ny});
                        }
                    }
                }
            }
        }
        return image;
    }
};