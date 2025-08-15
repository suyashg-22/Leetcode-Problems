class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n =bills.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){

            if(bills[i]==10){
                if(mpp[5]==0)return false;
                mpp[5]-=1;
            }
            else if(bills[i]==20){
                if(mpp[5]==0)return false;

                    if(mpp[10]>0){
                        mpp[10]-=1;
                        mpp[5]-=1;
                    }
                    else{
                        if(mpp[5]<3){
                            return false;
                        }
                        else mpp[5]-=3;
                    }
            }
            mpp[bills[i]]+=1;
        }
        return true;
    }
};