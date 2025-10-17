class Solution {
public:
    void sortColors(vector<int>& nums) { // Two pass solution
        int n = nums.size();
        int noz = 0, noo = 0;
        for (int x : nums) {
            if (x == 0)
                noz++;
            if (x == 1)
                noo++;
        }
        // filling elements
        for (int i = 0; i < n; i++) {
            if (i < noz)
                nums[i] = 0;
            else if (i < (noz + noo))
                nums[i] = 1;
            else
                nums[i] = 2;
        }
    }
};