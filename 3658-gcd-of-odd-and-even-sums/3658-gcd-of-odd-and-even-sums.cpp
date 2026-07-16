class Solution {
public:
    int gcd(int x,int y){
        while(x>0 && y>0){
            if(x>=y){
                x=x%y;
            }
            else y=y%x;
        }
        if(x==0)return y;
        return x;
    }
    int gcdOfOddEvenSums(int n) {
        int s1 = pow(n,2);
        int s2 = pow(n,2)+n;
        int temp = gcd(s1,s2);
        return temp;
    }
};