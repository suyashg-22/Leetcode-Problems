class Solution {
public:
    vector<vector<int>>arr;
    vector<int>dx{0,1,0,-1};
    vector<int>dy{-1,0,1,0};
    void bfs(vector<vector<int>>&grid){
        int n = grid.size();
        arr.assign(n,vector<int>(n,-1));
        queue<pair<pair<int,int>,pair<int,int>>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({{i,j},{i,j}});
                    arr[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            int size = q.size();
            for(int s = 0;s<size;s++){
                auto it = q.front();
                int i = it.first.first;
                int j = it.first.second;
                int ri = it.second.first;
                int rj = it.second.second;
                q.pop();
                for(int z=0;z<4;z++){
                    int ni = i+dx[z];
                    int nj = j+dy[z];
                    if(ni>=0 && ni<n && nj>=0 && nj<n){
                        if(arr[ni][nj]==-1){
                            arr[ni][nj]= abs(ri-ni)+abs(rj-nj);
                            q.push({{ni,nj},{ri,rj}});
                        }
                    }
                }
            }
        }
    }
    bool isvalid(int i,int j,int mid,int n,vector<vector<int>>&vis){
        if(arr[i][j]<mid)return false;
        if(i==n-1 && j==n-1)return true;
        vis[i][j]=1;
        int ans = false;
        for(int z=0;z<4;z++){
            int ni = i+dx[z];
            int nj = j+dy[z];
            if(ni>=0 && ni<n && nj>=0 && nj<n){
                if(vis[ni][nj]==0 && arr[ni][nj]>=mid){
                    if(isvalid(ni,nj,mid,n,vis)){
                        ans=true;
                        break;
                    }
                }
            }
        }
        return ans;
    }
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        bfs(grid);
        int l = 0;
        int h = min(arr[0][0],arr[n-1][n-1]);
        int ans = 0;
        while(l<=h){
            int mid = l+(h-l)/2;
            vector<vector<int>>vis(n,vector<int>(n,0));
            if(isvalid(0,0,mid,n,vis)){
                ans=mid;
                l=mid+1;
            }
            else h=mid-1;
        }
        return ans;
    }
};