class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int i=0;
        int j=0;
        char ans ;
        while(j<t.length()){
            if(t[j] == s[i]){
                i++;
                j++;
            }
            else{
                ans = t[j];
                break;
            }
        }
        return ans;
    }
};