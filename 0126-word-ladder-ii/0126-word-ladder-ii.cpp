class Solution {
public:
    unordered_set<string>st;
    unordered_map<string,int>mpp;
    void dfs(string word,string beginWord,vector<string>&temp,vector<vector<string>>&ans){
        if(word==beginWord){
            reverse(temp.begin(),temp.end());
            ans.push_back(temp);
            reverse(temp.begin(),temp.end());
            return ;
        }
        int level=mpp[word];
        for(int i=0;i<word.size();i++){
            for(char c='a';c<='z';c++){
                string ss = word;
                ss[i]=c;
                if(mpp.count(ss) && mpp[ss]+1==level){
                    temp.push_back(ss);
                    dfs(ss,beginWord,temp,ans);
                    temp.pop_back();
                }
            }
        }
        return;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        for(auto s:wordList){
            st.insert(s);
        }
        queue<string>q;
        st.erase(beginWord);
        q.push(beginWord);
        mpp[beginWord]=1;
        int level=1;
        while(!q.empty()){
            int size=q.size();
            for(int k=0;k<size;k++){
                string s = q.front();
                q.pop();
                for(int i=0;i<s.size();i++){
                    for(char c='a';c<='z';c++){
                        string temp = s;
                        temp[i]=c;
                        if(st.find(temp)!=st.end()){
                            st.erase(temp);
                            q.push(temp);
                            mpp[temp]=level+1;
                        }
                    }
                }
            }
            level++;
        }

        if(!mpp.count(endWord))return {};
        vector<vector<string>>ans;
        vector<string>temp;
        temp.push_back(endWord);
        dfs(endWord,beginWord,temp,ans);
        return ans;
    }
};