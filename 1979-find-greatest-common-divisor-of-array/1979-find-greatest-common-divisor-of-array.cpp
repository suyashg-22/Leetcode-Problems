class Solution {
public:
    int gcd(int a,int b){
        while(a>0 && b>0){
            if(a>b)a=a%b;
            else b=b%a;
        }
        if(a==0)return b;
        return a;
    }
    
    int findGCD(vector<int>& nums) {
        int mini=1e9;
        int maxi=-1e9;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
        }
        return gcd(mini,maxi);
    }
};