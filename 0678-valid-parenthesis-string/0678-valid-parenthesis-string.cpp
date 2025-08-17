class Solution {
public:
    bool checkValidString(string s) {
        int n =s.size();
        int ob =0;
        int used =0;
        int unused =0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                ob+=1;
            }
            else if(s[i]=='*'){
                if(ob>0){
                    ob-=1;
                    used+=1;
                }
                else{
                    unused+=1;
                }
            }
            else{
                if(ob>0){
                    ob-=1;
                }
                else if(unused>0){
                    unused-=1;
                }
                else if(used>0){
                    used-=1;
                    unused+=1;
                }
                else {
                    return false;
                }
            }
        }
        if(ob>0)return false;
        return true;
    }
};