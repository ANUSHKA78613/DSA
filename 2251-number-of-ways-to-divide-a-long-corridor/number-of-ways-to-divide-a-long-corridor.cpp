class Solution {
public:
    int numberOfWays(string corridor) {
        const int mod = 1e9 + 7;
        long long zero = 0;
        long long one = 0;
        long long two = 1;
        
        for (char i : corridor) {
            if (i == 'S') {
                zero = one;
                swap(one, two);
            } else {
                two = (two + zero) % mod;
            }
        }
        return zero;
    }
};