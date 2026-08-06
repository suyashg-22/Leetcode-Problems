class Solution {
public:
    int div(int n,int t){
        long long p = 1;
        while(n>0){
            p*= n%10;
            n/=10;
        }
        return (p%t==0);
    }
    int smallestNumber(int n, int t) {
        while(true){
            if(div(n,t))return n;
            n++;
        }
        return -1;
    }
};