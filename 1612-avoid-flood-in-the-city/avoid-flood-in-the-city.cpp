class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1);  // Default dry any lake if needed
        unordered_map<int,int> full; // lake -> last day it rained
        set<int> dryDays;           // indices of days we can dry a lake

        for(int i = 0; i < n; i++) {
            if(rains[i] > 0) {
                int lake = rains[i];
                
                // Check if this lake is already full
                if(full.count(lake)) {
                    // Find a dry day after last rain of this lake
                    auto it = dryDays.lower_bound(full[lake]);
                    if(it == dryDays.end()) {
                        // No dry day available → flood occurs
                        return {};
                    }
                    // Use this dry day to empty the lake
                    ans[*it] = lake;
                    dryDays.erase(it);
                }
                
                // Mark lake as full on this day
                full[lake] = i;
                ans[i] = -1;  // Rain days must be -1
            } else {
                // Dry day, store index for future use
                dryDays.insert(i);
            }
        }

        return ans;
    }
};
