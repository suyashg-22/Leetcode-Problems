class Solution {
public:
void bfs(vector<vector<char>>& board,int i,int j,vector<vector<int>>&vis)
    {
    vis[i][j]=1;
    queue<pair<int,int>>q;
    q.push({i,j});
    int row=board.size();
    int col=board[0].size();
    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,1,0,-1};
    while(!q.empty())
    {
        int r=q.front().first;
        int c=q.front().second;
        q.pop();

        for(int k=0;k<4;k++)
        {
        int newrow=r+delrow[k];
        int newcol=c+delcol[k];

        if(newrow>=0 && newrow<row && newcol>=0 && newcol<col && board[newrow][newcol]=='X' &&       !vis[newrow][newcol])
        {
            vis[newrow][newcol]=1;
            q.push({newrow,newcol});
        }
        }
        
    }
    }
    int countBattleships(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && board[i][j]=='X')
                {
                    bfs(board,i,j,vis);
                    count++;
                }
            }
        }
        return count;
    }
};