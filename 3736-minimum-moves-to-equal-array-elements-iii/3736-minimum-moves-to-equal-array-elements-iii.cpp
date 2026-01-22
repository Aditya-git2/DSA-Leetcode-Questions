class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int moves = 0;
        for (auto x : nums) {
            moves += (nums[n - 1] - x);
        }
        return moves;
    }
};