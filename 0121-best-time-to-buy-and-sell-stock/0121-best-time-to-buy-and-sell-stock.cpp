class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>arr(n);
        arr[n-1]=-1e9;
        for(int i=n-2;i>=0;i--)arr[i]=max(arr[i+1],prices[i+1]);
        int maxi =INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]-prices[i]);
        }
        if(maxi<=0)return 0;
        return maxi;
    }
};