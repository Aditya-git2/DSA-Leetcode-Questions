class Solution {
public:
    // Using frequency space
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> check(n + 1, 0); // if n=5 => 0,0,0,0,0
        for (int x : nums) {
            check[x]++;
            if (check[x] > 1)
                return x;
        }
        return -1;
    }

    // // Brute Force approach   T.C -> O(n*n)  S.C -> O(1)
    // int findDuplicate(vector<int>& nums) {
    //     int n = nums.size();
    //     // traverse array
    //     for (int i = 0; i < n - 1; i++) {
    //         // Compare the current element with the rest of the elements
    //         for (int j = i + 1; j < n; j++) {
    //             if (nums[i] == nums[j])
    //                 return nums[i]; // return duplicate element
    //         }
    //     }
    //     return -1; // if duplicate not found
    // }
};