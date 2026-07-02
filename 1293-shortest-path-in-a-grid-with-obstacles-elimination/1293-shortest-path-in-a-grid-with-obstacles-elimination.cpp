class Solution {
public:
    int bfs(vector<vector<int>>&arr,int k){
        int n = arr.size();
        int m = arr[0].size();
        if(n==1 && m==1)return 0;
        vector<int>dx{0,1,0,-1};
        vector<int>dy{-1,0,1,0};
        vector<vector<int>>kleft(n,vector<int>(m,-1));
        queue<pair<int,pair<int,int>>>q;
        kleft[0][0]=k;
        q.push({k,{0,0}});
        int d =1;
        while(!q.empty()){
            int size = q.size();
            for(int s=0;s<size;s++){
                auto it = q.front();
                q.pop();
                int kk = it.first;
                int i = it.second.first;
                int j = it.second.second;
                for(int z=0;z<4;z++){
                    int ni = i+dx[z];
                    int nj = j+dy[z];
                    if(ni>=0 && ni<n && nj>=0 && nj<m){
                        if(ni==n-1 && nj==m-1)return d;
                        int nkk = (arr[ni][nj]==1)?kk-1:kk;
                        if(nkk>=0){
                            if(kleft[ni][nj]==-1){
                                q.push({nkk,{ni,nj}});
                                kleft[ni][nj]=nkk;
                            }
                            else if(nkk>kleft[ni][nj]){
                                q.push({nkk,{ni,nj}});
                                kleft[ni][nj]=nkk;
                            }
                        }
                    }
                }
            }
            d+=1;
        }
        return -1;
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        return bfs(grid,k);
    }
};