class Solution {
public:
    vector<int>*arr;
    int n;
    vector<vector<int>>ans;

    void rec(int level,int sum,vector<int>&temp){

        if(sum==0){
            ans.push_back(temp);
            return;
        }

        for(int i=level;i<n;i++){
            if(i>level && (*arr)[i]==(*arr)[i-1])continue;
            if((*arr)[i]>sum)break;
            temp.push_back((*arr)[i]);
            rec(i+1,sum-(*arr)[i],temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(),candidates.end());

        this->n = candidates.size();
        this->arr = &candidates;

        vector<int>temp;

        rec(0,target,temp);

        return ans;
        
    }
};