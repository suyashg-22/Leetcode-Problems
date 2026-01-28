class Solution {
public:
    int n;
    vector<int>tin;
    vector<int>lowt;
    int t =1;
    vector<int>vis;
    vector<vector<int>>adj;
    vector<vector<int>>ans;

    void dfs(int node,int parent){
        vis[node]=1;
        tin[node]=t;
        lowt[node]=t;
        t+=1;
        for(auto it:adj[node]){
            if(it!=parent){
                if(!vis[it]){
                    dfs(it,node);
                    lowt[node]=min(lowt[node],lowt[it]);
                    if(tin[node]<lowt[it]){
                        ans.push_back({node,it});
                    }
                }
                else{
                    lowt[node]=min(lowt[node],lowt[it]);
                }
            }
        }

    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        this->n=n;
        tin.resize(n);
        lowt.resize(n);
        vis.assign(n,0);
        adj.resize(n);
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(0,-1);
        return ans;
    }
};