class Solution {
public:
    bool check(int x){
        while(x>0){
            int temp = x%10;
            if(temp==0)return false;
            x/=10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<=n/2;i++){
            int a = i;
            int b = n-i;
            if(check(a) && check(b)){
                return {a,b};
            }
        }
        return {-1,-1};
    }
};