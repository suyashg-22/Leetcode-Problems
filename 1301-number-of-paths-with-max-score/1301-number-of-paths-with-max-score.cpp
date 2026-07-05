const long long mod = 1e9+7;
class Solution {
public:
    int dp[101][101];
    int rec(int i,int j,vector<string>&arr){
        if(i==0 && j==0)return dp[i][j]= 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans = -1e9;
        int cur=arr[i][j]-'0';
        if(j-1>=0 && arr[i][j-1]!='X'){
            ans=max(ans,cur+rec(i,j-1,arr));
        }
        if(i-1>=0 && arr[i-1][j]!='X'){
            ans=max(ans,cur+rec(i-1,j,arr));
        }
        if(i-1>=0 && j-1>=0 && arr[i-1][j-1]!='X'){
            ans=max(ans,cur+rec(i-1,j-1,arr));
        }
        return dp[i][j]=ans;
    }
    int dp2[101][101];
    int rec2(int i,int j,vector<string>&arr){
        if(i==0 && j==0)return dp2[i][j]=1;
        if (dp2[i][j]!=-1)return dp2[i][j];
        int req = dp[i][j]-(arr[i][j]-'0');
        int ans=0;
        if(j-1>=0 && dp[i][j-1]==req)ans=(ans+rec2(i,j-1,arr))%mod;
        if(i-1>=0 && dp[i-1][j]==req)ans=(ans+rec2(i-1,j,arr))%mod;
        if(i-1>=0 && j-1>=0 && dp[i-1][j-1]==req)ans=(ans+rec2(i-1,j-1,arr))%mod;
        return dp2[i][j]=ans;
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        memset(dp,-1,sizeof(dp));
        memset(dp2,-1,sizeof(dp2));
        int n = board.size();
        board[n-1][n-1]='0';
        board[0][0]='0';
        int sum = rec(n-1,n-1,board);
        if(sum<0)return {0,0};
        vector<int>ans(2);
        ans[0]=sum;
        ans[1]=rec2(n-1,n-1,board);
        return ans;
    }
};