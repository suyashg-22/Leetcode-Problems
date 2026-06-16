class Solution {
public:
    string processStr(string s) {
        string result="";
        int n= s.size();
        for(int i=0;i<n;i++){
            if( s[i]=='*'){
                if(result.size()<=0){
                    continue;
                }
                else result.pop_back();
            }
            else if(s[i]=='#'){
                string temp = result;
                result+=temp;
            }
            else if(s[i]=='%'){
                reverse(result.begin(),result.end());
            }
            else{
                result.push_back(s[i]);
            }
        }
        return result;
    }
};