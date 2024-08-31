class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        int n = s.length();
        string result = "";
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                if (!st.empty()) {  // Only add if it's not the outermost '('
                    result += s[i];
                }
                st.push(s[i]);
            } else if (s[i] == ')') {
                st.pop();
                if (!st.empty()) {  // Only add if it's not the outermost ')'
                    result += s[i];
                }
            }
        }
        
        return result;
    }
};
