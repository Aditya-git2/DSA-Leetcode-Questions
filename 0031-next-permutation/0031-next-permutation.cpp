class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;

        // Step 1: Find first decreasing element from the end
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }

        // Step 2: If not found, reverse whole array
        if (idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Reverse the part after idx
        reverse(nums.begin() + idx + 1, nums.end());

        // Step 4: Find element just larger than nums[idx] and swap
        for (int i = idx + 1; i < n; i++) {
            if (nums[i] > nums[idx]) {
                swap(nums[idx], nums[i]);
                break;
            }
        }
    }
};
