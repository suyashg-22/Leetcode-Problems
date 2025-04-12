class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n= nums.size();
        //sort(nums.begin(),nums.end());
        vector<int>hash(3,0);
        for(int i=0;i<n;i++){
            hash[nums[i]]++;
        }
        int cnt0 = hash[0];
        int cnt1 = hash[1];
        int cnt2 = hash[2];
        vector<int>ans;
        while(cnt0>0 || cnt1>0 || cnt2>0){
            if(cnt0>0){
                cnt0--;
                ans.push_back(0);
            }
            else if(cnt1>0){
                cnt1 --;
                ans.push_back(1);
            }
            else if(cnt2>0){
                cnt2--;
                ans.push_back(2);
            }
        }
        for(int i=0;i<n;i++){
            nums[i]=ans[i];
        }
    }
};