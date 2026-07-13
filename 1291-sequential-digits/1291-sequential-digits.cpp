class Solution {
public:
    void rec(long long num,int low,int high,vector<int>&ans){
        if(num>high)return;
        if(num<=high && num>=low)ans.push_back(num);

        int last = num%10;
        if(last<9){
            long long nnum = num*10 + last+1;
            rec(nnum,low,high,ans);
        }
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        for(int i=1;i<=9;i++){
            rec(i,low,high,ans);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};