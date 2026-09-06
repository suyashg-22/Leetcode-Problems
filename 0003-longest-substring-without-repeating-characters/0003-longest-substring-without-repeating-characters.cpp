class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n= s.size();
        unordered_map<char,int>mpp;
        int maxi=0;
        int j=0;
        int i=0;
        while(j<n){
            char c = s[j];
            mpp[c]++;
            while(i<j && mpp[c]>1){
                char cc = s[i];
                mpp[cc]--;
                if(mpp[cc]<=0)mpp.erase(cc);
                i++;
            }
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};