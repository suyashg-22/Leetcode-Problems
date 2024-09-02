class Solution {
public:
    int recur(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        int ans = recur(n - 1) + recur(n - 2);
        return ans;
    }

    int fib(int n) {
        return recur(n);
    }
};
