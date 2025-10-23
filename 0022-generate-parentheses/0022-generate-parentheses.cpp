class Solution {
public:

    void rec(int n1, int n2, string &s,vector<string>&ans) {
        if (n1 > n2) return;
        if (n1 == 0 && n2 == 0) {
            ans.push_back(s);
            return;
        }

        if (n1 > 0) {
            s.push_back('(');
            rec(n1 - 1, n2, s,ans);
            s.pop_back();
        }
        if (n2 > 0) {
            s.push_back(')');
            rec(n1, n2 - 1, s,ans);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        ans.clear();
        string s;
        rec(n, n, s,ans);
        return ans;
    }
};
