class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        string ans="";
        for(int i=0;i<n/2;i++){
            ans+=s[i];
        }
        sort(ans.begin(),ans.end());
        if(n%2==1)ans+=s[n/2];
        int l= (n%2==1)?ans.size()-2:ans.size()-1;
        while(l>=0){
            ans+=ans[l];
            l--;
        }
        return ans;
    }
};