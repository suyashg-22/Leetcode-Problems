class Solution {
public:
    vector<int>*arr;
    int n;
    vector<vector<int>>ans;

    void rec(int level,int sum,vector<int>&res){
        if(level==n){
            if(sum==0){
                ans.push_back(res);
            }
            return;
        }
        rec(level+1,sum,res);
        if(sum-(*arr)[level]>=0){
            res.push_back((*arr)[level]);
            rec(level,sum-(*arr)[level],res);
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->arr=&candidates;
        this->n=candidates.size();
        vector<int>res;
        rec(0,target,res);
        return ans;
    }
};