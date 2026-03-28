class Solution {
public:
    vector<string>*arr;
    int n;
    int dp[1001];
    int rec(int level){
        if(level<0)return 0;
        if(dp[level]!=-1)return dp[level];

        int s2 = (*arr)[level].size();
        int ans = 1;
        for(int l=level-1;l>=0;l--){
            int s1 = (*arr)[l].size();
            if(s1+1 == s2){
                int i=0;
                int j=0;
                string a = (*arr)[l];
                string b = (*arr)[level];
                while(j<s2){
                    if(i>=s1)break;
                    if(a[i]==b[j]){
                        i+=1;
                        j+=1;
                    }
                    else j+=1;
                }

                if(i>=s1){
                    ans = max(ans, 1+rec(l));
                }
            }

        }
        return dp[level]=ans;
    }
    static bool comp(const string &x ,const string &y){
        // if(x.size()<y.size())return 1;
        // else return 0;
        return x.size()<y.size();
    }

    int longestStrChain(vector<string>& words) {
        this->n = words.size();
        this->arr= &words;
        memset(dp,-1,sizeof(dp));
        sort(words.begin(),words.end(),comp);
        int maxi = 1;
        for(int i=n-1;i>=0;i--){
            maxi=max(maxi,rec(i));
        }
        return maxi;
    }
};