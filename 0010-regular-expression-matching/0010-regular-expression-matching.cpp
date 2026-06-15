class Solution {
public: 
    int n;
    int m;
    int dp[23][23];
    bool rec(int i,int j,string &s,string &p){
        if(i==n && j==m)return true;
        if(j==m)return false;
        if(dp[i][j]!=-1)return dp[i][j];

        bool ans = false;
        if(j+1<m && p[j+1]=='*'){
            if(p[j]=='.'){
                ans=ans|rec(i,j+2,s,p);
                if(i<n)ans=ans|rec(i+1,j,s,p);
                // ans=ans|rec(i+1,j+2,s,p);
            }
            else{
                ans = ans|rec(i,j+2,s,p);
                if(s[i]==p[j]){
                    if(i<n)ans = ans|rec(i+1,j,s,p);
                    // ans = ans|rec(i+1,j+2,s,p);
                }
            }
        }
        else if((i<n)&&(p[j]=='.' || s[i]==p[j])){
            ans = rec(i+1,j+1,s,p);
        }

        return dp[i][j]=ans;
    }
    bool isMatch(string s, string p) {
        this->n=s.size();
        this->m=p.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,0,s,p);
    }
};