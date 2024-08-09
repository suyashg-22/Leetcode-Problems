class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        for(int i=0;i<s.size();i++){
            char ch =s[i];
            if(ch=='('||ch=='{'||ch=='['){
                st.push(ch);
            }
            else{
                //ch = ) } ]
                if(st.empty()) return false;
                char topele = st.top();

                if(ch==')'&& topele=='('){
                    st.pop();
                }
                else if(ch=='}'&& topele=='{'){
                    st.pop();
                }
                else if(ch==']'&& topele=='['){
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }
        if(st.empty()) return true;
        return false;
    }
};