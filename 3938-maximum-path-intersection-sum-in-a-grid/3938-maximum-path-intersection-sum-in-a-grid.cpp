class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans=-1e9;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i!=0 && i!=n-1 && j!=0 && j!=m-1)ans=max(ans,grid[i][j]);
            }
        }
        for(int i=0;i<n;i++){
            int sum=grid[i][0]+grid[i][1];
            int maxi=sum;
            for(int j=2;j<m;j++){
                sum=max(sum+grid[i][j],grid[i][j-1]+grid[i][j]);
                maxi=max(maxi,sum);
            }
            ans=max(ans,maxi);
        }
        for(int j=0;j<m;j++){
            int sum =grid[0][j]+grid[1][j];
            int maxi=sum;
            for(int i=2;i<n;i++){
                sum=max(sum+grid[i][j],grid[i-1][j]+grid[i][j]);
                maxi=max(maxi,sum);
            }
            ans=max(ans,maxi);
        }
        return ans;
    }
};