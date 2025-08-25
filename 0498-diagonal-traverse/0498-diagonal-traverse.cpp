class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m =mat[0].size();
        vector<int>arr;
        int i=0;
        int j=0;
        bool d =1;

        while(i<n && j<m){
            arr.push_back(mat[i][j]);
            if(j==m-1 && d==1){
                i+=1;
                d=0;
            }
            else if(i==0 && d==1){
                j+=1;
                d=0;
            }
            else if(i==n-1 && d==0){
                j+=1;
                d=1;
            }
            else if(j==0 && d==0){
                i+=1;
                d=1;
            }


            else if(d==0){
                i+=1;
                j-=1;
            }
            else{
                i-=1;
                j+=1;
            }

        }
        return arr;
    }
};