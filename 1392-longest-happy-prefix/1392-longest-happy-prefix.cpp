class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int>pi(n,0);
        int l =0;
        int i=1;
        while(i<n){
            if(s[i]==s[l]){
                l+=1;
                pi[i]=l;
                i+=1;
            }
            else{
                if(l!=0){
                    l=pi[l-1];
                }
                else{
                    pi[i]=0;
                    i+=1;
                }
            }
        }
        string ans="";
        for(int i=0;i<pi[n-1];i++)ans+=s[i];
        return ans;
    }
};