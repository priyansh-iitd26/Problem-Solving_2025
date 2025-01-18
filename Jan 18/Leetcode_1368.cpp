// Leetcode 1368 : Minimum Cost to Make at Least One Valid Path in a Grid
// Link : https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description/

// Djikstra's Algorithm with cost as edge weight
class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));

        pq.push({0, 0, 0});
        ans[0][0] = 0;

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int currCost = curr[0];
            int currRow = curr[1];
            int currCol = curr[2]; 

            for(int i = 0; i <= 3; i++){
                int newRow = currRow + directions[i][0];
                int newCol = currCol + directions[i][1];

                if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n){
                    int currCellDirection = grid[currRow][currCol]; 
                    int directionCost = (currCellDirection - 1 != i ? 1 : 0);

                    int newCost = currCost + directionCost;

                    if(newCost < ans[newRow][newCol]){
                        ans[newRow][newCol] = newCost;
                        pq.push({newCost, newRow, newCol});
                    }
                }
            }
        } 
        
        return ans[m - 1][n - 1]; //min cost to reach (m-1, n-1)
    }
};
