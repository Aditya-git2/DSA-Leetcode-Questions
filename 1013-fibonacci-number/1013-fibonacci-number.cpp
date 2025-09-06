// 0  1  1  2  3  5  8  13  21 ...........    fibonacci sequence
class Solution {
public:
    // approach 2 => by dp
    // Helper function to compute Fibonacci using memoization
    int fibo(int n, vector<int>& dp) {
        if (n <= 1) return n; // Base case: fib(0) = 0, fib(1) = 1
        if (dp[n] != -1) return dp[n]; // If already computed,return stored result
        return dp[n] = fibo(n - 1, dp) + fibo(n - 2, dp);
    }
    int fib(int n) {
        vector<int> dp(n + 1, -1);
        return fibo(n, dp);
    }
};
/* approach1=> by recursion => as it is short and easy problem => not show T.L.E
class Solution {
public:
    // 0  1  1  2  3  5  8  13  21 ...........    fibonacci sequence
    int fib(int n) {
        // if(n<=1) return n;     // n is not -ve
        if (n == 0 || n == 1) return n;
        // fib(n) = fib(n-1) + fib(n-2)
        return fib(n - 1) + fib(n - 2);
    }
};
*/