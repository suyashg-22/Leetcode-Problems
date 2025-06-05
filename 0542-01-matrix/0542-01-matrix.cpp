class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n= mat.size();
        int m= mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 &&mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        int delr[] ={-1,0,1,0};
        int delc[] ={0,1,0,-1};
        while(!q.empty()){
            int dist = q.front().second;
            int row = q.front().first.first;
            int col = q.front().first.second;
            q.pop();
            ans[row][col] = dist;
            for(int k=0;k<4;k++){
                int newr = row+delr[k];
                int newc = col+delc[k];
                if(newr>=0 && newr<n && newc>=0 && newc<m && vis[newr][newc]==0){
                    q.push({{newr,newc},dist+1});
                    vis[newr][newc]=1;
                }
            }
        }
        return ans;

    }
};