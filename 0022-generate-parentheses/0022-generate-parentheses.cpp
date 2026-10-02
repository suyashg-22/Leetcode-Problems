class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n = s.size();
        for(int i=n-1;i>=0;i--){
            char c= s[i];
            if(c==')'||c=='}'||c==']'){
                st.push(c);
            }
            else{
                if(st.empty())return false;
                else if(c=='(' && st.top()==')')st.pop();
                else if(c=='{' && st.top()=='}')st.pop();
                else if(c=='[' && st.top()==']')st.pop();
                else return false;
            }
        }
        if(!st.empty())return false;
        return true;
    }
    void rec(int c1,int c2,string&s, vector<string>&ans){
        if(c1==0 && c2==0){
            if(isValid(s))ans.push_back(s);
            return;
        }
        s+='(';
        if(c1>0)rec(c1-1,c2,s,ans);
        s.pop_back();
        s+=')';
        if(c2>0)rec(c1,c2-1,s,ans);
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