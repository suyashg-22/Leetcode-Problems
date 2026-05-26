class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        vector<int>arr(52,0);
        int cnt =0;
        for(int i=0;i<n;i++){
            char c = word[i];
            int x =0;
            if(isupper(c)){
                x = c-'A';
            }
            else{
                x= 26 + c-'a';
            }
            if(arr[x]==0)arr[x]+=1;
        }
        for(int i=0;i<26;i++){
            if(arr[i]+arr[i+26]==2)cnt+=1;
        }
        return cnt;
    }
};