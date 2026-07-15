class Solution {
public:
    int gcd(int x,int y){
        if(y==0)return x;
        return gcd(y,x%y);
    }
    int gcdOfOddEvenSums(int n) {
        int s1 = pow(n,2);
        int s2 = pow(n,2)+n;
        int temp = gcd(s1,s2);
        return temp;
    }
};