class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>pos,neg;
        for(int i=0;i<n;i++){
            if(nums[i]>0) pos.push_back(nums[i]);
            else neg.push_back(nums[i]);
        }
        int a =pos.size();
        int b= neg.size();
        if(a>b){
            for(int i=0;i<b;i++){
                nums[2*i]=pos[i];
                nums[2*i+1]=neg[i];
            }
            int index=b*2;
            for(int i=b;i<a;i++){
                nums[index]=pos[i];
                index++;
            }
        }
        else{
            for(int i=0;i<a;i++){
                nums[2*i]=pos[i];
                nums[2*i+1]=neg[i];
            }
            int index=a*2;
            for(int i=a;i<b;i++){
                nums[index]=neg[i];
                index++;
            }
        }
        return nums;
    }
};