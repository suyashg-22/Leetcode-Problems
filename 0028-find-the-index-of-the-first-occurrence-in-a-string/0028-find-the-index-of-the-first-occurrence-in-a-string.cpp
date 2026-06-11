class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        int m = haystack.size();
        
        if (n == 0) return 0;
        
        // Phase 1: Build the pi (LPS) array
        // Initialize an array of size n with 0s
        vector<int> pi(n, 0); 
        int l = 0;
        int i = 1;
        
        while (i < n) {
            if (needle[i] == needle[l]) {
                l += 1;
                pi[i] = l; // Assign directly instead of push_back
                i += 1;
            } else {
                if (l != 0) {
                    // Fall back to the previous longest prefix
                    // Do NOT increment i here! We must re-evaluate.
                    l = pi[l - 1]; 
                } else {
                    // If l is 0, there is no prefix, so pi[i] is 0
                    pi[i] = 0;
                    i += 1;
                }
            }
        }
        
        // Phase 2: Match needle in haystack
        i = 0; // index for haystack
        int j = 0; // index for needle
        
        while (i < m) {
            if (haystack[i] == needle[j]) {
                i += 1;
                j += 1;
                if (j == n) {
                    return i - n; // Match found!
                }
            } else {
                if (j != 0) {
                    // Fall back in the needle based on the pi array
                    // Do NOT increment i here!
                    j = pi[j - 1];
                } else {
                    // If we are at the very start of the needle and it doesn't match,
                    // ONLY THEN do we move forward in the haystack.
                    i += 1;
                }
            }
        }
        
        return -1;
    }
};