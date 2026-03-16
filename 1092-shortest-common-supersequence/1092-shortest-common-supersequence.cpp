class Solution {
public:
    string s1 ;
    string s2;
    int n1;
    int n2;
    int dp[1001][1001];
    string temp="";

    void f(int i,int j){
        if(i==n1 || j==n2)return;
        if(s1[i]==s2[j]){
            temp+=s1[i];
            f(i+1,j+1);
        }
        else{
            if(dp[i+1][j]==dp[i][j]){
                f(i+1,j);
            }
            else if(dp[i][j+1]==dp[i][j]){
                f(i,j+1);
            }
        }
        return;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        this->s1 = str1;
        this->s2 = str2;
        
        this->n1 = s1.size();
        this->n2 = s2.size();
        
        memset(dp,-1,sizeof(dp));
        
        for(int i=n1;i>=0;i--){
            for(int j=n2;j>=0;j--){
                
                if(i==n1 || j==n2)
                    dp[i][j]=0;
                    
                else{
                    
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                    
                    if(s1[i] == s2[j])
                        dp[i][j] = max(dp[i][j], 1 + dp[i+1][j+1]);
                }
            }
        }
        f(0,0);
        string s = temp;
        int i=0,j=0,k=0;
        int n=s.size();
        string ss ="";
        while(k<n){
            while(i<n1 && s1[i]!=s[k]){
                ss+=s1[i];
                i+=1;
            }
            while(j<n2 && s2[j]!=s[k]){
                ss+=s2[j];
                j+=1;
            }
            ss+=s[k];
            k+=1;
            i+=1;
            j+=1;
        }
        while(i<n1){
            ss+=s1[i];
            i+=1;
        }
        while(j<n2){
            ss+=s2[j];
            j+=1;
        }
        return ss;
    }
};