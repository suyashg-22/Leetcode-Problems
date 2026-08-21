class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n =numCourses;
        int cnt=0;
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
            cnt++;
            for(auto it:adj[node]){
                if(indeg[it]>0){
                    indeg[it]--;
                    if(indeg[it]==0)q.push(it);
                }
            }
        }
        return (cnt==n);
    }
};