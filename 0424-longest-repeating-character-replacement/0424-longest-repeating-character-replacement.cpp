class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>hash(26,0);
        int n = s.size();
        int l=0;
        int r=0;
        int maxif=0;
        int ans=0;
        while(r<n){
            char c = s[r];
            hash[c-'A']+=1;
            maxif=max(maxif,hash[c-'A']);
            while(l<r && r-l+1-maxif>k){
                hash[s[l]-'A']-=1;
                l++;
                maxif=0;
                for(int i=0;i<26;i++)maxif=max(maxif,hash[i]);
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};