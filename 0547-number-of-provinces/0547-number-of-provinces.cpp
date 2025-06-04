class Solution {
private:
    void dfs(int node ,vector<vector<int>>& adj,vector<int>&vis){
        vis[node]=1;
        for(auto it:adj[node] ){
            if(vis[it]==0){
                vis[it]=1;
                dfs(it,adj,vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n= isConnected.size();
        vector<vector<int>>adj(n);
        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int node =0;
        vector<int>vis(n,0);
        int cnt =0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(i,adj,vis);
                cnt+=1;
            }
        }
        return cnt;
    }
};