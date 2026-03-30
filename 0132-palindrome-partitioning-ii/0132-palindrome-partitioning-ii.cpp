class Solution {
public:
    int n;
    string *s;
    int dp[2001];
    vector<vector<bool>> pal;
    int rec(int level){
        if(level==n)return 0;
        if(dp[level]!=-1)return dp[level];

        int ans = 1e9;
        for(int k=level;k<n;k++){
            if(pal[level][k]){
                ans=min(ans,1+rec(k+1));
            }
        }
        return dp[level]=ans;
    }
    int minCut(string s) {
        this->n=s.size();
        this->s=&s;
        pal.assign(n, vector<bool>(n, false));
         for(int i = n-1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(s[i] == s[j] && (j-i <= 2 || pal[i+1][j-1])){
                    pal[i][j] = true;
                }
            }
        }

        memset(dp,-1,sizeof(dp));
        return rec(0)-1;
    }
};