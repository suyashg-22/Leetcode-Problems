class Node {
public:
    Node* arr[2];
    Node() {
        arr[0] = NULL;
        arr[1] = NULL;
    }
    ~Node() {
        delete arr[0];
        delete arr[1];
    }
    Node* next(int i) { return arr[i]; }
    bool isempty(int i) { return arr[i] == NULL; }
};
class Trie {
public:
    Node* root;
    Trie() { root = new Node(); }
    ~Trie() { delete root; }
    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int b = (num >> i) & 1;
            if (node->isempty(b)) {
                Node* nnode = new Node();
                node->arr[b] = nnode;
            }
            node = node->next(b);
        }
    }
    int maxixor(int num) {
        int ans = 0;
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int b = (num >> i) & 1;
            if (node->isempty(0) && node->isempty(1)) return -1;
            else if (b == 0 && !node->isempty(1)) {
                int temp = (1 << i);
                ans += temp;
                node = node->next(1);
            } else if (b == 1 && !node->isempty(0)) {
                int temp = (1 << i);
                ans += temp;
                node = node->next(0);
            }
            else {
                node = node->next(b);
            }
        }
        return ans;
    }
};
static bool comp(const vector<int>& v1, const vector<int>& v2) {
    return v1[1] < v2[1];
}
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int nn = queries.size();
        vector<int> ans(nn);
        vector<vector<int>> q(nn);
        for (int i = 0; i < nn; i++) {
            q[i] = {queries[i][0], queries[i][1], i};
        }
        sort(q.begin(), q.end(), comp);
        sort(nums.begin(), nums.end());
        int ind = 0;
        Trie* t = new Trie();
        for (auto it : q) {
            int x = it[0];
            int m = it[1];
            int i = it[2];

            while (ind < n && nums[ind] <= m) {
                t->insert(nums[ind]);
                ind += 1;
            }
            ans[i] = (t->maxixor(x));
        }
        return ans;
    }
};