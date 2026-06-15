class Solution {
public:
    unordered_set<int>st;
    bool rec(int n){
        if(n==1)return true;
        if(st.find(n)!=st.end()){
            return false;
        }
        st.insert(n);
        int nn=0;
        while(n>0){
            int d = n%10;
            nn+= (d*d);
            n/=10;
        }
        return rec(nn);
    }
    bool isHappy(int n) {
        return rec(n);
    }
};