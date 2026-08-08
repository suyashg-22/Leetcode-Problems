class Solution {
public:
    vector<int> f(int r){
        vector<int>ans;
        long long res=1;
        ans.push_back(1);
        for(int c=1;c<r;c++){
            res= res*(r-c)/c;
            ans.push_back(res);
        }
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int r=1;r<=numRows;r++){
            vector<int>temp = f(r);
            ans.push_back(temp);
        }
        return ans;
    }
};