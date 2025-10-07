class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int>ans(n,1);
        set<int>s;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(rains[i] > 0){
                int lake = rains[i];
               
                if(mp.count(lake)){
                    auto it = s.lower_bound(mp[lake]);
                    if(it == s.end()){
                        return {};
                    }
                    ans[*it] = lake;
                    s.erase(it);
                }
                 mp[lake] = i;
                ans[i] = -1;
            }
            else {
                s.insert(i);

            }
        }
        return ans;
    }
};