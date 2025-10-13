class Solution {    // Brute force approach => T.C => O(n*n)
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans; // vector to store answer
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    ans.push_back(i); // push i in ans
                    ans.push_back(j); // push j in ans
                    return ans;
                }
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> ans; // vector to store ans
//         int n = nums.size();
//         unordered_map<int, int> m;
//         for (int i = 0; i < n; i++) {
//             int rem = target - nums[i];
//             if (m.find(rem) != m.end()) {
//                 ans.push_back(m[rem]);
//                 ans.push_back(i);
//             } else
//                 m[nums[i]] = i;
//         }
//         return ans;
//     }
// };
