using ll = long long;
ll mod = 1000000007;

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        ll ans = 0;
        vector<int> l(100001, 0), r(100001, 0);

        for (int i = n - 1; i >= 0; i--) {
            r[nums[i]] += 1;
        }

        for (int i = 0; i < n; i++) {
            r[nums[i]] -= 1;
            if (2 * nums[i] <= 100000) {
                ans = (ans + 1LL * l[2 * nums[i]] * r[2 * nums[i]]) % mod;
            }
            l[nums[i]] += 1;
        }

        return ans;
    }
};
