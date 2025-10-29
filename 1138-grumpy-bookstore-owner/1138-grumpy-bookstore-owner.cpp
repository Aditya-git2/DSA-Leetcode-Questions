class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        // customers = [1,0,1,2,1,1,7,5]       minutes = 3
        //--- grumpy = [0,1,0,1,0,1,0,1]

        int n = customers.size();
        // finding window having most loss of satisfaction
        int prevLoss = 0;
        for (int i = 0; i < minutes; i++) {
            if (grumpy[i] == 1)
                prevLoss += customers[i];
        }
        int maxLoss = prevLoss;
        int maxIdx = 0;
        // Sliding window
        int i = 1;
        int j = minutes;
        while (j < n) {
    // currLoss = prevLoss + (customers[j] ---if grumpy[j]==1) - (customers[i] ---if grumpy[i-1]==)
            int currLoss = prevLoss;
            if (grumpy[j] == 1)
                currLoss += customers[j];
            if (grumpy[i - 1] == 1)
                currLoss -= customers[i - 1];
            if (maxLoss < currLoss) {
                maxLoss = currLoss;
                maxIdx = i;
            }
            prevLoss = currLoss;
            i++;
            j++;
        }
        // filling 0's in grumpy array window in which max loss of satisfaction
        for (int i = maxIdx; i < maxIdx + minutes; i++) {
            grumpy[i] = 0;
        }
        // sum of satisfaction => which we have to return
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0)
                sum += customers[i];
        }
        return sum;
    }
};