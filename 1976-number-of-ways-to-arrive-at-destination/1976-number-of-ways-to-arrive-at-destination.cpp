const long long mod =1e9+7;
using ll=long long;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<ll,ll>>>adj(n);
        for(auto it:roads){
            ll a =it[0];
            ll b=it[1];
            ll c=it[2];
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        vector<ll>dist(n,LONG_MAX);
        vector<ll>ways(n,0);
        dist[0]=0;
        ways[0]=1;
        pq.push({0,0});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            ll d = it.first;
            ll node = it.second;
            for(auto iit:adj[node]){
                ll nnode= iit.first;
                ll w = iit.second;
                if(d<dist[nnode]-w){
                    dist[nnode]=d+w;
                    ways[nnode]=ways[node];
                    pq.push({dist[nnode],nnode});
                }
                else if(d==dist[nnode]-w){
                    ways[nnode]=(ways[nnode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1];
    }
};