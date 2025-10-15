class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> result(nums.size());
        partial_sum(nums.begin(), nums.end(), result.begin());
        return result;
    }
};

// class Solution {
// public:
//     // Better approach
//     vector<int> runningSum(vector<int>& nums) {
//         int n = nums.size();
//         for (int i = 1; i < n; i++) {
//             nums[i]+=nums[i-1];
//         }
//         return nums;
//     }
// };

// Method 1
// class Solution {
// public:
//     vector<int> runningSum(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> run(n); // to store running sum;
//         run[0] = nums[0];
//         for (int i = 1; i < n; i++) {
//             run[i] = nums[i] + run[i - 1];
//         }
//         return run;
//     }
// };