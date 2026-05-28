class Solution {
public:
    int n;
    int m;
    int nn;
    vector<vector<char>>*arr;
    vector<int>dx{0,1,0,-1};
    vector<int>dy{-1,0,1,0};

    bool rec(int i,int j,int c,string& s){
        if(c==nn){
            return true;
        }

        bool ans = false;
        for(int z=0;z<4;z++){
            int ni = i+dx[z];
            int nj = j+dy[z];

            if(ni>=0 && ni<n && nj>=0 && nj<m){
                if((*arr)[ni][nj]!='1'&& (*arr)[ni][nj]==s[c]){
                    char ch = (*arr)[ni][nj];
                    (*arr)[ni][nj]='1';
                    ans = ans| rec(ni,nj,c+1,s);
                    (*arr)[ni][nj]=ch;
                }
            } 
        }
        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {
        this->nn= word.size();
        this->arr=&board;
        this->n= board.size();
        this->m= board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    char ch =board[i][j];
                    board[i][j]='1';
                    if(rec(i,j,1,word))return true;;
                    board[i][j]=ch;
                }
            }
        }
        return false;
    }
};