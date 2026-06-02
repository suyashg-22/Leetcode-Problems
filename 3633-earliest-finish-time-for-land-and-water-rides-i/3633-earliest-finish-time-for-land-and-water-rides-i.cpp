class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int ans = 1e9;
        for(int i=0;i<n;i++){
            int t = landStartTime[i]+landDuration[i];
            for(int j=0;j<m;j++){
                if(waterStartTime[j]<=t){
                    ans=min(ans,t+waterDuration[j]);
                }
                else{
                    ans=min(ans,t+waterStartTime[j]-t+waterDuration[j]);
                }
            }
        }

        for(int i=0;i<m;i++){
            int t = waterStartTime[i]+waterDuration[i];
            for(int j=0;j<n;j++){
                if(landStartTime[j]<=t){
                    ans=min(ans,t+landDuration[j]);
                }
                else{
                    ans=min(ans,t+landStartTime[j]-t+landDuration[j]);
                }
            }
        }
        return ans;
    }
};