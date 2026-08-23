class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights){
            int a=it[0];
            int b=it[1];
            int c=it[2];
            adj[a].push_back({b,c});
        }
        vector<int>dist(n,1e9);
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{0,src}});
        dist[src]=0;
        while(!q.empty()){
            auto it =q.front();
            q.pop();
            int f = it.first;
            int d = it.second.first;
            int node = it.second.second;
            for(auto iit:adj[node]){
                int w = iit.second;
                int nnode = iit.first;
                if(f+1<=k+1){
                    if(d+w<dist[nnode]){
                        dist[nnode]=d+w;
                        q.push({f+1,{d+w,nnode}});
                    }
                }
            }
        }
        if(dist[dst]==1e9)return -1;
        return dist[dst];
    }
};