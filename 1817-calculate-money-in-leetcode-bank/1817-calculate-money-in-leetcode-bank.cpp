using ll = long long;
class Solution {
public:
    int totalMoney(int n) {
        ll x = ceil(1.0L * n/7);
        x-=1;
        ll temp = (x*(7*(x-1)))/2;
        temp += x*28;
        ll s =x;
        ll e =(n%7==0)?s+7: s+(n%7);
        ll ans = temp;
        ans += (e*(e+1)/2);
        ans -= (s*(s+1)/2);
        return ans;
    }
};