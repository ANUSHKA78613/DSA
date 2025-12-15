class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long ans = 1;   // first element
        long long c = 1;     // current descent length
        
        for (int i = 1; i < n; i++) {
            if (prices[i - 1] - prices[i] == 1) {
                c++;
            } else {
                c = 1;
            }
            ans += c;
        }
        return ans;
    }
};
