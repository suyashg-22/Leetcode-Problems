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
                arr[x]+=1;
            }
            else{
                x= 26 + c-'a';
                if(arr[x-26]==0)arr[x]+=1;
                else arr[x]=0;
            }
        }
        for(int i=0;i<26;i++){
            if(arr[i]>0 && arr[i+26]>0)cnt+=1;
        }
        return cnt;
    }
};