class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n= nums.size();
        int el1=INT_MIN;
        int el2=INT_MIN;
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<n;i++){
            if(cnt1<=0 && nums[i]!=el2){
                el1=nums[i];
                cnt1=1;
            }
            else if(cnt2<=0 && nums[i]!=el1){
                el2=nums[i];
                cnt2=1;
            }

            else if(el1==nums[i])cnt1++;
            else if(el2==nums[i])cnt2++;
            else{
                cnt1--;
                cnt2--;
            }

        }
        cnt1=0;
        cnt2=0;
        for(auto x:nums){
            if(x==el1)cnt1++;
            else if(x==el2)cnt2++;
        }
        vector<int>ans;
        if(cnt1> n/3)ans.push_back(el1);
        if(cnt2> n/3)ans.push_back(el2);
        return ans;
    }
};