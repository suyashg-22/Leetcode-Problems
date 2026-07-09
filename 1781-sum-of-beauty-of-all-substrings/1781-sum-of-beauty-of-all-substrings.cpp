class Solution {
public:
    int beautySum(string s) {
        int n =s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int>arr(26,0);
            for(int j=i;j<n;j++){
                char c = s[j];
                arr[c-'a']+=1;
                int maxi=0;
                int mini=1e9;
                for(int z=0;z<26;z++){
                    if(arr[z]>0){
                        maxi=max(maxi,arr[z]);
                        mini=min(mini,arr[z]);
                    }
                }
                ans+= (maxi-mini);
            }
        }
        return ans;
    }
};