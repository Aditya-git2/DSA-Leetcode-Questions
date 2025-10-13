class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0; // Pointer to track the position of unique elements
        for (int j = 0; j < n; j++) {
            if (nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
        }
        // return no. of unique elements
        return i + 1;
    }
};