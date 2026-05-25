class Solution {
public:
    int n;
    int m1;
    int m2;
    int dp[100001];
    vector<int>pre;

    bool rec(int level, string& s) {
        // We calculate reachability for the current level
        int l = level - m2;
        int r = level - m1;
        int cnt = 0;
        
        if (s[level] == '0') {
            if (r < 0) {
                cnt = 0;
            }
            else if (l <= 0) {
                cnt = pre[r];
            }
            else {
                cnt = pre[r] - pre[l-1];
            }
        }
        
        // FIX 1: Set dp state for the CURRENT level
        dp[level] = (cnt > 0) ? 1 : 0;
        
        // FIX 2: Build the prefix array dynamically here, counting REACHABLE points
        pre[level] = pre[level - 1] + dp[level];
        
        // Base Case: If we just processed the final index, return its reachability
        if (level == n - 1) {
            return dp[level] == 1;
        }

        // FIX 3: ALWAYS move to the next level, even if current level is unreachable
        return rec(level + 1, s);
    }

    bool canReach(string s, int minJump, int maxJump) {
        this->n = s.size();
        this->m1 = minJump;
        this->m2 = maxJump;
        
        if (s[n-1] == '1') return false;
        
        memset(dp, -1, sizeof(dp));
        pre.resize(n, 0); // Initialize vector with 0s
        
        // Base cases setup for index 0
        dp[0] = 1; 
        pre[0] = 1; 
        
        return rec(1, s);
    }
};