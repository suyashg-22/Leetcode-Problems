class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m=matrix[0].size();
        int flag = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    if(j==0){
                        flag=0;
                        matrix[i][0]=0;
                    }
                    else{
                        matrix[0][j]=0;
                        matrix[i][0]=0;
                    }
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int f1=(j==0)?flag:matrix[0][j];
                int f2=matrix[i][0];
                if(f1==0 || f2==0){
                    matrix[i][j]=0;
                }
            }
        }
        return;
    }
};