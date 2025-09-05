using ll = long long;
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int i = 1; i <= 60; i++) {
            ll sum = (ll)num1 - (ll)num2 * i;
            if (sum < i) continue;
            if (__builtin_popcountll(sum) <= i) return i;
        }
        return -1;
    }
};
