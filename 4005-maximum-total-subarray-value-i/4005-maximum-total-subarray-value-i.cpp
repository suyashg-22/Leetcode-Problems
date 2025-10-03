#include <vector>
#include <algorithm>  
#include <climits>
using namespace std;

using ll = long long;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        ll n = nums.size();
        ll maxi = LLONG_MIN;
        ll mini = LLONG_MAX;
        for (ll i = 0; i < n; i++) {
            mini = min(mini, (ll)nums[i]);
            maxi = max(maxi, (ll)nums[i]);
        }
        ll ans = (maxi - mini) * k;
        return ans;
    }
};
