using ll = long long;
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(),potions.end());
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            ll temp = (success%spells[i]==0)?success/spells[i]:(success/spells[i])+1;
            arr[i]= m-(lower_bound(potions.begin(),potions.end(),temp)-potions.begin());
        }
        return arr;
    }
};