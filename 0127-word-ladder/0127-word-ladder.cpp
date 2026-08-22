class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st;
        for(auto s:wordList){
            st.insert(s);
        }
        queue<pair<string,int>>q;
        st.erase(beginWord);
        q.push({beginWord,1});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            string s = it.first;
            int d = it.second;
            for(int i=0;i<s.size();i++){
                for(char c='a';c<='z';c++){
                    string temp = s;
                    temp[i]=c;
                    if(st.find(temp)!=st.end()){
                        st.erase(temp);
                        q.push({temp,d+1});
                        if(temp==endWord)return d+1;
                    }
                }
            }
        }
        return 0;
    }
};