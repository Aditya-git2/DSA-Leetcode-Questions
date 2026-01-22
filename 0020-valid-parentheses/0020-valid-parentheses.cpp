class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0)
            return false; // odd length can't be valid

        stack<char> st;

        for (char c : s) {
            // push opening brackets
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                // if stack empty → invalid (no match for closing)
                if (st.empty())
                    return false;

                // check matching type
                if ((c == ')' && st.top() != '(') ||
                    (c == ']' && st.top() != '[') ||
                    (c == '}' && st.top() != '{')) {
                    return false;
                }
                st.pop(); // remove the matched one
            }
        }
        // valid only if all brackets matched
        return st.empty();
    }
};