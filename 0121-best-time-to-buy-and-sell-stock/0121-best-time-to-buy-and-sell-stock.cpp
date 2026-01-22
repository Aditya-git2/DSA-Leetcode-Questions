// class Solution {
// public:
//     // Goal: Find the maximum profit by choosing best day to buy and best day to sell
//     int maxProfit(vector<int>& prices) {
//         int maxProfit = 0;
//         int bestBuy = prices[0];  // assume we buy on day 1

//         for (int i = 1; i < prices.size(); i++) {
//             // if selling today gives profit, update maxProfit
//             if (prices[i] > bestBuy) {
//                 maxProfit = max(maxProfit, prices[i] - bestBuy);
//             }
//             // check if today's price is better for buying
//             bestBuy = min(bestBuy, prices[i]);
//         }

//         return maxProfit;  
//     }
// };


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestBuy = INT_MAX, maxProfit = 0;

        for (int price : prices) {
            bestBuy = min(bestBuy, price);          // track lowest price
            maxProfit = max(maxProfit, price - bestBuy);  // update profit
        }
        return maxProfit;
    }
};
