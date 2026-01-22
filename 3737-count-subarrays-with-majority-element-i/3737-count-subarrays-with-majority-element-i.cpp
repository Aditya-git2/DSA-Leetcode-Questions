class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        vector<int> check;
        for (auto i : nums) {
            if (i == target)
                check.push_back(1);
            else
                check.push_back(-1);
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += check[j];
                if (sum > 0)
                    ans++;
            }
        }
        return ans;
    }
};