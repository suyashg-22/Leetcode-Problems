class Solution {
public:
    int fun(vector<int>&arr,int days,int mid){
        int n= arr.size();
        int totdays=1;
        int sum =0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum>mid){
                sum = arr[i];
                totdays +=1;
            }
        }
        return totdays;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n= weights.size();
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int ans = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            int totdays= fun(weights,days,mid);
            if(totdays<=days){
                ans=mid;
                high=mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};