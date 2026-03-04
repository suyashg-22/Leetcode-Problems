class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int cnt =0;
        int n = mat.size();
        int m = mat[0].size();
        vector<int>rsum(n,0);
        vector<int>csum(m,0);
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++)rsum[i]+=mat[i][j];
        }
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                csum[j]+=mat[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1 && rsum[i]==1 && csum[j]==1)cnt+=1;
            }
        }
        return cnt;
    }
};