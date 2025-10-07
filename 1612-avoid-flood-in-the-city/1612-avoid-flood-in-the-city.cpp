#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, -1);
        unordered_map<int, int> lastRain;  // lake → last day it rained
        set<int> dryDays;  // stores indices of dry days (0s)

        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                dryDays.insert(i);  // this day can be used later
            } else {
                int lake = rains[i];
                if (lastRain.count(lake)) {
                    // this lake was already full → must dry before today
                    auto it = dryDays.lower_bound(lastRain[lake]);
                    if (it == dryDays.end()) return {}; // no dry day found
                    int dryDay = *it;
                    if (dryDay < i) {
                        ans[dryDay] = lake;  // dry this lake
                        dryDays.erase(it);
                    } else return {}; // invalid sequence
                }
                lastRain[lake] = i;
                ans[i] = -1;
            }
        }

        // Fill remaining dry days arbitrarily with 1
        for (int i : dryDays) ans[i] = 1;

        return ans;
    }
};
