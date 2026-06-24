using ll = long long;
class Solution {
public:
    vector<vector<pair<int,int>>>adj;
    
    int dijk(int n, int k, string &labels){
        vector<vector<int>> dist(n, vector<int>(k + 1, 1e9));
        dist[0][k-1] = 0; 
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0, {k-1, 0}});
        
        while(!pq.empty()){
            auto it = pq.top();
            int d = it.first;
            int kk = it.second.first;
            int node = it.second.second;
            pq.pop();
            
            if (d > dist[node][kk]) continue;
            
            char c = labels[node];
            
            for(auto x : adj[node]){
                int nnode = x.first;
                int wt = x.second;
                char cc = labels[nnode];
                
                if(c == cc){
                    if(kk - 1 >= 0){
                        if(d + wt < dist[nnode][kk - 1]){
                            dist[nnode][kk - 1] = d + wt;
                            pq.push({d + wt, {kk - 1, nnode}});
                        }
                    }
                }
                else{
                    if(d + wt < dist[nnode][k - 1]){
                        dist[nnode][k - 1] = d + wt;
                        pq.push({d + wt, {k - 1, nnode}});
                    }
                }
            }
        }
        
        int ans = 1e9;
        for(int i = 0; i <= k; i++) {
            ans = min(ans, dist[n-1][i]);
        }
        
        if(ans >= 1e9) return -1;
        return ans;
    }

    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        adj.resize(n);
        for(auto it : edges){
            int a = it[0];
            int b = it[1];
            int c = it[2];
            adj[a].push_back({b, c});
        }
        return dijk(n, k, labels);
    }
};