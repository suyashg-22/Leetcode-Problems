class Solution {
public:
    string removeOuterParentheses(string s) {
        int n= s.size();
        string ans = "";
        string temp = "";
        int size =0;
        int cnt =0;
        for(int i=0;i<n;i++){
            if(cnt==0){
                if(!temp.empty())temp.erase(0,1);
                if(!temp.empty())temp.pop_back();
                ans+=temp;
                temp="";
            }
            
            if(s[i]=='('){
                cnt+=1;
            }
            else{
                cnt-=1;
            }
            temp+=s[i];
        }
        if(cnt==0){
                if(!temp.empty())temp.erase(0,1);
                if(!temp.empty())temp.pop_back();
                ans+=temp;
                temp="";
            }
        return ans;
    }
};