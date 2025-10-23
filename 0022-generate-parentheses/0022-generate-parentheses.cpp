class Solution {
public:
    vector<string>ans;
    vector<string>rec(int n1,int n2,string &s){
        if(n1>n2){
            return ans;
        }

        if(n1<=0 && n2<=0){
            if(n1!=-1 && n2!=-1){
                ans.push_back(s);
            }
            return ans;
        }

        if(n1>0){
            s.push_back('(');
            rec(n1-1,n2,s);
            s.pop_back();
        }
        if(n2>0){
            s.push_back(')'); 
            rec(n1,n2-1,s);
            s.pop_back();
        }

        return ans;
    }
    vector<string> generateParenthesis(int n) {
        string s ="";
        return rec(n,n,s);
    }
};