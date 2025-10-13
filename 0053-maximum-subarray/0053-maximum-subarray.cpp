class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0;
        int maxSum = INT_MIN;

        for (int x : nums) { // Travel all elements in nums
            currSum += x;
            // Why this condition not here?
            // if (currSum < 0)  currSum = 0;
            // to tackle edge case where all elements are -ve
            maxSum = max(currSum, maxSum);
            if (currSum < 0)
                currSum = 0;
        }
        return maxSum;
    }
};