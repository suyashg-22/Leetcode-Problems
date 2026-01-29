class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        vector<int>arr(n);
        int cnto=0,cnte=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0)cnte+=1;
            else cnto+=1;
            arr[i]=(cnto-cnte);
        }   
        map<pair<int,int>,int>mpp;
        mpp[{0,0}]=-1;


        int x =0;
        int len=0;
        for(int i=0;i<n;i++){
            x^=nums[i];
            if(mpp.count({x,arr[i]})){
                len =max(len,i-mpp[{x,arr[i]}]);
            }
            else{
                mpp[{x,arr[i]}]=i;
            }
        } 
        return len;
    }
};