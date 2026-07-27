class Solution {
public:
    int dp[16];
    unordered_map<int,int>mpp;
    int rec(int level,string&s){
        if(level<0)return 0;
        if(dp[level]!=-1)return dp[level];
        int ans =1e8;
        int b=0;
        int num=0;
        for(int i=level;i>=0;i--){
            if(s[i]=='1'){
                int temp2= (1<<b);
                num+=temp2;
                if(mpp.count(num)){
                    ans= min(ans,1+rec(i-1,s));
                }
            }
            b+=1;
        }
        return dp[level]=ans;
    }
    int minimumBeautifulSubstrings(string s) {
        int n = s.size();
        memset(dp,-1,sizeof(dp));
        int temp=1;
        int limit = (1<<15);
        while(temp<=limit){
            mpp[temp]=1;
            temp*=5;
        }
        int ans= rec(n-1,s);
        if(ans>=1e8)return -1;
        return ans;
    }
};