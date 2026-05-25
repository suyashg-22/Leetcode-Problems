class Solution {
public:
    vector<vector<int>>ans;
    int k;
    int n;

    void rec(int level,int sum,vector<int>&temp){
        if(level==k){
            if(sum==0)ans.push_back(temp);
            return;
        }

        for(int i=(temp.size()==0)?1:temp[temp.size()-1]+1;i<=9;i++){
            if(i>sum)break;
            temp.push_back(i);
            rec(level+1,sum-i,temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        this->n=n;
        this->k=k;
        vector<int>temp;
        rec(0,n,temp);
        return ans;
    }
};