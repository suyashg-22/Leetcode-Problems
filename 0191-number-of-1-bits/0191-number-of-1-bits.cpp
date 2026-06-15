class Solution {
public:
    int hammingWeight(int n) {
        int ans =0;
        while(n>0){
            int temp = n&1;
            if(temp==1)ans+=1;
            n>>=1;
        }
        return ans;
    }
};