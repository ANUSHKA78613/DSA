class Solution {
public:
    int numberOfWays(string corridor) {
        const int MOD = 1e9 + 7;

        // Step 1: Count total seats
        int totalSeats = 0;
        for (char c : corridor) {
            if (c == 'S') totalSeats++;
        }

        // If seats are odd or zero, no valid division
        if (totalSeats == 0 || totalSeats % 2 != 0)
            return 0;

        long long ways = 1;
        int seatCount = 0;
        int plantCount = 0;
        bool countingPlants = false;

        // Step 2: Traverse corridor
        for (char c : corridor) {
            if (c == 'S') {
                seatCount++;

                // After completing a pair, start counting plants
                if (seatCount % 2 == 0) {
                    countingPlants = true;
                    plantCount = 0;
                }
                // When next pair starts, calculate ways
                else if (countingPlants) {
                    ways = (ways * (plantCount + 1)) % MOD;
                    countingPlants = false;
                }
            } 
            else if (c == 'P' && countingPlants) {
                plantCount++;
            }
        }

        return ways;
    }
};
