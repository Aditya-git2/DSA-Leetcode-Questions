class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        int n = nums.size();
        
        // Try all rotations of sorted array
        for (int i = 0; i < n; ++i) {
            bool match = true;
            for (int j = 0; j < n; ++j) {
                if (nums[j] != sorted[(i + j) % n]) {
                    match = false;
                    break;
                }
            }
            if (match) return true;
        }
        return false;
    }
};

// class Solution {
// public:
//     bool check(vector<int>& nums) {
//         int count = 0;
//         int n = nums.size();
//         for (int i = 0; i < n; ++i) {
//             if (nums[i] > nums[(i + 1) % n]) {
//                 count++;
//             }
//         }
//         return count <= 1;
//     }
// };
