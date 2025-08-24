class Solution {
public:
    bool check(vector<int>& nums,int mid,int target){
        int n = nums.size();
        if (nums[mid]==target)return 1;
        if(nums[0]<=nums[mid] && nums[mid]>=nums[n-1]){
            if(target>=nums[0] && target<=nums[mid])return 1;
            return 0;
        } 
        else if(nums[0]<=nums[mid]){
            if(target>=nums[0] && target<=nums[mid])return 1;
            return 0;
        }
        else {
            if(target>=nums[mid] && target<=nums[n-1])return 0;
            return 1;
        }
    }
    int search(vector<int>& nums, int target) {
        int n =nums.size();
        int l =0;
        int h = n-1;
        int ans =0;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(check(nums,mid,target)==1){
                ans = mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return (nums[ans]==target?ans:-1);
    }
};