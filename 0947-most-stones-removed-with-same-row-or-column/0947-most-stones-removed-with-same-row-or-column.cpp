class Solution {
public:
    int n;
    vector<int> parent, rnk;
    unordered_map<int,int>mpp;
    int findparent(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = findparent(parent[x]);
    }
    void dsu(int a, int b) {
        int upa = findparent(a);
        int upb = findparent(b);
        int ra = rnk[upa];
        int rb = rnk[upb];
        if (upa == upb)
            return;
        if (ra < rb) {
            parent[upa] = upb;
        } else if (rb < ra) {
            parent[upb] = upa;
        } else {
            parent[upb] = upa;
            rnk[upa] += 1;
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int m = stones.size();
        int maxr =0;
        int maxc =0;
        for(auto it:stones){
            maxr=max(maxr,it[0]);
            maxc=max(maxc,it[1]);
        }
        n = maxr+maxc+2;
        parent.resize(n);
        for(int i=0;i<n;i++)parent[i]=i;
        rnk.assign(n,0);
        for(auto it:stones){
            int nr = it[0];
            int nc = it[1]+1+maxr;
            dsu(nr,nc);
            mpp[nr]=1;
            mpp[nc]=1;
        }
        int cnt =0;
        for(auto it:mpp){
            if(findparent(it.first)==it.first)
cnt+=1;        }
        return m-cnt;
    }
};