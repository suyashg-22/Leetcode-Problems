class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n =grid.size();
        if(n==1 && grid[0][0]==0)return 1;
        if(grid[n-1][n-1]==1)return -1;
        if(grid[0][0]==1)return -1;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<int>dx{-1,0,1,1,1,0,-1,-1};
        vector<int>dy{-1,-1,-1,0,1,1,1,0};
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int x = it.second.first;
            int y = it.second.second;
            int d = it.first;
            for(int i=0;i<8;i++){
                int nx= x+dx[i];
                int ny= y+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<n){
                    if(grid[nx][ny]==0){
                        if(d+1<dist[nx][ny]){
                            dist[nx][ny]=d+1;
                            pq.push({d+1,{nx,ny}});
                        }
                    }
                }
            }
        }
        if(dist[n-1][n-1]==1e9)return -1;
        return dist[n-1][n-1]+1;
    }
};