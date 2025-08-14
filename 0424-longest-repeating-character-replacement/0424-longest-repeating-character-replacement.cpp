class Solution {
public:
    int characterReplacement(string s, int k) {
        int n =s.size();
        int l = 0;
        int r =0;
        unordered_map<char,int>mpp;
        int maxf =0;
        int maxl = 0;
        while(r<n){
            mpp[s[r]]+=1;
            maxf=max(maxf,mpp[s[r]]);
            int temp = r-l+1-maxf;
            if(temp>k){
                mpp[s[l]]-=1;
                l+=1;
            }
            if(temp<=k)maxl = max(maxl,r-l+1);
            r+=1;
        }
        return maxl;
    }
};