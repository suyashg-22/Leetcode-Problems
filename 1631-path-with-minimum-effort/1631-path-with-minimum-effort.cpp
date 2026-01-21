#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const long long mod = 1000000009;

#define asc(x) (x).begin(), (x).end()
#define desc(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second
#define forl(i,a,b) for(ll i = (a); i < (b); i++)
#define fore(x,a) for(auto &x : a)
#define yes cout << "YES\n"
#define no cout << "NO\n"
// #define endl '\n'
class Solution {
public:
    int n,m;
    vector<vector<int>>*arr;

    int dijk(){
        vector<vector<int>>ans(m,vector<int>(n,INT_MAX));
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        ans[0][0]=0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int d = it.ff;
            int x = it.ss.ff;
            int y = it.ss.ss;

            for(int i=0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n){
                    int temp1 = abs((*arr)[nx][ny]-(*arr)[x][y]);
                    if(max(temp1,d)<ans[nx][ny]){
                        ans[nx][ny]=max(temp1,d);
                        pq.push({max(temp1,d),{nx,ny}});
                    }
                }
            }
        }
        return ans[m-1][n-1];
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        m= heights.size();
        n=heights[0].size();
        arr=&heights;
        
        return dijk();
    }
};