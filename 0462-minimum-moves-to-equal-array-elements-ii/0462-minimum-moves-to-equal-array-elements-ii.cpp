class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int target1 = nums[nums.size()/2];
        int target2 = nums[(nums.size()-1)/2];
        int ans1 =0;
        int ans2 =0;
        for(int i=0;i<nums.size();i++){
            int dif1 = abs(target1-nums[i]);
            ans1 += dif1;
            int dif2 = abs(target2-nums[i]);
            ans2 +=dif2;
        }
        
        return min(ans1,ans2);
    }
};