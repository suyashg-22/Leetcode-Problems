class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<vector<int>>ans;
        priority_queue<vector<double>,vector<vector<double>>,greater<vector<double>>>pq;
        for(auto it :points){
            int a = it[0];
            int b = it[1];
            double temp = sqrt((a*a)+(b*b));
            pq.push({temp,1.0*a,1.0*b});
        }
        while(k>0){
            auto it = pq.top();
            pq.pop();
            ans.push_back({(int)it[1],(int)it[2]});
            k--;
        }
        return ans;
    }
};