class Solution {
public:
    int dp[2001];
    int rec(int level, vector<int>& arr,vector<int>&hash) {
        if (level < 0) return 0;
        if (dp[level] != -1) return dp[level];
        int ans = 1;
        int cnt = 1;
        for (int i = level - 1; i >= 0; i--) {
            if (arr[i] < arr[level]){
                int ans2 = 1+rec(i,arr,hash);
                if(ans2>ans){
                    ans=ans2;
                    cnt=hash[i];
                }
                else if(ans2==ans){
                    cnt+=hash[i];
                }
            }
        }
        hash[level]=cnt;
        return dp[level] = ans;
    }

    int findNumberOfLIS(vector<int>& nums) {
        int n =nums.size();
        memset(dp,-1,sizeof(dp));
        vector<int>hash(n,1);

        int maxi=-1;
        for(int i=0;i<n;i++){
            maxi=max(maxi,rec(i,nums,hash));
        }
        int cnt =0;
        for(int i=0;i<n;i++){
            if(rec(i,nums,hash)==maxi)cnt+=hash[i];
        }
        return cnt;;
    }
};