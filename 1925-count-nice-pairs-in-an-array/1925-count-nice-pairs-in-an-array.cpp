class Solution {
public:
    int reverse(int n) {
        int rev = 0;
        while (n != 0) {
            rev = rev * 10 + n % 10;
            n /= 10;
        }
        return rev;
    }
    int fact(int n) {
        int f = 1;
        for (int i = 2; i <= n; i++) {
            f *= i;
        }
        return f;
    }
    int combi(int n, int r) { return fact(n) / fact(r) * fact(n - r); }

    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        unordered_map<int, int> m;

        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] - reverse(nums[i]);
        }
        for (int i = 0; i < n; i++) {
            if (m.find(nums[i]) != m.end()) {
                count = count % 1000000007;
                count += m[nums[i]];
                m[nums[i]]++;
            } else
                m[nums[i]]++;
        }
        return count % 1000000007;
    }
};

// Brute force approach => T.L.E
// class Solution {
// public:
//     int reverse(int n) {
//         int rev = 0;
//         while (n != 0) {
//             rev = rev * 10 + n % 10;
//             n /= 10;
//         }
//         return rev;
//     }

//     int countNicePairs(vector<int>& nums) {
//         int n = nums.size();
//         int count = 0;

//         for(int i = 0; i < n - 1; i++) {
//            for(int j = i + 1; j < n; j++) {
//             if((nums[i]+reverse(nums[j])) == (reverse(nums[i])+nums[j])) {
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };
