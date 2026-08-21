class Solution {
public:
    bool bfs(int node,vector<int>&vis,vector<vector<int>>&graph,int n){
        queue<int>q;
        q.push(node);
        vis[node]=0;
        while(!q.empty()){
            auto node =q.front();
            q.pop();
            int c = vis[node];
            for(auto nnode:graph[node]){
                if(vis[nnode]==-1){
                    vis[nnode]= c^1;
                    q.push(nnode);
                }
                else{
                    if(c==vis[nnode])return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int>vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                bool ans = bfs(i,vis,graph,n);
                if(!ans)return false;
            }
        }
        return true;
    }
};