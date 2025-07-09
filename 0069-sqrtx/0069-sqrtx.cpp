class Solution {
public:
    int f(long long mid,long long x){
        if(mid*mid<x){
            return 2;
        }
        if(mid*mid>x){
            return 0;
        }
        return 1;
    }
    int mySqrt(int x) {
        long long l = 1;
        long long h= x;
        long long ans =1;
        if(x==0)return 0;
        while(l<=h){
            long long mid = l+(h-l)/2;
            if(f(mid,x)==1){
                return mid;
            }

            if(f(mid,x)==0){
                h=mid-1;
            }
            else{
                ans=mid;
                l=mid+1;
            }
        }
        return ans;
    }
};