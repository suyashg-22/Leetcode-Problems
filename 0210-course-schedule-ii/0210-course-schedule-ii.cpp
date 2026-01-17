class Solution
{
public:
    int n;
    vector<vector<int>> adj;
    vector<int> inor;
    vector<int> ans;

    void bfs()
    {
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (inor[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int p = q.front();
            q.pop();
            ans.push_back(p);
            for (auto x : adj[p])
            {
                inor[x] -= 1;
                if (inor[x] == 0)
                    q.push(x);
            }
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        this->n = numCourses;
        this->adj.resize(n);
        this->inor.assign(n, 0);
        ans.clear();
        for (int i = 0; i < prerequisites.size(); i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inor[prerequisites[i][0]]++;
        }
        bfs();
        if(ans.size()!=n)return {};
        return ans;
    }
};