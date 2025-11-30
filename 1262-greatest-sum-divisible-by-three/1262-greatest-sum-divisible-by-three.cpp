class Solution {
public:

    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%3==0)return sum;
        else if(sum%3==1){
            int two1=-1;
            int two2=-1;
            int one =-1;
            int cntone=0;
            int cnttwo =0;
            sort(nums.begin(),nums.end());
            for(int i=0;i<n;i++){
                if(nums[i]%3==2 && cnttwo<2){
                    if(two1==-1){
                        two1=nums[i];
                    }
                    else{
                        two2=nums[i];
                    }
                    cnttwo+=1;
                }
                else if(nums[i]%3==1 && cntone<1){
                    one = nums[i];
                    cntone+=1;
                }
            }
            if(cnttwo<2)return sum-one;
            if(cntone<1)return sum-two1-two2;
            return max(sum-one,sum-two1-two2);
        }
        else{
            int one1=-1;
            int one2=-1;
            int two =-1;
            int cntone =0;
            int cnttwo =0;
            sort(nums.begin(),nums.end());
            for(int i=0;i<n;i++){
                if(nums[i]%3==1 && cntone<2){
                    if(one1==-1){
                        one1 =nums[i];
                    }
                    else{
                        one2 =nums[i];
                    }
                    cntone+=1;
                }
                else if(nums[i]%3==2 && cnttwo<1){
                    two = nums[i];
                    cnttwo+=1;
                }
            }
            if(cntone<2)return sum-two;
            if(cnttwo<1)return sum-one1-one2;
            return max(sum-one1-one2,sum-two);
        }
        return 0;
    }
};