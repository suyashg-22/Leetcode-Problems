using ll =long long;
class Solution {
public:
    vector<string>ans;
    void rec(int level,string ss,string &s,int target,ll eval,ll resd){
        if(level==s.size()){
            if(eval==target)ans.push_back(ss);
            return;
        }
        ll x =0;
        string temp="";
        for(int j=level;j<s.size();j++){
            if(j>level && s[level]=='0')return;
            x = x*10 + (s[j]-'0');
            temp+=s[j];
            if(level==0){
                rec(j+1,ss+temp,s,target,x,x);
            }
            else{
                rec(j+1,ss+'+'+temp,s,target,eval+x,x);
                rec(j+1,ss+'-'+temp,s,target,eval-x,-1*x);
                rec(j+1,ss+'*'+temp,s,target,eval-resd+(resd*x),resd*x);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        string ss="";
        rec(0,ss,num,target,0,0);
        return ans;
    }
};