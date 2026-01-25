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
    int makeConnected(int n, vector<vector<int>>& connections) {
        this->n = n;
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        rnk.assign(n, 0);

        for (auto it : connections) {
            int u = it[0];
            int v = it[1];
            dsu(u, v);
        }
        for(int i=0;i<n;i++){
            parent[i]=findparent(i);
            mpp[parent[i]]+=1;
        }
        int req = mpp.size()-1;
        int ed = connections.size();
        for(auto it:mpp){
            ed-= (it.second-1);
        }
        if(ed>=req){
            return req;
        }
        return -1;
    }
};