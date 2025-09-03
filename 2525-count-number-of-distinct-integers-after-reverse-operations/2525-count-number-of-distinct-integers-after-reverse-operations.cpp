class Solution {
public:
    // Function to reverse digits of an integer
    int reverse(int n) {
        int r = 0;
        while (n != 0) {
            r = r * 10 + (n % 10); // append last digit of n to r
            n /= 10;               // remove last digit from n
        }
        return r;
    }

    // Count distinct integers after inserting each number and its reverse
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s; // stores unique numbers
        for (int i = 0; i < nums.size(); i++) {
            int rev = reverse(nums[i]); 
            s.insert(nums[i]);          // insert original 
            s.insert(rev);              // insert reversed
        }
        return s.size(); // return count of unique numbers
    }
};
