class Solution {
public:
    // 0  1  1  2  3  5  8  13  21 ...........    fibonacci sequence
    int fib(int n) {
        if (n == 0 || n == 1) return n;
        // fib(n) = fib(n-1) + fib(n-2)
        return fib(n - 1) + fib(n - 2);
    }
};