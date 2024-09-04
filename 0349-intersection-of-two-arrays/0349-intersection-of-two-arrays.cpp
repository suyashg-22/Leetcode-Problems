class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>arr;
        int n= nums1.size();
        int m =nums2.size();
        map<int,bool>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((nums1[i]==nums2[j])&&mp[nums2[j]]!=1){
                    arr.push_back(nums1[i]);
                    mp[nums2[j]]=1;
                    break;
                }
            }
        }

        return arr;
    }
};