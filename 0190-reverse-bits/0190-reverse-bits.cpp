class Solution {
public:
    int reverseBits(int n) {
        int ans =0;
        int i=0;
        while(n>0){
            int res = n&1;
            if(res==1){
                int b = 32-i-1;
                int temp = (1<<b);
                ans+=temp;
            }
            n>>=1;
            i+=1;
        }
        return ans;
    }
};