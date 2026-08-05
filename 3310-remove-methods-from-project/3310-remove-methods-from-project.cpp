class Solution {
public:
    void bfs(int node,vector<int>&vis,vector<vector<int>>&adj,vector<int>&indeg,int k){
        queue<int>q;
        q.push(k);
        vis[k]=1;
        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                int node = q.front();
                q.pop();
                for(auto it : adj[node]){
                    int nnode = it;
                    indeg[nnode]-=1;
                    if(vis[nnode]==0){
                        vis[nnode]=1;
                        q.push(nnode);
                    }
                }
            }
        }
        return;
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        vector<int>vis(n,0);
        vector<int>indeg(n,0);
        for(auto it :invocations){
            int a = it[0];
            int b = it[1];
            adj[a].push_back(b);
            indeg[b]+=1;
        }
        bfs(k,vis,adj,indeg,k);
        bool flag = true;
        for(int i=0;i<n;i++){
            if(vis[i]==1 && indeg[i]>0){
                flag = false;
                break;
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(flag){
                if(vis[i]==0)ans.push_back(i);
            }
            else{
                ans.push_back(i);
            }
        }
        return ans;
    }
};