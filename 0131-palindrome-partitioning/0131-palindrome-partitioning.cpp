class Solution {
public:
    vector<vector<string>>ans;
    int n;
    bool ispali(string&ss){
        int i=0;
        int j=ss.size()-1;
        while(i<j){
            if(ss[i]!=ss[j])return false;
            i++;
            j--;
        }
        return true;
    }
    void rec(int level,vector<string>&temp,string &s){
        if(level==n){
            ans.push_back(temp);
            return;
        }
        string ss="";
        for(int i=level;i<n;i++){
            ss+=s[i];
            if(ispali(ss)){
                temp.push_back(ss);
                rec(i+1,temp,s);
                temp.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        this->n=s.size();
        vector<string>temp;
        rec(0,temp,s);
        return ans;
    }
};