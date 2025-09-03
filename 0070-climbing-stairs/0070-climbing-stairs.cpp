class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;   // only one way
        if (n == 2) return 2;   // 2 ways
        int first = 1, second = 2, curr;
        for (int i = 3; i <= n; i++) {
            curr = first + second;
            first = second;
            second = curr;
        }
        return second;
    }
};