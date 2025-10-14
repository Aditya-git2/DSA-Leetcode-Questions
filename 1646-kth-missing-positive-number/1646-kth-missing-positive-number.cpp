class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> s(arr.begin(), arr.end());
        int count = 0;
        int val = 1;
        while (true) {
            if (s.find(val) == s.end()) { // val not exist
                count++;
                if (count == k) return val;
            }
            val++;
        }
    }
};