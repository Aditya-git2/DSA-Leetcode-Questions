class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();

        sort(satisfaction.begin(), satisfaction.end());  // sort dishes

        // Suffix sum array
        vector<int> suf(n);
        suf[n - 1] = satisfaction[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = satisfaction[i] + suf[i + 1];
        }

        // Find first index where total future sum becomes positive -> pivot idx
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (suf[i] > 0) {      // keep dishes from here
                idx = i;
                break;
            }
        }

        if (idx == -1) return 0;   // discard all dishes if all negative

        // Compute like time coefficient from pivot index onward
        int x = 1, ans = 0;
        for (int i = idx; i < n; i++) {
            ans += satisfaction[i] * x;
            x++;
        }

        return ans;
    }
};
