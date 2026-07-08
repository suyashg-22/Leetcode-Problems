const long long mod = 1e9 + 7;

// Use a struct instead of a pair so we can track the count of non-zero digits
struct Node {
    long long val;
    long long sum;
    long long cnt;
};

class Solution {
    vector<long long> p10;
    
    // A helper function to keep the merge logic clean and prevent code duplication
    Node merge(Node left, Node right) {
        Node res;
        res.cnt = left.cnt + right.cnt;
        res.sum = left.sum + right.sum;
        
        if (right.cnt == 0) {
            res.val = left.val;
        } else if (left.cnt == 0) {
            res.val = right.val;
        } else {
            // Shift the left value by the actual COUNT of digits in the right value
            res.val = ((left.val * p10[right.cnt]) % mod + right.val) % mod;
        }
        return res;
    }

    void build(int l, int h, int ind, string& s, vector<Node>& seg) {
        if (l == h) {
            int digit = s[l] - '0';
            if (digit == 0) {
                seg[ind] = {0, 0, 0};
            } else {
                seg[ind] = {digit, digit, 1}; // val, sum, count
            }
            return;
        }
        int mid = (l + h) / 2;
        build(l, mid, 2 * ind + 1, s, seg);
        build(mid + 1, h, 2 * ind + 2, s, seg);
        
        seg[ind] = merge(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    Node find(int l, int h, int ind, string& s, vector<Node>& seg, int ll, int hh) {
        if (ll <= l && h <= hh) {
            return seg[ind]; 
        }
        if (h < ll || l > hh) {
            return {0, 0, 0}; // Out of bounds
        }
        int mid = (l + h) / 2;
        Node left = find(l, mid, 2 * ind + 1, s, seg, ll, hh);
        Node right = find(mid + 1, h, 2 * ind + 2, s, seg, ll, hh);
        
        return merge(left, right);
    }

public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        
        // Precompute powers of 10 up to N to avoid using pow()
        p10.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            p10[i] = (p10[i - 1] * 10) % mod;
        }

        vector<Node> seg(n * 4);
        build(0, n - 1, 0, s, seg);
        
        int m = queries.size();
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            int ll = queries[i][0];
            int hh = queries[i][1];
            Node p = find(0, n - 1, 0, s, seg, ll, hh); 
            
            // Answer is value * sum
            ans[i] = (p.val * p.sum) % mod;
        }
        return ans;
    }
};