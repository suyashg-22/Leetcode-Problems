class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n =grid.size();
        int m =grid[0].size();
        int shift = k%(n*m);
        int r= shift/m;
        int c= shift%m;
        vector<vector<int>>ans(n,vector<int>(m));
        int i =r;
        int j =c;
        int ii=0;
        int jj=0;
        while(ii<n && jj<m){
            ans[i][j]=grid[ii][jj];
            jj+=1;
            if(jj%m==0){
                jj=0;
                ii+=1;
            }
            j+=1;
            if(j%m==0){
                j=0;
                i+=1;
                if(i%n==0)i=0;
            }
        }
        return ans;
    }
};