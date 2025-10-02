class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int x = numBottles;
        int y = numExchange;
        int ans=0;
        int empty =0;
        while(x>0 || empty>=y){
            if(x>0){
                empty += x;
                ans+=x;
                x=0;
            }
            else{
                x=1;
                empty-=y;
                y+=1;
            }
        }
        return ans;
    }
};