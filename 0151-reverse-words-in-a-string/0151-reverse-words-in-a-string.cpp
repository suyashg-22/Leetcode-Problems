class Solution {
public:
    string reverseWords(string s) {
        int n= s.size();
        stack<string>st;
        string temp="";
        for(int i=0;i<n;i++){
            if(isspace(s[i])){
                if(temp.size()>=1){
                    st.push(temp);
                    temp="";
                }    
            }
            else
                temp+=s[i];
        }
        if(temp.size()>=1){
            st.push(temp);
            temp="";
        }    
        string ans ="";
        while(!st.empty()){
            ans+=st.top();
            ans+=" ";
            st.pop();
        }
        ans.pop_back();
        return ans;
    }
};