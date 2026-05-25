class Solution {
public:

    vector<vector<int>>ans;
    int n;
    vector<int>*arr;

    void rec(int level,vector<int>&temp){
        ans.push_back(temp);
        for(int i=level;i<n;i++){
            if(i>level && (*arr)[i]==(*arr)[i-1])continue;
            temp.push_back((*arr)[i]);
            rec(i+1,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        this->n=nums.size();
        this->arr=&nums;
        sort(nums.begin(),nums.end());
        vector<int>temp;
        rec(0,temp);
        return ans;
    }
};