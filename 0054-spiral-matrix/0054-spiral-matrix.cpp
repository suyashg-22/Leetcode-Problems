class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int top=0,left=0,right=m-1,botm=n-1;
        vector<int>ans;
        while( top<=botm && left<=right){
            for(int i=left;i<=right;i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            for(int i =top;i<=botm;i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(top<=botm){
                for(int i=right;i>=left;i--){
                    ans.push_back(matrix[botm][i]);
                }
                botm--;
            }
            if(left<=right){
                for(int i=botm;i>=top;i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};