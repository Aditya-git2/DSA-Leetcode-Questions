class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;

        int i = 0; // pointer for x-values
        int j = n; // pointer for y-values

        while (i < n && j < 2 * n) {
            ans.push_back(nums[i]); // xi
            ans.push_back(nums[j]); // yi
            i++;
            j++;
        }
        return ans;
    }
};