class Solution {
public:
    void allSubsets(vector<int>& nums, int i, vector<int>& curr, vector<vector<int>>& res) {
        if (i == nums.size()) {
            res.push_back(curr); // store current subset
            return;
        }

        // include nums[i]
        curr.push_back(nums[i]);
        allSubsets(nums, i + 1, curr, res);

        // exclude nums[i]
        curr.pop_back();
        allSubsets(nums, i + 1, curr, res);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        allSubsets(nums, 0, curr, res);
        return res;
    }
};
