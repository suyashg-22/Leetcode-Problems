class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int x =numBottles;
        int y =numExchange;
        int ans = x;
        int rem =0;
        while(true){
            if(x>=y){
                ans+=x/y;
                rem+=x%y;
                x=x/y;
            }
            else if(rem>=y){
                ans+=rem/y;
                rem=rem/y;
            }
            else if((x+rem)>=y){
                ans+=(x+rem)/y;
                x=x/y;
                rem=rem/y;
            }
            else break;
        }
        return ans;
    }
};