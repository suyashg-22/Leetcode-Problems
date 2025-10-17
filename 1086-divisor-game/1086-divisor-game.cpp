class Solution {
public:
    // int dp[1001];
    // int rec(int n){
    //     if(n==0)return 0;
    //     if(dp[n]!=-1)return dp[n];
    //     int ans = 0;
    //     for(int i=1;i<n;i++){
    //         if(n%i==0 && rec(n-i)==0){
    //             ans =1;
    //             break;
    //         }
    //     }
    //     return dp[n]=ans;
    // }
    bool divisorGame(int n) {
        // memset(dp,-1,sizeof(dp));
        // return rec(n);
        return (n%2==0?true:false);
    }
};