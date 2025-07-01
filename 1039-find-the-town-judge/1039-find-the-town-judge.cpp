#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_set<string> trustset;

    bool f(int first, int last) {
        return trustset.count(to_string(first) + "," + to_string(last));
    }

    int findJudge(int n, vector<vector<int>>& trust) {
        if(n == 1) return 1;
        if(trust.size() == 0) return -1;

        // Preprocess trust into unordered_set for O(1) lookup
        for(auto& t : trust) {
            trustset.insert(to_string(t[0]) + "," + to_string(t[1]));
        }

        int first = 1;
        int last = n;

        while(first < last) {
            if(f(first, last)) {
                first++;
            } else if(f(last, first)) {
                last--;
            } else {
                first++;
                last--;
            }
        }

        if(last > first) return -1;

        // Check that candidate doesn't trust anyone
        for(auto& t : trust) {
            if(t[0] == first) return -1;
        }

        // Check that candidate is trusted by exactly (n - 1) others
        int cnt = 0;
        for(auto& t : trust) {
            if(t[1] == first) cnt++;
        }

        if(cnt != n - 1) return -1;

        return first;
    }
};
