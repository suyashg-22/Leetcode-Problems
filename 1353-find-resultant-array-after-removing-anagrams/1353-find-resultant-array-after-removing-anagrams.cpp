class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string>arr;
        arr.push_back(words[0]);
        for(int i=1;i<n;i++){
            string s = words[i];
            if(words[i-1].size()!=words[i].size()){
                arr.push_back(s);
                continue;
            }
            sort(words[i-1].begin(),words[i-1].end());
            sort(words[i].begin(),words[i].end());
            if(words[i-1]==words[i]){
                continue;
            }
            else{
                arr.push_back(s);
            }
        }
        return arr;
    }
};