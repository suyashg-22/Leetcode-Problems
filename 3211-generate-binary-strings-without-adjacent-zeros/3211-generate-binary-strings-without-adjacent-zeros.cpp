class Solution {
public:
    int n;
    vector<string>ans;

    void rec(int level, string s) {
        if (level == n) {
            ans.push_back(s);
            return;
        }

        s+='1';
        rec(level + 1, s);
        s.pop_back();
        if (s.size()==0 || (s.size()>0 && s[s.size()-1] != '0')) {
            s+='0';
            rec(level + 1, s);
            s.pop_back();
        }

    }
    vector<string> validStrings(int n) {
        this->n=n;
        rec(0,"");
        return ans;
    }
};