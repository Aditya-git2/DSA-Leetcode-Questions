class Solution { // Tabulation method
public:
    // 1 => obstacle  0=> no obstacle
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();                   // no. of rows
        int n = obstacleGrid[0].size();                // no. of cols
        vector<vector<int>> dp(m, vector<int>(n, 0)); // Dp array with value 0
        // start cell
        if (obstacleGrid[0][0] == 1)
            return 0; // obstacle at start point
        dp[0][0] = 1;
        // First row
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[0][j] == 0)
                dp[0][j] = dp[0][j - 1];
        }
        // First column
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 0)
                dp[i][0] = dp[i - 1][0];
        }
        // rest of the grid
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0) { // no obstacle
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
// class Solution {   // Rcursive + Memorization(using extra 2D dp array)
// public:
//     int helper(int sr,int sc,int er,int ec,vector<vector<int>>&
//     obstacleGrid,vector<vector<int>>& dp){
//         if(sr>er || sc>ec) return 0;   // out of bound
//         if(obstacleGrid[sr][sc] == 1) return 0;   // obstacle
//         if(sr==er && sc ==ec) return 1;   // final destination
//         if(dp[sr][sc] != -1) return dp[sr][sc];
//         return dp[sr][sc] = helper(sr,sc+1,er,ec,obstacleGrid,dp)
//         +helper(sr+1,sc,er,ec,obstacleGrid,dp);
//     }
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size();   // no. of rows
//         int n = obstacleGrid[0].size();   // no. of cols
//         vector<vector<int>>dp(m,vector<int>(n,-1));   // Dp array
//         return helper(0,0,m-1,n-1,obstacleGrid,dp);
//     }
// };
// class Solution {   // Rcursive solution
// public:
//     int helper(int sr,int sc,int er,int ec,vector<vector<int>>&
//     obstacleGrid){
//         if(sr>er || sc>ec) return 0;   // out of bound
//         if(obstacleGrid[sr][sc] == 1) return 0;   // obstacle
//         if(sr==er && sc ==ec) return 1;   // final destination
//         return helper(sr,sc+1,er,ec,obstacleGrid)
//         +helper(sr+1,sc,er,ec,obstacleGrid);
//     }
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size();   // no. of rows
//         int n = obstacleGrid[0].size();   // no. of cols
//         return helper(0,0,m-1,n-1,obstacleGrid);
//     }
// };
