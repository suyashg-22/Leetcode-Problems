class Solution {
public:
    int fun(vector<int>&arr,int k,int mid){
        int cnt =1;
        int cnts =0;
        for(int i =0;i<arr.size();i++){
            if(cnts+arr[i]<=mid){
                cnts += arr[i];
            }
            else{
                cnt+=1;
                cnts=arr[i];
            }
        }
        return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>n) return -1;
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans =low;
        while(low<=high){
            int mid = low+(high-low)/2;
            int cnt = fun(nums,k,mid);
            if(cnt>k){
                low =mid+1;
            }
            else{
                if(cnt==k) ans = mid;
                high=mid-1;
            }
        }
        return ans;
    }
};