class Solution {

public:
    bool f(vector<vector<int>>& trust,int first,int last){
        int n = trust.size();
        for(int i=0;i<n;i++){
            if(trust[i][0]==first && trust[i][1]==last){
                return true;
            }
        }
        return false;
    }
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1)return 1;
        if(trust.size()<=0)return -1;
        int first = 1;
        int last = n;
        while(first<last){
            if(f(trust,first,last)==1){
                first+=1;
            }
            else if(f(trust,last,first)==1){
                last-=1;
            }
            else{
                first+=1;
                last-=1;
            }
        }
        if(last>first)return -1;
        for(int i=0;i<trust.size();i++){
            if(trust[i][0]==first)return -1;
        }
        int cnt = 0;
        for(int i = 0; i < trust.size(); i++) {
            if(trust[i][1] == first) cnt++;
        }
        if(cnt != n - 1) return -1;

        return first;
    }
};