class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101, 0); // supports nums[i] in range [1, 100]

        // Count frequencies
        for (int x : nums) {
            freq[x]++;
        }

        // Find the maximum frequency
        int maxFreq = 0;
        for (int x : freq) {
            maxFreq = max(maxFreq, x);
        }

        // Count how many elements have that max frequency
        int count = 0;
        for (int x : freq) {
            if (x == maxFreq)
                count++;
        }

        return maxFreq * count;
    }
};
