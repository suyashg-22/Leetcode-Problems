class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        int ans = 0;
        int openCount = 0;  // Track the number of unmatched opening '('

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                openCount++;  // Increment for an opening '('
            } else {  // s[i] is ')'
                if (openCount > 0) {
                    openCount--;  // Match it with an opening '('
                } else {
                    ans++;  // We have an unmatched ')', increment answer
                }
            }
        }

        // Any unmatched '(' will need to be closed
        ans += openCount;

        return ans;
    }
};
