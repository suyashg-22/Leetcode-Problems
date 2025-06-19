class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        bool flag = true;
        if(n<0) {
            flag = false;
            n=abs(n);
        }
        while(n>0){
            if(n%2==1){
                ans=ans*x;
                n=n-1;
            }
            else{
                x=x*x;
                n=n/2;
            }
        }
        if(!flag) return 1.0/ans;    
        return ans;
    }
};