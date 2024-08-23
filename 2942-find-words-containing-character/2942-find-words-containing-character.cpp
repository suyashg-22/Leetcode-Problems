class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        
        vector<int>arr;
        for(int i=0;i<words.size();i++){
            int n = words[i].size();
            string str = words[i];
            for(int j=0;j<n;j++){
                if(str[j]==x){
                    arr.push_back(i);
                    break;
                }
            }
        }
        return arr;
    }
};