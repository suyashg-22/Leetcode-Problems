class Solution {
public:
    vector<vector<char>> arr;

    bool rec(int x,int y){

        if(x==9){
            return true;
        }

        int nx,ny;

        if(y==8){
            nx=x+1;
            ny=0;
        }
        else{
            nx=x;
            ny=y+1;
        }

        if(arr[x][y]!='.'){
            return rec(nx,ny);
        }

        for(char ch='1';ch<='9';ch++){

            bool flag=true;

            for(int i=0;i<9;i++){
                if(arr[x][i]==ch){
                    flag=false;
                    break;
                }
            }

            if(flag){
                for(int i=0;i<9;i++){
                    if(arr[i][y]==ch){
                        flag=false;
                        break;
                    }
                }
            }

            if(flag){

                int sr=(x/3)*3;
                int sc=(y/3)*3;

                for(int i=sr;i<sr+3;i++){
                    for(int j=sc;j<sc+3;j++){

                        if(arr[i][j]==ch){
                            flag=false;
                            break;
                        }
                    }
                }
            }

            if(flag){

                arr[x][y]=ch;

                if(rec(nx,ny)){
                    return true;
                }

                arr[x][y]='.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {

        arr=board;

        rec(0,0);

        board=arr;
    }
};