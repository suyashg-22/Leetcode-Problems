#include <algorithm> // For sort
#include <vector>

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<vector<int>> ret;

        // Iterate through items1
        for (int i = 0; i < items1.size(); i++) {
            bool found = false;
            // Search for matching item in items2
            for (int j = 0; j < items2.size(); j++) {
                if (items1[i][0] == items2[j][0]) {
                    ret.push_back({items1[i][0], items1[i][1] + items2[j][1]});
                    found = true;
                    break;
                }
            }
            // If no match found in items2, add the item from items1
            if (!found) {
                ret.push_back(items1[i]);
            }
        }

        // Add remaining items from items2 that are not in items1
        for (int j = 0; j < items2.size(); j++) {
            bool found = false;
            for (int i = 0; i < items1.size(); i++) {
                if (items2[j][0] == items1[i][0]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                ret.push_back(items2[j]);
            }
        }

        // Sort the result vector
        sort(ret.begin(), ret.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        return ret;
    }
};
