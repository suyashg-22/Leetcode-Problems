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
    bool flag = true;
    vector<int>vis;

    void bfs(int start)
    {
        // prereq-*arr,n,ans,vis

        // vector<pair<int , int >> padosi{{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};
        queue<pair<int,int> > q;
        // starting push and mark it vis:
        q.push({start,1});
        vis[start]=1;

        // logic:
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int p=it.ff;
            int s=it.ss;

            for (auto x : (*arr)[p])
            {
                if (vis[x]==0)
                {
                    int c = (s==1)?2:1;
                    vis[x] = c;
                    q.push({x,c});
                }
                else{
                    if(vis[x]==s){
                        flag =false;
                        break;
                    }
                }
            }
            if(!flag)break;
        }
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        n = graph.size();
        arr = &graph;
        vis.assign(n,0);

        for(int i=0;i<n;i++){
            if(vis[i]==0){
                bfs(i);
                if(!flag)return false;
            }
        }
        return true;
    }
};