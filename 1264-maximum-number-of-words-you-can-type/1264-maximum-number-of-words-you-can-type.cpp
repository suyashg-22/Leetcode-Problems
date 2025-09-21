class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<char,int>mpp;
        int n=text.size();
        int m=brokenLetters.size();
        for(int i=0;i<m;i++){
            mpp[brokenLetters[i]]+=1;
        }
        int cnt =0;
        bool flag = true;
        int i=0;
        while(i<n){
            if(isspace(text[i])){
                if(flag ){
                    cnt+=1;
                }
                flag = true;
                i+=1;
                continue;
            }
            else if(mpp[text[i]]>0){
                flag = false;
                while(i<n && !isspace(text[i])){
                    i+=1;
                }
            }
            else i+=1;
        }
        if(flag)cnt+=1;
        return cnt;
    }
};