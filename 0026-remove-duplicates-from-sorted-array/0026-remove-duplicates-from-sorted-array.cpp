class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int l=0;
        int r=1;
        while(r<n){
            int x = nums[r];
            int y = nums[l];
            if(x>y){
                l++;
                nums[l]=x;
            }
            r++;
        }
        return l+1;
    }
};