class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int>arr;
        int i=0;
        int j=0;
        int n= nums1.size();
        int m =nums2.size();
        map<int,bool>mp;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((nums1[i]==nums2[j])&&mp[j]!=1){
                    arr.push_back(nums1[i]);
                    mp[j]=1;
                    break;
                }
            }
        }
        return arr;
    }
};