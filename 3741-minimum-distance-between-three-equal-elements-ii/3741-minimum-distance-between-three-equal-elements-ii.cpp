class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> freq;
        for (int i = 0; i < n; i++) {
            freq[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for (auto p : freq) {
            auto v = p.second;

            if (v.size() >= 3) {
                for (int i = 0; i + 2 < v.size(); i++) {
                    int dist = 2 * (v[i + 2] - v[i]);
                    ans = min(ans, dist);
                }
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};