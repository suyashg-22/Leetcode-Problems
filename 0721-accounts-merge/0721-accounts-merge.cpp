class Solution {
public:
    int findParent(int node, vector<int>& parent) {
        if (parent[node] == node)return node;
        return parent[node] = findParent(parent[node], parent);
    }

    void union_find(int parentNode, int x, vector<int>& parent) {
        int rootParent = findParent(parentNode, parent);
        int rootX = findParent(x, parent);
        if (rootParent == rootX)
            return;
        parent[rootX] = rootParent;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        int n = accounts.size();
        map<string, int> m;
        vector<int> parent(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (int i = 0; i < n; i++) {
            vector<string> current = accounts[i];
            for (int j = 1; j < current.size(); j++) {
                if (m.find(current[j]) == m.end())
                    m[current[j]] = i;
                else
                    union_find(m[current[j]], i, parent);
            }
        }


        map<int, vector<string>> indexes;
        for (auto& entry : m) {
            int parentIndex = findParent(entry.second, parent);
            indexes[parentIndex].push_back(entry.first);
        }

        vector<vector<string>> result;
        for (auto& entry : indexes) {
            vector<string> current;
            current.push_back(accounts[entry.first][0]);
            for (auto& str : entry.second)
                current.push_back(str);
            sort(current.begin() + 1, current.end());
            result.push_back(current);
        }

        return result;
    }
};