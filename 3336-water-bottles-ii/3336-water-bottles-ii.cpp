class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {

        int ans=0;
        int empty =0;
        while(numBottles>0 || empty>=numExchange){
            if(numBottles>0){
                empty += numBottles;
                ans+=numBottles;
                numBottles=0;
            }
            else{
                numBottles=1;
                empty-=numExchange;
                numExchange+=1;
            }
        }
        return ans;
    }
};