class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> altitudes(n + 1);
        // Building prefix sum array
        altitudes[0] = 0;
        for (int i = 1; i <= n; i++) {
            altitudes[i] = gain[i - 1] + altitudes[i - 1];
        }
        // finding highest altitude
        int highest = -1;
        for (int i = 0; i <= n; i++) {
            highest = max(highest, altitudes[i]);
        }
        return highest;
    }
};