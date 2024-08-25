class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int row = accounts.size();
        int col = accounts[0].size();
        
        int sum =0;
        
        for(int i=0;i<row;i++){
            
            for(int j=0;j<col;j++){
                sum += accounts[i][j];        
            }
            if(sum>maxi){
                maxi = sum;
            }
            sum =0;
        }
        
        return maxi;
    }
};