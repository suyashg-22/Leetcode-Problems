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
};