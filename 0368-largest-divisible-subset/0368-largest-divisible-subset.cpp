class Solution {
public:
    int dp[1001];
    int rec(int level,vector<int>&arr,vector<int>&hash,int n){
        if(level<0)return 0;
        if(dp[level]!=-1)return dp[level];

        int ans=1;
        for(int i=level-1;i>=0;i--){
            if(arr[level]%arr[i]==0){
                int temp= 1+rec(i,arr,hash,n);
                if(temp>ans){
                    hash[level]=i;
                    ans=temp;
                }
            }
        }
        return dp[level]=ans;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n =nums.size();
        memset(dp,-1,sizeof(dp));
        sort(nums.begin(),nums.end());
        vector<int>hash(n);
        for(int i=0;i<n;i++)hash[i]=i;
        int maxi=-1;
        int maxiind=-1;
        for(int i=0;i<n;i++){
            int temp = rec(i,nums,hash,n);
            if(temp>maxi){
                maxi=temp;
                maxiind=i;
            }
        }
        vector<int>ans;
        while(hash[maxiind]!=maxiind){
            ans.push_back(nums[maxiind]);
            maxiind=hash[maxiind];
        }
        ans.push_back(nums[maxiind]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};