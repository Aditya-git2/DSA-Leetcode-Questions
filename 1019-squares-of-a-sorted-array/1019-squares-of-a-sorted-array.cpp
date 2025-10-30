class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        vector<int> res;
        while (i <= j) {
            if (abs(nums[i]) > abs(nums[j])) {
                res.push_back(nums[i] * nums[i]);
                i++;
            } else {
                res.push_back(nums[j] * nums[j]);
                j--;
            }
        }
        reverse(res.begin(), res.end());

        return res;
    }
    // vector<int> sortedSquares(vector<int>& nums) {   // T.C -> O(nlogn)
    //     int n = nums.size();
    //     // -4 -1 0 3 10    -> initially nums
    //     for (int i = 0; i < n; i++) {
    //         nums[i] *= nums[i];
    //     }
    //     // 16 1 0 3 10  -> after squaring each element of nums
    //     sort(nums.begin(), nums.end()); // sort array
    //     return nums;
    // }
};