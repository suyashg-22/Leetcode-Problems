class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int>pre(n);
        vector<int>suf(n);
        int i =0;
        int j =0;
        while(i<n){
            while(j<m && s[i]!=t[j]){
                j++;
            }
            pre[i]=j;
            i++;
            if(j!=m)j++;
        }
        i=n-1;
        j=m-1;
        while(i>=0){
            while(j>=0 && s[i]!=t[j]){
                j--;
            }
            suf[i]=j;
            i--;
            if(j!=-1)j--;
        }
        
        for(int i=0;i<n;i++){
            int l= (i-1>=0)?pre[i-1]:-1;
            int r= (i+1<n)?suf[i+1]:m;
            if(r-l-1>=1)return true;
        }
        return false;
    }
};