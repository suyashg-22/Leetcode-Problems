class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        map<char,bool> mp;
        for(int i=0 ;i<allowed.length();i++){
            mp[allowed[i]]=1;
        }
        int count =0;
        for(int i=0;i<words.size();i++){
            string curword = words[i];
            for(int j=0;j<curword.length();j++){
                if(mp[curword[j]] != 1){
                    count --;
                    break;
                }
            }
            count +=1;
        }
        return count;
    }
};