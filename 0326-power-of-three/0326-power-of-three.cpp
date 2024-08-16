class Solution {
public:
    
    bool recur(int n,int i){
        if(i>19){
            return false;
        }   
        int check = static_cast<int>(pow(3,i));
        if(check==n){
            return true;
        }
        return recur(n,i+1);
    }
    
    bool isPowerOfThree(int n) {
        return recur(n,0);
    }
};