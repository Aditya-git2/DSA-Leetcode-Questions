class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;
        // Dutch flag algorithm -> 3 pointer approach
        // mid ke baare mein socho
        // 0 -> low-1 ==> 0's    low->high-1 ==> 1's   remaining -> 2's

        while (mid <= high) {
            if (nums[mid] == 2) {
                swap(nums[mid], nums[high]);
                high--;
            } else if (nums[mid] == 1) {
                mid++;
            } else if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
        }
    }
};

// class Solution {
// public:
//     void sortColors(vector<int>& nums) { // Two pass solution
//         int n = nums.size();
//         int noz = 0, noo = 0;
//         for (int x : nums) {
//             if (x == 0)
//                 noz++;
//             if (x == 1)
//                 noo++;
//         }
//         // filling elements
//         for (int i = 0; i < n; i++) {
//             if (i < noz)
//                 nums[i] = 0;
//             else if (i < (noz + noo))
//                 nums[i] = 1;
//             else
//                 nums[i] = 2;
//         }
//     }
// };