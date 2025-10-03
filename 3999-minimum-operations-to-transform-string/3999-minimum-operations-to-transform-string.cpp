class Solution {
public:
    int minOperations(string s) {
        int ans =0;
        int n =s.size();
        sort(s.begin(),s.end());
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                continue;
            }
            if(s[i]=='a'){
                continue;
            }
            ans+= int(s[i+1])-int(s[i]);
        }
        if(s[n-1]=='a') return ans;
        ans+=(-int(s[n-1])+int('z')+1);
        return ans;
    }
};