class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        // Sort the numbers to access negative numbers first
        sort(nums.begin(), nums.end());
        
        int i = 0;
        // Negate negative numbers first
        while (k > 0 && i < nums.size() && nums[i] < 0) {
            nums[i] = -nums[i];
            i++;
            k--;
        }
        
        // Sort again to find the smallest absolute value
        sort(nums.begin(), nums.end());
        
        // If k is still odd, negate the smallest element
        if (k % 2 == 1) {
            nums[0] = -nums[0];
        }
        
        // Calculate the sum of the array
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        
        return sum;
    }
};
