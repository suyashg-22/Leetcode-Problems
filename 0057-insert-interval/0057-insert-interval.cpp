class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,vector<int>& newInterval) {
        vector<vector<int>> ans;
        int x = newInterval[0];
        int y = newInterval[1];
        int n= intervals.size();
        int ind = 0;
        while (ind < n && x > intervals[ind][1]) {
            ans.push_back({intervals[ind][0], intervals[ind][1]});
            ind += 1;
        }
        if(ind==n){
            ans.push_back({x,y});
            return ans;
        }

        int nind = -1;
        if(intervals[ind][0]>y){
            ans.push_back({x,y});
            nind = ind;
        }
        else{
            int a = min(x, intervals[ind][0]);
            int b = max(y, intervals[ind][1]);
            for (int i = ind + 1; i < n; i++) {
                int xx = intervals[i][0];
                int yy = intervals[i][1];
                if (xx > b) {
                    nind = i;
                    break;
                }
                a = min(a, xx);
                b = max(b, yy);
            }
            ans.push_back({a, b});

        }
        if (nind == -1)return ans;
        for (int i = nind; i < n; i++) {
            int xx = intervals[i][0];
            int yy = intervals[i][1];
            ans.push_back({xx, yy});
        }
        return ans;
    }
};