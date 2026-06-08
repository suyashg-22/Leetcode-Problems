class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n =nums.size();
        vector<int>smaller;
        vector<int>greater;
        for(int i=0;i<n;i++){
            if(nums[i]>pivot)greater.push_back(nums[i]);
            else if(nums[i]<pivot) smaller.push_back(nums[i]);
        }
        int size = n-(greater.size()+smaller.size());      
        vector<int>ans;
        for(int i=0;i<smaller.size();i++){
            ans.push_back(smaller[i]);
        }
        for(int i=0;i<size;i++){
            ans.push_back(pivot);
        }
        for(int i=0;i<greater.size();i++){
            ans.push_back(greater[i]);
        }
        return ans;
    }
};