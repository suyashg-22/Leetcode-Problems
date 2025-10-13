class Solution {
public:
    vector<string>*arr;
    int size;
    int dp[601][101][101];
    int rec(int level,int m,int n){
        if(level==size){
            return 0;
        }
        if(dp[level][m][n]!=-1){
            return dp[level][m][n];
        }
        int ans = rec(level+1,m,n);
        int cnt0=0,cnt1=0;
        string s = (*arr)[level];
        for(int i=0;i<s.size();i++){
            if(s[i]=='0')cnt0+=1;
            else cnt1+=1;
        }
        if(m-cnt0>=0 && n-cnt1>=0){
            ans = max(ans,1+rec(level+1,m-cnt0,n-cnt1));
        }
        return dp[level][m][n]= ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        arr = &strs;
        size = strs.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,m,n);
    }
};