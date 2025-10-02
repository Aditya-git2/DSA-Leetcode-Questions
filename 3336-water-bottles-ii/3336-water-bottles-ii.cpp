class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        long long totalDrunk = numBottles;
        long long empty = numBottles;
        while (empty >= numExchange) {
            // perform one exchange
            empty = empty - numExchange; // pay the cost
            totalDrunk++;                // drink new bottle
            empty++;                     // new bottle became empty
            numExchange++;               // cost increase
        }
        return totalDrunk;
    }
};