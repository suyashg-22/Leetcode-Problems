class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n =fruits.size();
        int cnt =0;
        for(int i=0;i<n;i++){
            bool flag = false;
            for(int j=0;j<n;j++){
                if(baskets[j]>=fruits[i] && baskets[j]!=-1){
                    baskets[j]=-1;
                    flag = true;
                    break;
                }
            }
            if(!flag)cnt+=1;
        }
        return cnt;
    }
};