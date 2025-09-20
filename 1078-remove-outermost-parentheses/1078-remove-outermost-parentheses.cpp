class Solution {
public:
    string removeOuterParentheses(string s) {
        string result; // to store result
        int depth = 0; // to track current depth of parenthesis
        for (char ch : s) {
            if (ch == '(') {
                //  if depth > 0 => it means it is not outer parenthesis 
                //  so add it to result
                if (depth > 0) {
                    result += ch;
                }
                depth++; // Increase depth for every '('
            } else {     // if((ch == ')')
                depth--; // Derease depth for every ')'
                if (depth > 0) {
                    result += ch;
                }
            }
        }
        return result;
    }
};