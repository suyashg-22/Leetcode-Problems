class Solution {
public:
    int binary(vector<int>& m) {
        int l = 0;
        int h = m.size() - 1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (m[mid] == 0)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>> pq;  

        for (int i = 0; i < mat.size(); i++) {
            int soldiers = binary(mat[i]);

            pq.push({soldiers, i});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> ans(k);
        for (int i = k - 1; i >= 0; i--) {
            ans[i] = pq.top().second;
            pq.pop();
        }

        return ans;
    }
};
