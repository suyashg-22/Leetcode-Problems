class Solution {
private:
    bool bfscycledetector(int i,int j,vector<vector<char>>& grid,vector<vector<int>>&vis){
        int row =grid.size();
        int col =grid[0].size();
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        queue<pair<pair<int,int>,pair<int,int>>>q;
        q.push({{i,j},{-1,-1}});
        vis[i][j]=1;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int parentr = q.front().second.first;
            int parentc = q.front().second.second;
            q.pop();
            char alpha = grid[r][c];
            for(int k=0;k<4;k++){
                int newr = r + delr[k];
                int newc = c + delc[k];
                if (newr >= 0 && newr < row && newc >= 0 && newc < col && grid[newr][newc] == alpha) {
                    if (vis[newr][newc] == 0) {
                        vis[newr][newc] = 1;
                        q.push({{newr, newc}, {r, c}});
                    } else if ((newr != parentr && newc != parentc)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0){
                    if(bfscycledetector(i,j,grid,vis) == true){
                        return true;
                    }
                }    
            }
        }
        return false;
    }
};