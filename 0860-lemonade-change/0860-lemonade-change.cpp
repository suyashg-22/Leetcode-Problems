class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n= bills.size();
        int c1=0;
        int c2 =0;
        int c3=0;
        int tot =0;
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                c1+=1;
            }
            else if(bills[i]==10){
                if(c1>0){
                    c1-=1;
                }
                else return false;
                c2+=1;
            }
            else{
                if(c2>0 && c1>0){
                    c2-=1;
                    c1-=1;
                }
                else if(c1>=3){
                    c1-=3;
                }
                else return false;
                c3+=1;
            }
        }
        return true;
    }
};