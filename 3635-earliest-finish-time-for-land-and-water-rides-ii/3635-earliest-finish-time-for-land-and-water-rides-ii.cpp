class Solution {
public:
    int fun(vector<int>&arr1,vector<int>&arr2,vector<int>&brr1,vector<int>&brr2){
        int t = INT_MAX;
        int n =arr1.size();
        int m =brr1.size();
        for(int i=0;i<n;i++){
            t=min(t,arr1[i]+arr2[i]);
        }
        int ans = INT_MAX;
        for(int i=0;i<m;i++){
            if(brr1[i]>t){
                ans=min(ans,brr1[i]+brr2[i]);
            }
            else{
                ans=min(ans,t+brr2[i]);
            }
        }
        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = min(fun(landStartTime,landDuration,waterStartTime,waterDuration),fun(waterStartTime,waterDuration,landStartTime,landDuration));
        return ans;
    }
};