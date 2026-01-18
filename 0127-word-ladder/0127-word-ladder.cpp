#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long mod = 1000000009;

#define asc(x) (x).begin(), (x).end()
#define desc(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second
#define forl(i, a, b) for (int i = (a); i < (b); i++)
#define fore(x, a) for (auto& x : a)
#define yes cout << "YES\n"
#define no cout << "NO\n"
// #define endl '\n'

class Solution {
public:
    unordered_map<string, vector<int>> mpp;
    string s1;
    string s2;
    vector<vector<int>> adj;
    int n;
    vector<string>* arr;
    vector<int> vis;
    int index = -1;

    void bfs() {
        // prereq-*adj,n,ans,vis

        // vector<pair<int, int>> padosi{{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};
        queue<int> q;

        // starting push and mark it vis:
        q.push(n);
        vis[n] = 0;
        int d = 1;

        // logic:
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int p = q.front();
                q.pop();

                for (auto x : adj[p]) {
                    if (vis[x]==-1) {
                        vis[x] = d;
                        if(x==index)return;
                        q.push(x);
                    }
                }
            }
            d += 1;
        }
    }

    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        this->s1 = beginWord;
        this->s2 = endWord;
        this->n = wordList.size();
        this->arr = &wordList;
        vis.assign(n + 1, -1);
        adj.resize(n+1);

        for (int i = 0; i < s1.size(); i++) {
            string temp = s1;
            temp[i] = '*';
            mpp[temp].push_back(n);
        }
        for (int i = 0; i < wordList.size(); i++) {
            if (wordList[i] == s1)
                continue;

            if (wordList[i] == s2)
                index = i;

            string s = wordList[i];
            int m = s.size();
            for (int j = 0; j < m; j++) {
                string temp = s;
                temp[j] = '*';
                if (mpp.count(temp)) {
                    for (auto x : mpp[temp]) {
                        adj[x].pb(i);
                        adj[i].pb(x);
                    }
                }
                mpp[temp].pb(i);
            }
        }
        bfs();
        if(index==-1)return 0;
        if(vis[index]==-1)return 0;
        return vis[index]+1;
    }
};

