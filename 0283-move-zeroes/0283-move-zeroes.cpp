class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int l=0;
        while(l<n && nums[l]!=0)l++;
        int r=l+1;
        while(r<n){
            if(nums[r]!=0){
                swap(nums[r],nums[l]);
                l++;
            }
            r++;
        }
    }
};