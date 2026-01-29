class Solution {
public:
    int climbStairs(int n) {
        int nxt = 1;
        int nxt2nxt =0;
        for(int level=n-1;level>=0;level--){
                int ans1 = nxt;
                int ans2 = nxt2nxt;
                nxt2nxt=nxt;
                nxt=ans1+ans2;            
        }
        return nxt;
    }
};