class Solution {
public:
    int queen[10];
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
    int rec(int level){
        //base
        if(level==N){
            return 1;
        }
        //cache check
        if(queen[level]!=-1){
            return queen[level];
        }
        //compute
        int ans =0;
        for(int col =0;col<N;col++){
            if(check(level,col)){
                queen[level]=col;
                ans+=rec(level+1);
                queen[level]=-1;
            }
        }
        return ans;
    }
    int totalNQueens(int n) {
         N=n;
        memset(queen,-1,sizeof(queen));
        return rec(0);
    }
};