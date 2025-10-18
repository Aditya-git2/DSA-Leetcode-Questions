class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();    // no. of rows
        int n = matrix[0].size(); // no. of columns

        // 2d vector of n*m to store transpose
        vector<vector<int>> t(n, vector<int>(m));
        // store
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                t[i][j] = matrix[j][i];
            }
        }
        return t;
    }
};