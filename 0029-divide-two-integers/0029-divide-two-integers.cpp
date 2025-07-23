using ll = long long;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        bool f1 = dividend>0;
        bool f2 = divisor>0;
        int res = (f1^f2)?-1:1;
        ll a = abs((ll)dividend);
        ll b = abs((ll)divisor);

        ll ans=0;
        while(a>=b){
            ll i=0;
            while(true){
                ll temp =(b<<i) ;
                if(temp>a){
                    break;
                }
                i+=1;
            }
            if(i!=0){
                i-=1;
            }
            ans+= (1LL<<i);
            a-= (b<<i);
        }
        return res*ans;
    }
};