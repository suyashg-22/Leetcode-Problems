class Solution {

private:
    void bfs(vector<vector<int>>& ans,int sr,int sc,int color,vector<vector<int>>& vis,int ini){
        ans[sr][sc]=color;  
        vis[sr][sc]=1;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int row = ans.size();
        int col = ans[0].size();
        int delrow[] = {0,-1,0,1};
        int delcol[] = {-1,0,1,0};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int k=0;k<4;k++){     
                int newrow = r + delrow[k];
                int newcol = c + delcol[k];
                if(newrow>=0 && newrow <row && newcol>=0 && newcol<col &&ans[newrow][newcol]==ini && vis[newrow][newcol]==0){
                    vis[newrow][newcol]=1;
                    ans[newrow][newcol]=color;
                    q.push({newrow,newcol});
                }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans(image);
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ini = image[sr][sc];
        bfs(ans,sr,sc,color,vis,ini);
        return ans;
    }
};