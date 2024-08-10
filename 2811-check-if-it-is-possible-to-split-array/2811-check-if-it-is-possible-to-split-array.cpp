#include <vector>

class Solution {
public:
    bool canSplitArray(std::vector<int>& nums, int m) {
        int n = nums.size();
        
        // If the array has 2 or fewer elements, it is always possible to split them into single elements
        if (n <= 2) {
            return true;
        }

        // Check if there is any pair of consecutive elements whose sum is at least m
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] + nums[i + 1] >= m) {
                return true;
            }
        }

        // If no such pair exists, it's not possible to split as required
        return false;
    }
};
