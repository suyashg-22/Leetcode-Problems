class Solution {
private:
    bool bfs(int start,vector<vector<int>>& graph,vector<int>&color){
        queue<int>q;
        q.push(start);
        color[start]=0;
        while(!q.empty()){
            int el = q.front();
            q.pop();
            for(auto it:graph[el]){
                if(color[it] == -1){
                    color[it] = color[el]==0 ?1:0;
                    q.push(it);
                }
                else if(color[it]==color[el]){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(bfs(i,graph,color)==false){
                    return false;
                }
            }
        }
        return true;
    }
};