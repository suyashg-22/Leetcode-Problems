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
    int n;
    vector<vector<int>>*arr;

    int bfs(){
        queue<pair<int,int>>q;

        if((*arr)[0][0]==1)return-1;
        if(n==1)return 1;
        q.push({0,0});
        (*arr)[0][0]=1;
        int level =1;

        while(!q.empty()){
            vector<int>dx{0,-1,-1,-1,0,1,1,1};
            vector<int>dy{-1,-1,0,1,1,1,0,-1};
            int size=q.size();
            for(int z=0;z<size;z++){
                auto p =q.front();
                q.pop();
                int x=p.ff;
                int y=p.ss;
                for(int i=0;i<8;i++){
                    for(int j=0;j<8;j++){
                        int nx = x+dx[i];
                        int ny = y+dy[j];
                        if(nx<n && nx>=0 && ny<n && ny>=0){
                            if((*arr)[nx][ny]==0){
                                if(nx==n-1 && ny==n-1)return level+1;
                                (*arr)[nx][ny]=1;
                                q.push({nx,ny});
                            }
                        }
                    }
                }
            }
            level+=1;
        }
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        this-> n =grid.size();
        arr=&grid;
        return bfs();
        
    }
};