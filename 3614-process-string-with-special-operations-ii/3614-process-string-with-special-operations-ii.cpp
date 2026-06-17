using ll = long long;
class Solution {
public:
    char processStr(string s, long long k) {
        ll n = s.size();
        ll len=0;
        for(ll i=0;i<n;i++){
            if(s[i]=='*'){
                if(len>0)len--;
            }
            else if(s[i]=='#'){
                len*=2;
            }
            else if(s[i]=='%'){
                continue;
            }
            else len++;
        }
        if(k>=len)return '.';
        for(ll i=n-1;i>=0;i--){
            if(s[i]=='*'){
                len++;
            }
            else if(s[i]=='#'){
                len/=2;
                if(k>=len){
                    k-=len;
                }
            }
            else if(s[i]=='%'){
                k= (len-k-1);
            }
            else{
                len--;
            }

            if(len==k){
                return s[i];
            }
        }
        return '.';
    }
};