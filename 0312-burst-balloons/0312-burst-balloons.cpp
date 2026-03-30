class Solution {
public:
    int n;
    vector<int>*arr;
    int dp[303][303];
    int rec(int l,int r){
        if(l==r)return 0;
        if(dp[l][r]!=-1)return dp[l][r];
        int ans =0;
        for(int k=l;k<r;k++){
            ans=max(ans,(*arr)[l]*(*arr)[k+1]*(*arr)[r+1] + rec(l,k)+rec(k+1,r));
        }
        return dp[l][r]=ans;
    }
    int maxCoins(vector<int>& nums) {
        this->arr=&nums;
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        this->n=nums.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,n-2);
    }
};