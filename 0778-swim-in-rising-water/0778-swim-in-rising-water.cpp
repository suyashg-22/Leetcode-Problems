class Solution {
public:
    vector<int>parent;
    vector<int>rnk;
    int n;
    vector<int>dx{-1,0,1,0};
    vector<int>dy{0,-1,0,1};
    vector<vector<int>>*arr;

    int findparent(int x){
        if(parent[x]==x)return x;
        return parent[x]=findparent(parent[x]);
    }
    void dsu(int x,int y,int thresh){
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<n){
                if((*arr)[nx][ny]<=thresh){
                    int a = x*n+y;
                    int b = nx*n+ny;
                    int upa = findparent(a);
                    int upb = findparent(b);
                    int ra = rnk[upa];
                    int rb = rnk[upb];
                    if(upa==upb)continue;
                    if(ra<rb){
                        parent[upa]=upb;
                    }
                    else if(rb<ra){
                        parent[upb]=upa;
                    }
                    else{
                        parent[upa]=upb;
                        rnk[upb]+=1;
                    }

                }
            }
        }
    }
    int swimInWater(vector<vector<int>>& grid) {
        this->n = grid.size();
        this->arr=&grid;
        parent.resize(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                parent[i*n+j]=i*n+j;
            }
        }
        rnk.assign(n*n,0);
        int cnt =0;
        while(true){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]<=cnt)dsu(i,j,cnt);
                }
            }
            if(findparent(0)==findparent(n*n-1)){
                break;
            }
            cnt+=1;
        }
        return cnt;
    }
};