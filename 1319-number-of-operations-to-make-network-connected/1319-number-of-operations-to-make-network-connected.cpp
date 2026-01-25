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

        int cntex =0;
        int req =0;
        for (auto it : connections) {
            int u = it[0];
            int v = it[1];
            if(findparent(u)==findparent(v))cntex+=1;
            else dsu(u, v);
        }
        for(int i=0;i<n;i++){
            if(findparent(i)==i)req+=1;
        }

        if(cntex>=req-1)return req-1;
        return -1;
    }
};