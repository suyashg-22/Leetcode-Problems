class Solution {
public:
    int rec(int n){
        if(n<2)return n;
        return rec(n-1)+rec(n-2);
    }
    int fib(int n) {
        return rec(n);
    }
};