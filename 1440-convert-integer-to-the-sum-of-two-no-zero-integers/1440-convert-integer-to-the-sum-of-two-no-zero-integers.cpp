class Solution {
public:
    bool check(int x){
        string s = to_string(x);
        int n =s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                return false;
            }
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