class Solution {
public:
    int n;
    int k;
    vector<vector<pair<int,int>>>adj;
    vector<int>dist;

    void dijk(){
        dist.assign(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto it = pq.top();
            int d = it.first;
            int node =it.second;
            pq.pop();
            for(auto x:adj[node]){
                int newd = x.second;
                int newnode = x.first;
                if(d+newd<dist[newnode]){
                    dist[newnode]=d+newd;
                    pq.push({dist[newnode],newnode});
                }
            }
        }

    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        this->n=n;
        this->k=k;
        adj.resize(n+1);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }    
        dijk();
        int maxi = INT_MIN;
        for(int i=1;i<dist.size();i++){
            if(dist[i]==INT_MAX)return -1;
            maxi= max(maxi,dist[i]);
        }
        return maxi;

    }
};