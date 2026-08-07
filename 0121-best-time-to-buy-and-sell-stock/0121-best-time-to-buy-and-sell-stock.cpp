class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>arr(n);
        arr[n-1]=prices[n-1];
        for(int i=n-2;i>=0;i--){
            arr[i]=max(arr[i+1],prices[i]);
        }
        int maxi=0;
        for(int i=0;i<n-1;i++){
            maxi=max(maxi,-prices[i]+arr[i+1]);
        }
        return maxi;
    }
};