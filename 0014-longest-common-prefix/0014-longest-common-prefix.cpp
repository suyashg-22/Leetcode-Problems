class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n =strs.size();
        int mini =INT_MAX;
        for(int i=0;i<n;i++){
            int size = strs[i].size();
            mini=min(mini,size);
        }
        string ans ="";
        while(mini>0){
            bool flag = true;
            for(int i=0;i<n-1;i++){
                if(strs[i].substr(0,mini)!=strs[i+1].substr(0,mini)){
                    mini-=1;
                    flag =false;
                    break;
                }
            }
            if(flag){
                ans = strs[0].substr(0,mini);
                return ans;
            }
        }
        return ans;
    }
};