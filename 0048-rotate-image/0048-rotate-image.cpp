class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // transpose
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // swap i,j to j,i
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // reverse each row of transpose matrix
        for (int k = 0; k < n; k++) { // for rows
            // reverse -> Two pointer
            int i = 0;
            int j = n - 1;
            while (i <= j) {
                swap(matrix[k][i], matrix[k][j]);
                i++;
                j--;
            }
        }
        return;
    }
};