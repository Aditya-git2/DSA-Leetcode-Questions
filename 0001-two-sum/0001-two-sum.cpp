class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans; // vector to store ans
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    ans.push_back(i); // push i in vector
                    ans.push_back(j); // push j in vector
                    return ans;
                }
            }
        }
        return ans;
    }
};