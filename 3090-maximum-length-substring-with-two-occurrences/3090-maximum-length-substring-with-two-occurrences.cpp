class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int>mpp;
            for(int j=i;j<n;j++){
                char c = s[j];
                mpp[c]+=1;
                bool flag= true;
                for(auto it:mpp){
                    if(it.second>2)flag = false;
                }
                if(flag)maxi=max(maxi,j-i+1);
            }
        }
        return maxi;
    }
};