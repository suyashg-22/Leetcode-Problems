class Solution {
public:
    bool check(string &s){
        int n = s.length();
        for(int i=0;i<n-1;i++){
            if(s[i]=='A'&& s[i+1]=='B'){
                s.erase(i,2);
            }
            if(s[i]=='C'&& s[i+1]=='D'){
                s.erase(i,2);
            }
        }
        if(s.length()==n){
            return false;
        }
        return true;
    }
    int recur(string &s){
        int n = s.length();
        if(n<=0){
            return 0;
        }
        if(!check(s)){
            return n;
        }
        return recur(s);
    }
    int minLength(string s) {
        return recur(s);
    }
};