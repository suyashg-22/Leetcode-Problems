class Solution {
public:

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int start = image[sr][sc];
        int n = image[0].size();
        int m = image.size();
        queue<pair<int,int>>q;
        vector<pair<int, int>> padosi{{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};
        vector<vector<int>>vis(m,vector<int>(n,0));
        q.push({sr,sc});
        image[sr][sc]=color;

        while(!q.empty()){
            auto p = q.front();
            auto x = p.first;
            auto y = p.second;
            vis[x][y]=1;
            q.pop();
            for(int i=0;i<padosi.size();i++){
                int a = x+padosi[i].first;
                int b = y+padosi[i].second;
                pair<int,int>z = {a,b};
                if(a>=0 && a<m && b>=0 && b<n){
                    if(image[a][b]==start){
                        if(vis[a][b]==0){
                            vis[a][b]=1;
                            q.push(z);
                            image[a][b]=color;
                        }
                    }
                }
            }
        }
        return image;
    }
};