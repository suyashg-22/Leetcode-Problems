class Solution {
public:
    int dp[1001];
    bool fun(string& s1,string& s2){
        int i=0;
        int j=0;
        int n=s1.size();
        int m=s2.size();
        if(m!=n+1)return false;
        while(j<m){
            if(s1[i]!=s2[j]){
                j++;
            }
            else {
                i++;
                j++;
            }
        }
        if(i==n && j==m)return true;
        return false;
    }
    int rec(int level, vector<string>& arr, int n) {
        if (level < 0) return 0;
        if (dp[level] != -1) return dp[level];

        int ans = 1;
        for (int i = 0; i < level; i++) {
            if (fun(arr[i], arr[level])) { 
                ans = max(ans, 1 + rec(i, arr, n));
            }
        }
        return dp[level] = ans;
    }

    static bool comp(const string &s1,const string&s2){
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
        int n =words.size();
        memset(dp,-1,sizeof(dp));
        sort(words.begin(),words.end(),comp);
        int ans =0;
        for(int i=0;i<n;i++){
            ans=max(ans,rec(i,words,n));
        }
        return ans;
    }
};