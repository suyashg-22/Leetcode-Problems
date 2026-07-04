class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int ultimateparent(int a){
        if(parent[a]==a)return a;
        return parent[a]=ultimateparent(parent[a]);
    }
    void unionbyrank(int a,int b){
        int upa = ultimateparent(a);
        int upb = ultimateparent(b);

        if(upa==upb) return;
        int rupa = rank[upa];
        int rupb = rank[upb];
        if(rupa>rupb){
            parent[upb]=upa;
        }
        else if(rupb>rupa){
            parent[upa]=upb;
        }
        else{
            parent[upb]=upa;
            rank[upa]+=1;
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        this->parent.resize(n+1);
        this->rank.assign(n+1,0);
        for(int i=0;i<n+1;i++)parent[i]=i;
        int mini = 1e9;
        for(auto it:roads){
            int a = it[0];
            int b = it[1];
            int wt = it[2];
            unionbyrank(a,b);
        }

        for(auto it:roads){
            int a = it[0];
            int wt = it[2];
            if(ultimateparent(a)==ultimateparent(1))mini=min(mini,wt);
        }
        return mini;
    }
};