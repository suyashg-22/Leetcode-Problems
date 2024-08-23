class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        int n2 = n*2; 
        vector<int>arr(n2);

        for(int i=0;i<n;i++){
            arr[i]=nums[i];
        }
        int i=0;
        for(int j=n;j<n2;j++){
            arr[j]=nums[i];
            i++;
        }

        return arr;
    }
};