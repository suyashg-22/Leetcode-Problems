class Solution {
public:
    bool check(vector<int>&arr,int mid,int k){
        int n = arr.size();
        int sum=0;
        int cnt =0;
        for(int i=0;i<n;i++){
            if(sum+arr[i]<=mid){
                sum+=arr[i];
            }
            else{
                cnt++;
                sum=arr[i];
            }
        }
        cnt++;
        if(cnt<=k)return true;
        return false;
    }
    int splitArray(vector<int>& nums, int k) {
        int n =nums.size();
        int maxi = INT_MIN;
        int sum =0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            sum+=nums[i];
        }
        int l= maxi;
        int h=sum;
        int ans=-1;
        while(l<=h){
            int mid =l+(h-l)/2;
            if(check(nums,mid,k)){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};