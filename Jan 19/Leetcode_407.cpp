// Problem Link : https://leetcode.com/problems/trapping-rain-water-ii/description/
//MIK's video for detailed intuition and visualization : https://www.youtube.com/watch?v=TzsbIDtTlsQ
class Solution {
public:
    
    typedef pair<int, pair<int, int>> ppi;
    vector<vector<int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        priority_queue<ppi, vector<ppi>, greater<>> boundaryCells; //min-heap -> {height, {row, col}}

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        //top most row and bottom most row (0, m - 1)
        for(int col = 0; col < n; col++){
            for(int row : {0, m - 1}){
                boundaryCells.push({heightMap[row][col], {row, col}});
                visited[row][col] = true;
            }
        }

        //leftmost and rightmost column (0, n - 1)
        for(int row = 0; row < m; row++){
            for(int col : {0, n - 1}){
                boundaryCells.push({heightMap[row][col], {row, col}});
                visited[row][col] = true;
            }
        }

        int water = 0;

        while(!boundaryCells.empty()){
            auto p = boundaryCells.top();
            boundaryCells.pop();

            int height = p.first;
            int row = p.second.first;
            int col = p.second.second;

            //explore neighbors
            for(vector<int>& dir : directions){
                int nrow = row + dir[0];
                int ncol = col + dir[1];

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !visited[nrow][ncol]){
                    visited[nrow][ncol] = true;
                    water += max(height - heightMap[nrow][ncol], 0);
                    boundaryCells.push({max(height, heightMap[nrow][ncol]), {nrow, ncol}});
                }
            }
        }

        return water;
    }
};
