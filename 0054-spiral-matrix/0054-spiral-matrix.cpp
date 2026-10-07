class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m= matrix[0].size();
        vector<int>ans;
        int c1=0;
        int c2=m-1;
        int r1=0;
        int r2=n-1;
        while(c1<=c2 && r1<=r2){
            if(c1<=c2 && r1<=r2){
                for(int j=c1;j<=c2;j++)ans.push_back(matrix[r1][j]);
                r1++;
            }
            if(c1<=c2 && r1<=r2){
                for(int i=r1;i<=r2;i++)ans.push_back(matrix[i][c2]);
                c2--;
            }
            if(c1<=c2 && r1<=r2){
                for(int j=c2;j>=c1;j--)ans.push_back(matrix[r2][j]);
                r2--;
            }
            if(c1<=c2 && r1<=r2){
                for(int i=r2;i>=r1;i--)ans.push_back(matrix[i][c1]);
                c1++;
            }
        }
        return ans;
    }
};