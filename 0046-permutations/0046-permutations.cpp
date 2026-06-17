class Solution {
public:
    int n;
    vector<vector<int>>ans;
    void rec(int level,vector<int>&temp,vector<int>&taken,vector<int>&nums){
        if(level==n){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<n;i++){
            if(taken[i]==0){
                taken[i]=1;
                temp.push_back(nums[i]);
                rec(level+1,temp,taken,nums);
                temp.pop_back();
                taken[i]=0;
            }
        }
        return ;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        this->n=nums.size();
        vector<int>taken(n,0);
        vector<int>temp;
        rec(0,temp,taken,nums);
        return ans;
    }
};