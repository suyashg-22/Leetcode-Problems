class Solution {
public:
    string greatestLetter(string s) {
        string q = "";  // To store uppercase letters
        
        for (int i = 0; i < s.size(); i++) {
            if (isupper(s[i])) {
                q += s[i];
            }
        }

        // Sorting q (uppercase letters) and s (original string)
        sort(q.begin(), q.end());
        sort(s.begin(), s.end());

        string ans = "";
        int i = s.length() - 1;
        int j = q.length() - 1;

        // Start comparing from the end of both sorted strings to find the greatest letter
        while (i >= 0 && j >= 0) {
            if (toupper(s[i]) == q[j]) {
                ans = q[j];  // Greatest letter found
                break;
            }
            // Move to the previous characters in both strings
            if (toupper(s[i]) > q[j]) {
                i--;
            } else {
                j--;
            }
        }

        // Return ans only if it was found, otherwise return empty string
        if (ans != "" && s.find(tolower(ans[0])) != string::npos) {
            return ans;
        }
        
        return "";  // If no such letter exists
    }
};
