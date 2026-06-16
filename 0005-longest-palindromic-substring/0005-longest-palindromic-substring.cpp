class Solution {
public:
    int n;
    int dp[1001][1001];
    int rec(int i,int j,string&s){
        if(i>j)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        if(s[i]==s[j]){
            ans=rec(i+1,j-1,s);
        }
        return dp[i][j]=ans;
    }
    string longestPalindrome(string s) {
        this->n=s.size();    
        int maxi=0;
        string ans="";
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            string temp="";
            for(int j=i;j<n;j++){
                temp+=s[j];
                if(rec(i,j,s)==1 && j-i+1>maxi){
                    maxi=j-i+1;
                    ans=temp;
                }
            }
        }
        return ans;
    }
};