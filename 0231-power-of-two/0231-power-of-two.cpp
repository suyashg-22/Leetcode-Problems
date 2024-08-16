class Solution {
public:
    
    bool recur(int n,int i){
        if(i>30){
            return false;
        }   
        int check = static_cast<int>(pow(2,i));
        if(check==n){
            return true;
        }
        return recur(n,i+1);
    }
    
    bool isPowerOfTwo(int n) {
        return recur(n,0);
    }
};