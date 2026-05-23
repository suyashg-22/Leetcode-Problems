using ll = long long;
const long long mod = 1e9+7;
class Solution {
public:
    int countGoodNumbers(long long n) {
        ll nn =(n%2==0) ?n/2:(n-1)/2;
        ll ans = (n%2==0)?1:5;
        ll x = 20;

        while(nn>0){
            if(nn%2==0){
                x = x*x%mod;
                nn/=2;
            }
            else{
                ans = ans*x%mod;
                nn-=1;
            }
        }
        return ans;
    }
};