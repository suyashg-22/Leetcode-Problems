class Solution {
public:
    int myAtoi(string s) {
        int n= s.size();
        long long ans =0;
        int sign=1;
        int i=0;
        while(i<n){
            if(!isspace(s[i]))break;
            i+=1;
        }
        if(s[i]=='+'){
            sign=1;
            i+=1;
        }
        else if(s[i]=='-'){
            sign=-1;
            i+=1;
        }
        while(i<n){
            if(s[i]=='0'){
                i+=1;
            }
            else break;
        }
        while(i<n){
            if(!isdigit(s[i])){
                break;
            }
            else{
                ans= ans*10 + (s[i]-'0');
                if(sign==-1 && sign*ans<=INT_MIN ){
                    return INT_MIN;
                }
                if(sign==1 && ans>=INT_MAX){
                    return INT_MAX;
                }
                i+=1;
            }
        }
        return sign*ans;
    }
};