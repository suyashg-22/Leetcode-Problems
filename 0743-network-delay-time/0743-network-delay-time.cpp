class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,1e9);
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times){
            int a =it[0];
            int b=it[1];
            int c=it[2];
            adj[a].push_back({b,c});
        }
        priority_queue<pair<int,int>>pq;
        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty()){
            auto it =pq.top();
            pq.pop();
            int node= it.second;
            int d = it.first;
            for(auto iit:adj[node]){
                int nnode = iit.first;
                int w = iit.second;
                if(d+w<dist[nnode]){
                    dist[nnode]=d+w;
                    pq.push({d+w,nnode});
                }
            }
        }
        int maxi=0;
        for(int i=1;i<n+1;i++){
            maxi=max(maxi,dist[i]);
        }
        if(maxi==1e9)return -1;
        return maxi;
    }
};