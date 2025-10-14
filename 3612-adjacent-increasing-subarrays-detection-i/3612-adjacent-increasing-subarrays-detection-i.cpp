class Solution {
public:
    bool check(int i, int k, vector<int>& nums) {
        int n = nums.size();
        // Ensure both subarrays of length k fit inside nums
        if (i + 2 * k > n) return false;

        // Check first subarray [i .. i+k-1]
        for (int j = i + 1; j < i + k; j++) {
            if (nums[j] <= nums[j - 1]) return false;
        }

        // Check second subarray [i+k .. i+2k-1]
        for (int j = i + k + 1; j < i + 2 * k; j++) {
            if (nums[j] <= nums[j - 1]) return false;
        }

        return true;
    }

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i + 2 * k <= n; i++) {
            if (check(i, k, nums)) return true;
        }
        return false;
    }
};
