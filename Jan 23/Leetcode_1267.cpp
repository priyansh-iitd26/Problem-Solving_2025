// Problem Link : https://leetcode.com/problems/count-servers-that-communicate/description/

// Brute force approach (TC : O(m*n*(m+n)), SC = O(1))
class Solution {
public:
    int m, n;
    bool canCommunicateinCol(vector<vector<int>>& grid, int row, int col){
        for(int i = 0; i < m; i++){
            if(i != row && grid[i][col] == 1){
                return true;
            }
        }
        return false;
    }
    bool canCommunicateinRow(vector<vector<int>>& grid, int row, int col){
        for(int j = 0; j < n; j++){
            if(j != col && grid[row][j] == 1){
                return true;
            }
        }
        return false;
    }

    int countServers(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int cnt = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0)
                    continue;
                else if(canCommunicateinRow(grid, i, j) || canCommunicateinCol(grid, i, j)){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};

// Better Approach (TC : O(m*n), SC : O(m+n))
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> rowServerCount(m, 0);
        vector<int> colServerCount(n, 0);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    rowServerCount[i]++;
                    colServerCount[j]++;
                }
            }
        }

        int ans = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    if(rowServerCount[i] > 1 || colServerCount[j] > 1){
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};
