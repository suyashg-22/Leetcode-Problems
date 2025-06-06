class Solution {
private:
    bool dfs(int start, vector<vector<int>>& adjlist, vector<int>& vis, vector<int>& pathvis, vector<int>& ans) {
        vis[start] = 1;
        pathvis[start] = 1;
        
        for (auto it : adjlist[start]) {
            if (vis[it] == 0) {
                if (!dfs(it, adjlist, vis, pathvis, ans))
                    return false;
            } else if (pathvis[it] == 1) {
                // Cycle detected
                return false;
            }
        }
        
        pathvis[start] = 0;
        ans.push_back(start);  // push after processing all neighbors
        
        return true;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlist(numCourses);
        for (auto it : prerequisites) {
            int a = it[0];
            int b = it[1];
            adjlist[b].push_back(a);
        }
        
        vector<int> vis(numCourses, 0);
        vector<int> pathvis(numCourses, 0);
        vector<int> ans;
        
        for (int i = 0; i < numCourses; i++) {
            if (vis[i] == 0) {
                if (!dfs(i, adjlist, vis, pathvis, ans)) {
                    // cycle detected → impossible
                    return {};
                }
            }
        }
        
        reverse(ans.begin(), ans.end());  // because we added nodes after recursion
        
        return ans;
    }
};
