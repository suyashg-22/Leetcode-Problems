using ll = long long int;
class Solution {
public:
    vector<int> nthRowOfPascalTriangle(int row) {
        vector<int>ansrow;
        ansrow.push_back(1);
        ll ans =1;
        for(int c=1;c<row;c++){
            ans = ans*(row-c);
            ans = ans/c;
            ansrow.push_back(ans);
        }
        return ansrow;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ansfinal;
        int row = numRows;
        for(int i=1;i<=row;i++){
            ansfinal.push_back(nthRowOfPascalTriangle(i));
        }
        return ansfinal;
    }
};