class Solution {
public:
    
    bool recur(int n,int i){
        if(i>15){
            return false;
        }   
        int check = static_cast<int>(pow(4,i));
        if(check==n){
            return true;
        }
        return recur(n,i+1);
    }
    
    bool isPowerOfFour(int n) {
        return recur(n,0);
    }
};