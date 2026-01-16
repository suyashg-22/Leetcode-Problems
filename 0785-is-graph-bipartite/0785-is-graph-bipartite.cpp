#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
const long long mod = 1000000009;

#define asc(x) (x).begin(), (x).end()
#define desc(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second
#define forl(i, a, b) for (int  i = (a); i < (b); i++)
#define fore(x, a) for (auto &x : a)
#define yes cout << "YES\n"
#define no cout << "NO\n"
// #define endl '\n'

class Solution
{
public:
    vector<vector<int>> *arr;
    int n;
    vector<int>vis;

    bool bfs(int start)
    {
        // prereq-*arr,n,ans,vis

        // vector<pair<int , int >> padosi{{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};
        queue<int> q;
        // starting push and mark it vis:
        q.push(start);
        vis[start]=1;

        // logic:
        while (!q.empty())
        {
            int p = q.front();
            q.pop();

            for (auto x : (*arr)[p])
            {
                if (vis[x]==0)
                {
                    int c = (vis[p]==1)?2:1;
                    vis[x] = c;
                    q.push(x);
                }
                else{
                    if(vis[x]==vis[p]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        n = graph.size();
        arr = &graph;
        vis.assign(n,0);

        for(int i=0;i<n;i++){
            if(vis[i]==0){
                bool flag = bfs(i);
                if(!flag)return false;
            }
        }
        return true;
    }
};