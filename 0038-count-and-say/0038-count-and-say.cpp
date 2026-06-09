class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for(int i=2;i<=n;i++){
            int nn = s.size();
            int l = 1;
            string temp = "";
            for(int j=1;j<nn;j++){
                if(s[j]!=s[j-1]){
                    temp+=(l+'0');
                    temp+=s[j-1];
                    l=1;
                }
                else{
                    l+=1;
                }
            }
            temp+= (l+'0');
            temp+= s[nn-1];
            s=temp;
        }
        return s;
    }
};