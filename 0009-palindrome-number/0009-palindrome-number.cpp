class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        int start =x;
        long long xx =x%10;
        x/=10;
        while(x>0){
            int d = x%10;
            xx*=10;
            xx+=d;
            x/=10;
        }
        cout<<xx<<endl;
        if(xx<INT_MIN || xx>INT_MAX)return false;
        if((int)xx==start)return true;
        return false;
    }
};