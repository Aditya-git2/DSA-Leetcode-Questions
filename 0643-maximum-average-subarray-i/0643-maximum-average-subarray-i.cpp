class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i = 0, j = 0;
        double sum = 0, maxSum = INT_MIN;

        while (j < nums.size()) {
            sum += nums[j]; // add current element

            if (j - i + 1 < k) j++;                       // expand window
            else if (j - i + 1 == k) {     // window size == k
                maxSum = max(maxSum, sum); // update max
                sum -= nums[i];             // remove first element
                i++; j++;                  // slide window
            }
        }
        return maxSum / k;   // max average = maxSum/k
    }
};