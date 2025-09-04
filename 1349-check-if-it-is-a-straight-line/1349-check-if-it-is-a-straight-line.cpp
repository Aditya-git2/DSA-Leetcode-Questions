class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x1 = coordinates[0][0], y1 = coordinates[0][1]; // point 1
        int x2 = coordinates[1][0], y2 = coordinates[1][1]; // point 2
        for (int i = 2; i < coordinates.size(); i++) {
            int x3 = coordinates[i][0], y3 = coordinates[i][1]; // point 3
            if ((x2 - x1)*(y3 - y2) != (y2 - y1)*(x3 - x2))  // slope checking
                return false;   // non coolinear
        }
        return true;   // coolinear
    }
};