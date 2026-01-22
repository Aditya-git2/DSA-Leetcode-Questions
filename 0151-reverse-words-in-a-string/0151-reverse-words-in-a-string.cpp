class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();

        // reverse whole string
        reverse(s.begin(), s.end());

        int i = 0;  // to traverse in string
        int l = 0, r = 0; // l and r words ko reverse karne mein help karenge

        while (i < n) {

            // skip spaces
            while (i < n && s[i] == ' ') i++;

            // copy word
            while (i < n && s[i] != ' ') {
                s[r++] = s[i++];
            }

            if (l < r) {
                reverse(s.begin() + l, s.begin() + r);
                s[r++] = ' ';
                l = r;
            }
        }

        // remove trailing space
        if (r > 0) r--;

        return s.substr(0, r);
    }
};
