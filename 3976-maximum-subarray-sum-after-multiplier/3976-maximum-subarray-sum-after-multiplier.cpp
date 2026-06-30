using ll = long long;

class Solution {
public:
    ll rec(int level, int state, vector<int>& arr, int n, int k, vector<vector<ll>>& dp) {
        if (level == n) return 0;
        if (dp[level][state] != -1e18) return dp[level][state];
        
        ll ans = LONG_MIN;
        ll val = arr[level];
        ll m_val = (ll)arr[level] * k;
        ll d_val = arr[level] / k;   
        
        if (state == 0) {
            ans = val; 
                ans = max(ans, val + rec(level + 1, 0, arr, n, k, dp));
                ans = max(ans, val + rec(level + 1, 1, arr, n, k, dp));
                ans = max(ans, val + rec(level + 1, 2, arr, n, k, dp));
        }
        else if (state == 1) {
            ans = m_val;
                ans = max(ans, m_val + rec(level + 1, 1, arr, n, k, dp));
                ans = max(ans, m_val + rec(level + 1, 3, arr, n, k, dp));
        }
        else if (state == 2) {
            ans = d_val;
                ans = max(ans, d_val + rec(level + 1, 2, arr, n, k, dp));
                ans = max(ans, d_val + rec(level + 1, 3, arr, n, k, dp));
            
        }
        else { 
            ans = val;
                ans = max(ans, val + rec(level + 1, 3, arr, n, k, dp));
        }
        
        return dp[level][state] = ans;
    }
    
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<ll>> dp(n, vector<ll>(4, -1e18)); 
        
        ll ans = LONG_MIN;
        
        for (int i = 0; i < n; i++) {
            ans = max(ans, rec(i, 0, nums, n, k, dp));
            ans = max(ans, rec(i, 1, nums, n, k, dp));
            ans = max(ans, rec(i, 2, nums, n, k, dp));
        }
        
        return ans;
    }
};