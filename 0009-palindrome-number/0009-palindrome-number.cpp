class Solution {
public:
    bool isPalindrome(int x) {
        if(x<10&&x>=0){
            return true;
        }
        else if(x<0){
            return false;
        }
        else {
            string str= to_string(x);
            int i=0;
            int j=str.size()-1;
            while(i<j){
                if(str[i]!=str[j]){
                    return false;
                }
                i++;
                j--;
            }
            return true;
        }
    }
};