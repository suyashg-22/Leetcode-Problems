class Solution {
public:
    string smallestSubsequence(string s) {
        int n =s.size();
        vector<int>vis(26,0);
        unordered_map<char,int>mpp;
        stack<char>st;
        for(int i=0;i<n;i++){
            mpp[s[i]]=i;
        }
        st.push(s[0]);
        vis[s[0]-'a']=1;
        for(int i=1;i<n;i++){
            char c = s[i];
            if(vis[c-'a']==1)continue;
            while(!st.empty() && st.top()>c && mpp[st.top()]>i){
                vis[st.top()-'a']=0;
                st.pop();
            }
            vis[c-'a']=1;
            st.push(c);
        }
        string ans="";
        while(!st.empty()){
            ans+= st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};