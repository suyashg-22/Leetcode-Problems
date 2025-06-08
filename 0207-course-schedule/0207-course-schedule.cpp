class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<int>indegree(numCourses);
        vector<vector<int>>adj(numCourses);
        queue<int>q;
        vector<int>topo;
        for(int i=0;i<n;i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            adj[a].push_back(b);
            indegree[b]+=1;
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it: adj[node]){
                indegree[it]-=1;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(topo.size()==numCourses) return true;
        return false;
    }
};