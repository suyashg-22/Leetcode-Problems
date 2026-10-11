class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int>indeg(n,0);
        vector<vector<int>>adj(n);
        for(auto it:prerequisites){
            int a = it[0];
            int b = it[1];
            adj[b].push_back(a);
            indeg[a]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0)q.push(i);
        }
        int cnt =0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(indeg[node]==0)cnt++;
            for(auto nnode : adj[node]){
                indeg[nnode]--;
                if(indeg[nnode]==0)q.push(nnode);
            }
        }
        if(cnt==n)return true;
        return false;
    }
};