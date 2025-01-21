// Classic DP Problem Link : https://leetcode.com/problems/count-paths-with-the-given-xor-value/description/

// NOTE :
// The fact that one can move only right and below is important in solving this via DP.
// That makes it a DAG (directed acyclic graph). And we could use DFS with DP in this problem.

// Recursive + Memoization
class Solution {
public:
    const int MOD = 1e9 + 7;
    int m, n;
    int dp[301][301][17];

    int solve(vector<vector<int>>& grid, int i, int j, int xorr, int k){
        if(i == m - 1 && j == n - 1){
            xorr ^= grid[i][j];
            return xorr == k;
        }

        if(dp[i][j][xorr] != -1)
            return dp[i][j][xorr];

        int pathCnt = 0;

        //right
        if(j + 1 < n){
            pathCnt = (pathCnt + solve(grid, i, j + 1, xorr ^ grid[i][j], k)) % MOD;
        }
        //down
        if(i + 1 < m){
            pathCnt = (pathCnt + solve(grid, i + 1, j, xorr ^ grid[i][j], k)) % MOD;
        }

        return dp[i][j][xorr] = pathCnt;
    }

    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        m = grid.size(), n = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(grid, 0, 0, 0, k);
    }
};
