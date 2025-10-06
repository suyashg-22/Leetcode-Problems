using ll =long long;
class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        ll maxi = max(n,m);
        if(maxi<=k)return 0;
        ll ans = (maxi-k)*k;
        return ans;
    }
};