class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int leftSum = 0;
            int rightSum = 0;

            // Calculate sum of elements to the left of index i
            for (int j = 0; j < i; j++) {
                leftSum += nums[j];
            }

            // Calculate sum of elements to the right of index i
            for (int j = i + 1; j < n; j++) {
                rightSum += nums[j];
            }

            // Check if left and right sums are equal
            if (leftSum == rightSum) {
                return i;  // Return the first pivot index found
            }
        }

        // If no pivot index found
        return -1;
    }
};


// class Solution {     // Brute force approach
// public:
//     int pivotIndex(vector<int>& nums) {
//         int n = nums.size();

//         for (int i = 0; i < n; i++) {
//             int leftSum = 0;
//             int rightSum = 0;

//             // Calculate sum of elements to the left of index i
//             for (int j = 0; j < i; j++) {
//                 leftSum += nums[j];
//             }

//             // Calculate sum of elements to the right of index i
//             for (int j = i + 1; j < n; j++) {
//                 rightSum += nums[j];
//             }

//             // Check if left and right sums are equal
//             if (leftSum == rightSum) {
//                 return i; // Return the first pivot index found
//             }
//         }

//         // If no pivot index found
//         return -1;
//     }
// };
