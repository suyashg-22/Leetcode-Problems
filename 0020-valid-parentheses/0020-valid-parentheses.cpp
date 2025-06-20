class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;
                else{
                    int el = st.top();
                    st.pop();
                    if((s[i]==')' && el == '(') || (s[i]==']'&& el=='[') || (s[i]=='}'&& el=='{')) continue;
                    else return false;
                }
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};