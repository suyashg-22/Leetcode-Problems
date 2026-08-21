class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n =numCourses;
        vector<int>ans;
        queue<int>q;
        vector<int>indeg(n,0);
        vector<vector<int>>adj(n);
        for(auto it:prerequisites){
            int a = it[0];
            int b = it[1];
            adj[b].push_back(a);
            indeg[a]+=1;
        }
        for(int i=0;i<n;i++){
            if(indeg[i]==0)q.push(i);   
        }
        while(!q.empty()){
            int node =q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0)q.push(it);
            }
        }
        if(ans.size()!=n)return {};
        return ans;
    }
};