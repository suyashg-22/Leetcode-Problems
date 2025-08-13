class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n =s.size();
        int maxil = 0;
        if(n==0)return 0;
        unordered_map<char,int>mpp;
        int l=0;
        int r =0;
        while(r<n){
            mpp[s[r]]+=1;
            while(mpp[s[r]]>1){
                mpp[s[l]]-=1;
                l+=1;
            }
            maxil =max(maxil,r-l+1);
            r+=1;
        }
        return maxil;
    }
};