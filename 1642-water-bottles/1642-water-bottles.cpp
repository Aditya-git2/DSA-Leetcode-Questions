class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        long long totalDrunk = numBottles;
        long long empty = numBottles;
        while (empty >= numExchange) {
            long long newBottles = empty / numExchange;
            totalDrunk += newBottles;
            empty = (empty % numExchange) + newBottles;
        }
        return (int)totalDrunk; // C style Typecasting => less safe
        // C++ style TypeCasting => type checked
        //  return static_cast<int>(totalDrunk);
    }
};