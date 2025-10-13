class Solution {
public:
    int queen[10];
    vector<vector<string>>ans;
    int N;
    bool check(int row,int col){
        for(int i=0;i<row;i++){
            int rowp = i;
            int colp = queen[i];
            if(colp==col || abs(colp-col)==abs(rowp-row)){
                return false;
            }
        }
        return true;
    }
    void rec(int level){
        //base
        if(level==N){
            vector<string>arr(N);
            for(int i=0;i<N;i++){
                string s(N,'.');
                s[queen[i]]='Q';
                arr[i]=s;
            }
            ans.push_back(arr);
        }
        //cache check
        // if(queen[level]!=-1){
        //     return queen[level];
        // }
        //compute
        for(int col =0;col<N;col++){
            if(check(level,col)){
                queen[level]=col;
                rec(level+1);
                queen[level]=-1;
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        N=n;
        memset(queen,-1,sizeof(queen));
        rec(0);
        return ans;
    }
};