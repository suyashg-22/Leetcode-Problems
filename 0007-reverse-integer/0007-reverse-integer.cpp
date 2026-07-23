class Solution {
public:
    int reverse(int x) {
        long long ans =0;
        bool flag = (x>=0)?true:false;
        if(!flag && x<=-2147483648)return 0;
        long long xx= (flag)?x:-1*x;
        long long d = xx%10;
        xx/=10;
        ans=d;
        while(xx>0){
            d=xx%10;
            if(flag && ans>2147483647/10)return 0;
            if(!flag && ans>2147483648/10)return 0;
            ans*=10;
            if(flag && ans>2147483647-d)return 0;
            if(!flag && ans>2147483648-d)return 0;
            ans+=d;
            xx/=10;
        }
        if(flag)return ans;
        return -1*ans;
    }
};