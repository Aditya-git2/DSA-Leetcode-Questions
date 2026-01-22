class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int x : nums){
            ans ^= x;
        }
        return ans;
    }
};
// XOR of two same numbers is always 0 i.e. a ^ a = 0. ←Property 1.
// XOR of a number with 0 will result in the number itself i.e. 0 ^ a = a.  ←Property 2