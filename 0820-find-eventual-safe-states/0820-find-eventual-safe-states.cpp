class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>rgraph(n);
        vector<int>indegree(n);
        queue<int>q;
        vector<int>topo;
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                rgraph[it].push_back(i);
                indegree[i]++;
            }
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it: rgraph[node]){
                indegree[it]-=1;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        sort(topo.begin(),topo.end());
        return topo;
    }
};