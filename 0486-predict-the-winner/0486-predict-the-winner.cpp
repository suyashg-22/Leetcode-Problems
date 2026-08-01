class Solution {
public:
    bool rec(int l,int r,vector<int>&arr,int sum,int total){
        if(l>r){
            int scoreb = total-sum;
            if(sum>=scoreb)return true;
            return false;
        }
        sum+=arr[l];
        bool ans1=rec(l+1,r-1,arr,sum,total);
        bool ans2=rec(l+2,r,arr,sum,total);
        sum-=arr[l];
        if(ans1 && ans2)return true;
        sum+=arr[r];
        bool ans3=rec(l+1,r-1,arr,sum,total);
        bool ans4=rec(l,r-2,arr,sum,total);
        sum-=arr[r];
        if(ans3 && ans4)return true;
        return false;
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int total=0;
        for(int i=0;i<n;i++)total+=nums[i];
        return rec(0,n-1,nums,0,total);
    }
};