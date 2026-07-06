class Solution {
public:
    static bool comp(const vector<int>&v1,const vector<int>&v2){
        if(v1[0]!=v2[0]){
            return v1[0]>v2[0];
        }
        return v1[1]<v2[1];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),comp);
        int cnt=0;
        for(int i=0;i<n;i++){
            int l= intervals[i][0];
            int r= intervals[i][1];
            for(int j=i+1;j<n;j++){
                int ll=intervals[j][0];
                int rr=intervals[j][1];
                if(ll<=l && rr>=r){
                    cnt+=1;
                    break;    
                }
            }
        }
        return n-cnt;
    }
};