class Solution {
public:
    void reversePart(vector<int>& arr, int st, int end) {
        while (st < end) {
            swap(arr[st], arr[end]);
            st++;
            end--;
        }
    }
    void rotate(vector<int>& arr, int d) {
        int n = arr.size();
        if (d > n)
            d = d % n;
        reversePart(arr, 0, n - d - 1);
        reversePart(arr, n - d, n - 1);
        reversePart(arr, 0, n - 1);
    }
};

// class Solution {
// public:
//     void rotate(vector<int>& arr, int d) {
//         int n = arr.size();
//         // to handle d>n
//         d%=n;
//         // Reverse the last d elements
//         reverse(arr.end() - d, arr.end());
//         // Reverse the first n-d elements
//         reverse(arr.begin(), arr.end() - d);
//         // Reverse the entire array
//         reverse(arr.begin(), arr.end());
//     }
// };