class Solution {
public:
    string removeOuterParentheses(string s) {
        int n= s.size();
        stack<char>st;
        string ans = "";
        string temp = "";
        int size =0;
        for(int i=0;i<n;i++){
            if(st.empty()){
                if(!temp.empty())temp.erase(0,1);
                if(!temp.empty())temp.pop_back();
                ans+=temp;
                temp="";
            }
            
            if(s[i]=='('){
                st.push('(');
            }
            else{
                if(!st.empty())st.pop();
            }
            temp+=s[i];
        }
        if(st.empty()){
                if(!temp.empty())temp.erase(0,1);
                if(!temp.empty())temp.pop_back();
                ans+=temp;
                temp="";
            }
        return ans;
    }
};