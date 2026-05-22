using ll = long long;
class Solution {
public:

    double myPow(double x, int n) {
        ll nn = n;
        if(nn<0)nn = -1*nn;
        double ans = 1.0;

        while(nn>0){
            if(nn%2==0){
                x= x*x;
                nn=nn/2;
            }
            else{
                ans*=x;
                nn-=1;
            }
        }

        if(n<0)return 1.0/ans;
        return ans;
    }
};