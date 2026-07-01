class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>arr(n,0);
        vector<int>brr(n,0);
        for(int i=0;i<n-1;i++){
            if(i==0){
                arr[i+1]=1;
            }
            else{
                int l = abs(nums[i]-nums[i-1]);
                int r = abs(nums[i]-nums[i+1]);
                if(l<=r){
                    arr[i+1]=arr[i]+r;
                }
                else{
                    arr[i+1]=arr[i]+1;
                }
            }
        }
        for(int i=n-1;i>0;i--){
            if(i==n-1){
                brr[i-1]=1;
            }
            else{
                int l = abs(nums[i]-nums[i-1]);
                int r = abs(nums[i]-nums[i+1]);
                if(l<=r){
                    brr[i-1]=brr[i]+1;
                }
                else brr[i-1]=brr[i]+l;

            }
        }
        int m = queries.size();
        vector<int>ans(m);
        for(int i=0;i<m;i++){
            int l = queries[i][0];
            int r = queries[i][1];
            if(l<=r){
                ans[i]= arr[r]-arr[l];
            }
            else{
                ans[i]= brr[r]-brr[l];
            }
        }
        return ans;
    }
};