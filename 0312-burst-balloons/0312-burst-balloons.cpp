class Solution {
public:
    int dp[303][303];
    
    int rec(int i, int j, vector<int>& arr) {
        if(i > j) return 0;        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = 0;
        for(int k = i; k <= j; k++) {
            int cost = arr[i-1] * arr[k] * arr[j+1];
            ans = max(ans, cost + rec(i, k-1, arr) + rec(k+1, j, arr));
        }
        
        return dp[i][j] = ans;
    }
    
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n = nums.size();
        
        memset(dp, -1, sizeof(dp));
        return rec(1, n - 2, nums); 
    }
};