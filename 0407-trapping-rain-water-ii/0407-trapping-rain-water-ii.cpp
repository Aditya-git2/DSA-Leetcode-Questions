class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        if (m <= 2 || n <= 2) return 0; // no trapping possible

        // Min-heap: stores {height, x, y}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Push all boundary cells
        for (int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][n - 1], i, n - 1});
            visited[i][0] = visited[i][n - 1] = true;
        }
        for (int j = 1; j < n - 1; j++) {
            pq.push({heightMap[0][j], 0, j});
            pq.push({heightMap[m - 1][j], m - 1, j});
            visited[0][j] = visited[m - 1][j] = true;
        }

        // Directions
        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        int trapped = 0;

        while (!pq.empty()) {
            auto cell = pq.top(); pq.pop();
            int h = cell[0], x = cell[1], y = cell[2];

            for (auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) continue;

                visited[nx][ny] = true;

                // If neighbor is lower, trap water
                trapped += max(0, h - heightMap[nx][ny]);

                // Update boundary height
                pq.push({max(h, heightMap[nx][ny]), nx, ny});
            }
        }

        return trapped;
    }
};
