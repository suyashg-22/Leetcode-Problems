class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int>arr(100001,0);
        int cnt=0;
        for(auto x:costs){
            arr[x]+=1;
        }
        for(int i=1;i<=100000;i++){
            int buying = min(arr[i],coins/i);
            cnt+=buying;
            coins-= (i*buying);
            if(coins==0)break;
        }
        return cnt;
    }
};