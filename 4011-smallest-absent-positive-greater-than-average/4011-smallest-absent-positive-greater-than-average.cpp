class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int n =nums.size();
        int avg =0;
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]+=1;
            avg+=nums[i];
        }
        avg = avg/n;
       
        int a = avg;
        while(a<=avg || mpp[a]>0){
            if(a<=0)a=1;
            else a+=1;
        }
        return a;
    }
};