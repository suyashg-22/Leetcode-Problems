class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int c1=0;
        int temp =0;
        int c2=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(')c1+=1;
            else if(s[i]=='*'){
                if(c1>0){
                    temp+=1;
                    c1-=1;
                }
                else{
                    c2+=1;
                }
            }
            else{
                if(c1>0)c1-=1;
                else if(temp>0){
                    temp-=1;
                    c2+=1;
                }
                else if(c2>0){
                    c2-=1;
                }
                else{
                    return false;
                }
            }
        }
        if(c1>0)return false;
        return true;

    }
};