class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();

        vector<int> pre(n + 1); // to store no.of 'N' before nth hour
        vector<int> suf(n + 1); // to store no. of 'Y' after and including nth hour

        pre[0] = 0;
        for (int i = 0; i < n; i++) {
            // int count = 0;
            // if(customers[i] =='N') count++;
            // pre[i+1] = pre[i] + count;
            pre[i + 1] = pre[i] + ((customers[i] == 'N') ? 1 : 0);
        }

        suf[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1] + ((customers[i] == 'Y') ? 1 : 0);
        }

        int minPen = INT_MAX;
        for (int i = 0; i <= n; i++) {
            pre[i] += suf[i];
            minPen = min(minPen, pre[i]);
        }
        int ans;
        for (int i = 0; i <= n; i++) {
            if (pre[i] == minPen) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};