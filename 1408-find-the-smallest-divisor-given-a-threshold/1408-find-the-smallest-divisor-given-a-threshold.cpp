class Solution {
public:
    bool fun(vector<int>&nums,int threshold,int mid){
        int sum =0;
        int n= nums.size();
        for(int i=0;i<n;i++){
            sum+= ceil((double)nums[i]/(double)mid);
        }
        if(sum <= threshold) return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1;
        int high = * max_element(nums.begin(),nums.end());
        int ans =INT_MAX;
        while(low<=high){
            int mid =low+(high-low)/2;
            if(fun(nums,threshold,mid)==true){
                ans=mid;
                high=mid-1;
            }
            else{
                low =mid+1;
            }
        }
        return ans;

    }
};