class Solution {
public:
    void rec(int c1,int c2,string&s, vector<string>&ans){
        if(c1==0 && c2==0){
            ans.push_back(s);
            return;
        }
        s+='(';
        if(c1>0)rec(c1-1,c2,s,ans);
        s.pop_back();
        s+=')';
        if(c2>c1)rec(c1,c2-1,s,ans);
        s.pop_back();
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s ="";
        rec(n,n,s,ans);
        return ans;
    }
};