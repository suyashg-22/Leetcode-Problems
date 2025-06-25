class Solution {
public:
    int binary(vector<int> m)
    {
        int l = 0;
        int h = m.size()-1;
        while(l <= h)
        {
            int mid = l + (h-l)/2;
            if(m[mid] == 0)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int>ans(k);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++){
            int soldiers=binary(mat[i]);
            pq.push({soldiers,i});
        }
        for(int i=0;i<k;i++){
            ans[i]= pq.top().second;
            pq.pop();
        }
        return ans;
    }
}; 