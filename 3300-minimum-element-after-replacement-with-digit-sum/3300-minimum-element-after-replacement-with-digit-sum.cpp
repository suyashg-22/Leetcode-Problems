class Solution {
public:
    int minElement(vector<int>& nums) {
        int n =nums.size();
        int mini =INT_MAX;

        for(int i=0;i<n;i++){
            int x =nums[i];
            int sum=0;
            string s= to_string(x);
            for(int j=0;j<s.size();j++){
                sum+= (s[j]-'0');
            }
            mini=min(mini,sum);
        }
        return mini;
    }
};