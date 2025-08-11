#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

class Solution {
public:
    ll modpow(ll base, ll exp) {
        ll res = 1;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return res;
    }
    
    ll modInverse(ll a) {
        return modpow(a, mod - 2);
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        // Step 1: Build powers array
        vector<int> powers;
        for (int i = 0; i < 31; i++) {
            if (n & (1 << i)) {
                powers.push_back(1 << i);
            }
        }
        
        // Step 2: Prefix products
        int m = powers.size();
        vector<ll> prefix(m + 1, 1);
        for (int i = 0; i < m; i++) {
            prefix[i + 1] = (prefix[i] * powers[i]) % mod;
        }
        
        // Step 3: Answer queries
        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            ll prod = (prefix[r + 1] * modInverse(prefix[l])) % mod;
            ans.push_back((int)prod);
        }
        return ans;
    }
};
