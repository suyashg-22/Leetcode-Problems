#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long mod = 1000000009;

#define asc(x) (x).begin(), (x).end()
#define desc(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second
#define forl(i, a, b) for (ll i = (a); i < (b); i++)
#define fore(x, a) for (auto& x : a)
#define yes cout << "YES\n"
#define no cout << "NO\n"
// #define endl '\n'

// bool check(){
//
// }

// ll bs(vector<ll>& arr,ll l,ll h,ll ans){
//     ll n  = arr.size();
//     ll lo = l;
//     ll hi = h;
//     while(lo <= hi){
//         ll mid = lo + (hi - lo) / 2;
//         if(check() == 1){
//             ans = mid;
//             hi  = mid - 1;
//         }
//         else lo = mid + 1;
//     }
//     return ans;
// }

// ll rec(){
//     //prunning

//     //base case

//     //cache check

//     //transitions/compute

//     //save and return
// }

// //graph
// void bfs(){
//     //prereq-*adj,n,ans,vis

//     // vector<pair<ll, ll>> padosi{{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};
//     queue<ll>q;

//     //starting push and mark it vis:
//
//     //logic:
//     while(!q.empty()){
//         ll p = q.front();
//         q.pop();
//         ans.pb(p);

//         for(auto x:(*adj)[p]){
//             if(!vis[x]){
//                 vis[x]=1;
//                 q.push(x);
//             }
//         }
//     }
// }

// //graph
// void dfs_rec(ll start){
//     //prereq-*adj,n,ans,vis

//     vis[start]=1;
//     ans.pb(start);
//     for(auto x: (*adj)[start]){
//         if(!vis[x]){
//             dfs_rec(x);
//         }
//     }
// }

class Solution {
public:
    vector<vector<int>>* adj;
    int n;
    vector<int> vis;
    vector<int> ans;

    int dfs_rec(int node) {
        // prereq-*adj,n,ans,vis

        // base case:
        if ((*adj)[node].size()==0) {
            vis[node] = 2;
            return 1;
        }

        // transitions:
        vis[node] = 1;
        int cnt = 0;
        int size = (*adj)[node].size();
        for (auto x : (*adj)[node]) {
            if (vis[x]==0) {
                int f = dfs_rec(x);
                cnt += (f == 1) ? 1 : 0;
            } 
            else if (vis[x] == 2) {
                cnt += 1;
            }
            else{
                vis[x]=3;
                break;
            }
        }

        if (cnt == size) {
            vis[node]=2;
            return 1;
        }
        vis[node] = 3;
        return 0;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        adj = &graph;
        this->n = graph.size();
        this->vis.assign(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs_rec(i);
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(vis[i]==2)ans.pb(i);
        }
        return ans;
    }
};
