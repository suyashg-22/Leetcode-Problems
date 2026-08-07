class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool flag= 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    (j==0)?flag=0:matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                bool f1=1;
                bool f2=(matrix[i][0]==0)?0:1;
                if(j==0){
                    if(flag==0)f1=0;
                    else f1=1;
                }
                else{
                    if(matrix[0][j]==0)f1=0;
                    else f1=1;
                }
                if(f1==0 || f2==0)matrix[i][j]=0;
            }
        }
    }
};