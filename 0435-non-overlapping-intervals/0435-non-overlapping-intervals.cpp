class Solution {
public:
    static bool comp(const vector<int>&v1,const vector<int>&v2){
        return v1[1]< v2[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();   
        sort(intervals.begin(),intervals.end(),comp);
        int cnt=1;
        int a = intervals[0][0];
        int b = intervals[0][1];

        for(int i=1;i<n;i++){
            int x = intervals[i][0];
            int y = intervals[i][1];
            if(b<=x){
                cnt+=1;
                a=x;
                b=y;
            }
        }     
        return n-cnt;
    }
};