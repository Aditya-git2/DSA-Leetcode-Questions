class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false; // lengths must be equal 
    return (s + s).find(goal) != string::npos;
    // Concatenate the string with itself → s + s => "abcde" + "abcde" = "abcdeabcde"
    // All possible rotations of s are contained inside s + s
    // temp.find(goal) → searches for the substring goal inside temp
    // If it finds it, it returns the starting index (like 0, 1, 2, ...) 
    // If it doesn’t find it, it returns a special value string::npos (which means
    //  “not found”)
    }
};

// class Solution {
// public:
//     bool rotateString(string s, string goal) {
//         if (s.length() != goal.length()) return false; // lengths must be equal 
//         int n = s.length();
//         string temp = s + s;
//         // check every rotation
//         for (int i = 0; i < n; i++) {
//             string rotated = temp.substr(i, n); // take substring of length n
//             if (rotated == goal)
//                 return true; // found matching rotation
//         }
//         return false;
//     }
// };
