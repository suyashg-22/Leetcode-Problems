class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans ="";
        int i=0;
        string temp ="";
        while(i<n){
            if(s[i]==' '){
                reverse(temp.begin(),temp.end());
                ans+=temp;
                ans+=" ";
                temp="";
            }
            else{
                temp+=s[i];
            }
            
            i+=1;
        }
        reverse(temp.begin(),temp.end());
        ans+=temp;
        temp="";
        return ans;
    }
};