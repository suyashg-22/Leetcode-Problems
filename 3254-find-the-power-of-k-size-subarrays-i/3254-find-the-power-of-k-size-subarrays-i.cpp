class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        
        int n = nums.size();
        int size = n-k+1;
        vector<int> ans(size, -1);
        
        bool isCons = 1;
        for (int i = 0; i <= n - k; i++) {
            isCons = 1;
            
            for (int j = i + 1; j < i + k; j++) {
                if (nums[j] != nums[j - 1] + 1) {
                    isCons = 0;
                    break;
                }
            }
            
            if (isCons) {
                ans[i] = nums[i + k - 1];
            }
        }

        return ans;
    }
};
