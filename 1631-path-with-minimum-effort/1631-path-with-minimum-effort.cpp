class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n= heights.size();
        int m =heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<int>dx{0,1,0,-1};
        vector<int>dy{-1,0,1,0};
        pq.push({0,{0,0}});
        dist[0][0]=0;
        while(!pq.empty()){
            auto it =pq.top();
            pq.pop();
            int d = it.first;
            int x=it.second.first;
            int y=it.second.second;
            if(x==n-1 && y==m-1)return d;
            for(int z=0;z<4;z++){
                int nx=x+dx[z];
                int ny=y+dy[z];
                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    int dd = abs(heights[nx][ny]-heights[x][y]);
                    int maxi=max(d,dd);
                    if(maxi<dist[nx][ny]){
                        dist[nx][ny]=maxi;
                        pq.push({maxi,{nx,ny}});
                    }
                }
            }
        }
        return dist[n-1][m-1];        
    }
};