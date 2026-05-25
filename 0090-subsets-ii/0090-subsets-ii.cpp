class Solution {
public:
    set<vector<int>>st;
    int n;
    vector<int>*arr;

    void rec(int level,vector<int>&temp){
        if(level==n){
            st.insert(temp);
            return;
        }
        rec(level+1,temp);
        temp.push_back((*arr)[level]);
        rec(level+1,temp);
        temp.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        this->n=nums.size();
        this->arr=&nums;
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        rec(0,temp);
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};