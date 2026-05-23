class Solution {
public:
    vector<string>ans;

    void rec(int l , int r,string s){
        if(l==0 && r==0){
            ans.push_back(s);
            return; 
        }

        if(l>0){
            s+='(';
            rec(l-1,r,s);
            s.pop_back();
        }

        if(r>l){
            s+=')';
            rec(l,r-1,s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        rec(n,n,"");
        return ans;
    }
};