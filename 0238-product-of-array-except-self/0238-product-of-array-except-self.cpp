// class Solution {
// public:
//     // using 1 extra vectors
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();

//         int p = nums[0]; // running prefix product
//         vector<int> pre(n);
//         pre[0] = 1; // no prefix for 1st element
//         for (int i = 1; i < n; i++) {
//             pre[i] = p;   // store prefix product first
//             p *= nums[i]; // update prefix
//         }

//         p = nums[n - 1]; // reset p for suffix
//         for (int i = n - 2; i >= 0; i--) {
//             pre[i] *= p;   // multiply with product of elements after i
//             p *= nums[i]; // update suffix
//         }

//         return pre;
//     }
// };

class Solution {
public:
    // using 2 extra vectors
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        int p = nums[0]; // running prefix product
        vector<int> pre(n);
        pre[0] = 1; // no prefix for 1st element
        for (int i = 1; i < n; i++) {
            pre[i] = p;   // store prefix product first
            p *= nums[i]; // update prefix
        }

        p = nums[n - 1]; // reset p for suffix
        vector<int> suf(n);
        suf[n - 1] = 1; // no suffix for last element
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = p;   // store suffix product first
            p *= nums[i]; // update suffix
        }

        for (int i = 0; i < n; i++) {
            pre[i] = pre[i] * suf[i]; // prefix * suffix
        }

        return pre;
    }
};

// class Solution {
// public:
//     // using 3 extra vectors
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();

//         int p = nums[0]; // running prefix product
//         vector<int> pre(n);
//         pre[0] = 1; // no prefix for 1st element
//         for (int i = 1; i < n; i++) {
//             pre[i] = p;   // store prefix product first
//             p *= nums[i]; // update prefix
//         }

//         p = nums[n - 1]; // reset p for suffix
//         vector<int> suf(n);
//         suf[n - 1] = 1; // no suffix for last element
//         for (int i = n - 2; i >= 0; i--) {
//             suf[i] = p;   // store suffix product first
//             p *= nums[i]; // update suffix
//         }

//         vector<int> ans(n); // final result
//         for (int i = 0; i < n; i++) {
//             ans[i] = pre[i] * suf[i]; // prefix * suffix
//         }

//         return ans;
//     }
// };
