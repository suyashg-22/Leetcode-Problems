class Solution {
public:
    long long flowerGame(int n, int m) {
        long long e1,o1,e2,o2 =0;
        e1 =n/2;
        e2 =m/2;
        o1 =(n%2==1)?(n/2)+1:n/2;
        o2 =(m%2==1)?(m/2)+1:m/2;
        long long ans = e1*o2 + e2*o1;
        return ans;
    }
};