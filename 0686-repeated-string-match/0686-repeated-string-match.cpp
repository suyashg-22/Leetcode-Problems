class Solution {
public:
    // Standard Rabin-Karp matching function
    bool rabinKarp(const string& source, const string& target) {
        int n = source.size();
        int m = target.size();
        if (n < m) return false;

        long long p = 31;
        long long mod = 1e9 + 7;
        
        long long targetHash = 0;
        long long currentHash = 0;
        long long p_pow = 1;

        // 1. Calculate the hash for the target and the first window of the source
        for (int i = 0; i < m; i++) {
            targetHash = (targetHash * p + (target[i] - 'a' + 1)) % mod;
            currentHash = (currentHash * p + (source[i] - 'a' + 1)) % mod;
            
            // Calculate p^(m-1) for the rolling hash removal step
            if (i < m - 1) {
                p_pow = (p_pow * p) % mod;
            }
        }

        // Check if the very first window matches
        if (currentHash == targetHash) {
            // Double-check string to avoid hash collisions (extremely rare but mathematically possible)
            if (source.substr(0, m) == target) return true;
        }

        // 2. Slide the window using the Rolling Hash formula
        for (int i = m; i < n; i++) {
            // Remove the character that is left behind
            long long leftCharVal = (source[i - m] - 'a' + 1) * p_pow % mod;
            currentHash = (currentHash - leftCharVal + mod) % mod; // + mod to handle negative numbers in C++
            
            // Shift the window and add the new character
            currentHash = (currentHash * p + (source[i] - 'a' + 1)) % mod;

            // Check for match
            if (currentHash == targetHash) {
                if (source.substr(i - m + 1, m) == target) return true;
            }
        }

        return false;
    }

    int repeatedStringMatch(string a, string b) {
        string source = "";
        int count = 0;

        // Build the minimum repeated string needed to match the length of b
        while (source.size() < b.size()) {
            source += a;
            count++;
        }

        // Check if b is a substring
        if (rabinKarp(source, b)) {
            return count;
        }

        // Check the spill-over case by appending 'a' exactly one more time
        source += a;
        if (rabinKarp(source, b)) {
            return count + 1;
        }

        // If it's in neither, it's impossible
        return -1;
    }
};