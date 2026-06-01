class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n =cost.size();
        int ans =0;
        int temp =0;
        sort(cost.rbegin(),cost.rend());
        for(int i=2;i<n;i+=3){
            temp+= cost[i];
        }
        for(int i=0;i<n;i++){
            ans+= cost[i];
        }
        return ans-temp;
    }
};