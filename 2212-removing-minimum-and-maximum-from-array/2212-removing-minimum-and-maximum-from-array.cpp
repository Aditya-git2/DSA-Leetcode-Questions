class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIdx = 0, maxIdx = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIdx]) minIdx = i;
            if (nums[i] > nums[maxIdx]) maxIdx = i;
        }

        if (minIdx > maxIdx) swap(minIdx, maxIdx);

        int option1 = maxIdx + 1;               // front
        int option2 = n - minIdx;               // back
        int option3 = (minIdx + 1) + (n - maxIdx);  // both ends

        return min({option1, option2, option3});
    }
};


// class Solution {
// public:
//     int minimumDeletions(vector<int>& nums) {
//         int n = nums.size();
//         int minVal = INT_MAX;
//         int maxVal = INT_MIN;
//         int minIdx = -1, maxIdx = -1;

//         // Find indices of the minimum and maximum elements
//         for (int i = 0; i < n; i++) {
//             if (nums[i] < minVal) {
//                 minVal = nums[i];
//                 minIdx = i;
//             }
//             if (nums[i] > maxVal) {
//                 maxVal = nums[i];
//                 maxIdx = i;
//             }
//         }

//         // Option 1: Delete from front
//         int option1 = max(minIdx, maxIdx) + 1;

//         // Option 2: Delete from back
//         int option2 = n - min(minIdx, maxIdx);

//         // Option 3: Delete from both ends
//         int option3 = (minIdx + 1) + (n - maxIdx);
//         int option4 = (maxIdx + 1) + (n - minIdx);

//         // Return the minimum of all options
//         return min({option1, option2, option3, option4});
//     }
// };
