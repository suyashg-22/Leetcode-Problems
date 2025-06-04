class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>>ans(grid);
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(row,vector<int>(col,0));
        int tm = 0;
        int cntfresh =0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(ans[i][j]==2){
                    vis[i][j]=2;
                    q.push( {{i,j},0});
                }
                else{
                    vis[i][j]=0;
                }

                if(ans[i][j]==1){
                    cntfresh+=1;
                }
            }
        }
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        int cnt =0;
        while(!q.empty()){
            int t = q.front().second;
            int r = q.front().first.first;
            int c = q.front().first.second;
            q.pop();
            tm = max(tm,t);
            for(int k =0;k<4;k++){
                int newr = r+delrow[k];
                int newc = c+delcol[k];
                if(newr>=0 && newr<row && newc>=0 && newc<col && vis[newr][newc]==0 && ans[newr][newc]==1){
                    vis[newr][newc]=1;
                    ans[newr][newc]=2;
                    q.push({{newr,newc},t+1});
                    cnt+=1;
                }
            }
        }
        if(cnt != cntfresh) return -1;
        return tm;
    }
};