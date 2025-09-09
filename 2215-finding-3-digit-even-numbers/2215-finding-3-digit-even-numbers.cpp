class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;

        // Step 1: Count frequency of digits in input array
        unordered_map<int, int> m;
        for (auto ele : arr) {
            m[ele]++;
        }

        // Step 2: Iterate through all 3-digit even numbers (100 to 999)
        for (int i = 100; i <= 999; i += 2) {
            int x = i;

            // Extract digits of current number
            int a = x % 10; // ones place digit
            x /= 10;
            int b = x % 10; // tens place digit
            x /= 10;
            int c = x; // hundreds place digit

            // Step 3: Try to form this number using available digits
            if (m.find(a) != m.end()) { // check if ones place digit exists
                m[a]--;                 // use one occurrence of digit a
                if (m[a] == 0)
                    m.erase(a);

                if (m.find(b) != m.end()) { // check if tens place digit exists
                    m[b]--;                 // use one occurrence of digit b
                    if (m[b] == 0)
                        m.erase(b);

                    if (m.find(c) != m.end()) { //if hundreds place digit exists
                        ans.push_back(i); // valid number → add to answer
                    }

                    m[b]++; // backtrack: restore tens digit
                }

                m[a]++; // backtrack: restore ones digit
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> findEvenNumbers(vector<int>& arr) {
//         int n = arr.size();
//         vector<int> ans;
//         unordered_map<int, int> m;
//         for (auto ele : arr) {
//             m[ele]++;
//         }
//         for (int i = 100; i <= 999; i += 2) {
//             int x = i;
//             int a = x % 10; // ones place digit
//             x /= 10;
//             int b = x % 10; // tens place digit
//             x /= 10;
//             int c = x;

//             if (m.find(a) != m.end()) {
//                 m[a]--;
//                 if (m[a] == 0)
//                     m.erase(a);
//                 if (m.find(b) != m.end()) {
//                     m[b]--;
//                     if (m[b] == 0)
//                         m.erase(b);
//                     if (m.find(c) != m.end()) {
//                         ans.push_back(i);
//                     }
//                     m[b]++;
//                 }
//                 m[a]++;
//             }
//         }
//         return ans;
//     }
// };