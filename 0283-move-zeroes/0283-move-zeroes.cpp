class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int l=0;
        int r=0;
        while(r<n && nums[r]!=0){r++;}
        if(r==n)return;
        l=r;
        r++;
        while(r<n){
            if(nums[r]==0)r++;
            else{
                swap(nums[l],nums[r]);
                l++;
                r++;;
            }
        }
        return;
    }
};