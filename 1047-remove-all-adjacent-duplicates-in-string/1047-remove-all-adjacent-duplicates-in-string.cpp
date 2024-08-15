class Solution {
public:
    string removeDuplicates(string s) {
        string result;
        for (char c : s) {
            if (!result.empty() && result.back() == c) {
                result.pop_back();  // Remove the last character if it's the same as the current one
            } else {
                result.push_back(c);  // Append the current character otherwise
            }
        }
        return result;
    }
};
