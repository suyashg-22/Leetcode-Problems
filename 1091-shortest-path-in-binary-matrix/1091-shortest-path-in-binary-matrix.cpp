class Solution {
public:
    vector<int> dx{0, -1, -1, -1, 0, 1, 1, 1};
    vector<int> dy{-1, -1, 0, 1, 1, 1, 0, -1};
    int dijk(vector<vector<int>>&arr){
        int n= arr.size();
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        dist[0][0]=1;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({1,0,0});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int i= it[1];
            int j= it[2];
            int d= it[0];
            for(int x=0;x<8;x++){
                int ni = i+dx[x];
                int nj = j+dy[x];
                if(ni>=0 && ni<n && nj>=0 && nj<n && arr[ni][nj]==0){
                    if(d+1<dist[ni][nj]){
                        dist[ni][nj]=d+1;
                        pq.push({dist[ni][nj],ni,nj});
                    }
                }
            }
        }
        if(dist[n-1][n-1]==1e9)return -1;
        return dist[n-1][n-1];
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n= grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)return -1;
        return dijk(grid);
    }
};