class Solution {
public:
    bool isValid(string s) {
        int n= s.size();
        stack<char>st;
        st.push(s[n-1]);
        for(int i=n-2;i>=0;i--){
            char c = s[i];
            if(c==')' || c=='}' || c==']'){
                st.push(c);
            }
            else{
                if(st.empty())return false;
                char cc = st.top();
                if(c=='('){
                    if(cc!=')')return false;
                    st.pop();
                }
                else if(c=='{'){
                    if(cc!='}')return false;
                    st.pop();    
                }
                else{
                    if(cc!=']')return false;
                    st.pop();
                }
            }
        }
        if(st.size()>0)return false;
        return true;
    }
};