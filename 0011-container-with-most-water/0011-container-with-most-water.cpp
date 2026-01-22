class Solution {
public:
    int maxArea(vector<int>& height) {   // T.C => O(n)    // most optimal = 2 pointer approach
        int n = height.size();
        int lb = 0, rb = n-1;   // lb => left Boundary  rb => right Boundary  
        int maxWater = 0;
        while(lb < rb) {
            //  width = (rb - lb)    height = min(height[lb],height[rb])
            int currWater = (rb - lb) * min(height[lb],height[rb]);
            maxWater = max(maxWater,currWater);
            // height of the container depends on the min boundary => lb & rb will move acc to that
            height[lb] < height[rb] ? lb++ : rb--; 
        }
        return maxWater;
    }
};
// class Solution {
// public:
//     int maxArea(vector<int>& height) {   // T.C => O(n*n)    // T.L.E
//         int n = height.size();
//         int maxWater = 0;
//         for (int i = 0; i < n - 1; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 // width = j - i     height = min(height[i], height[j]);
//                 int area = (j-i) * min(height[i], height[j]);
//                 maxWater = max(maxWater, area);
//             }
//         }
//         return maxWater;
//     }
// };