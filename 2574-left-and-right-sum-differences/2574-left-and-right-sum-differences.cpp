class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        int sumr =0;
        for(int i=0;i<n;i++)sumr+=nums[i];
        int suml=0;
        for(int i=0;i<n;i++){
            sumr-=nums[i];
            ans[i]=abs(sumr-suml);
            suml+=nums[i];
        }
        return ans;
    }
};