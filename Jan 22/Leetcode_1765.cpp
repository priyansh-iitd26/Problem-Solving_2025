// Problem Link : https://leetcode.com/problems/map-of-highest-peak/description/
// Same problem : https://leetcode.com/problems/01-matrix/

// Revised Multi-Source BFS from MIK's video

class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        
        vector<vector<int>> ans(m, vector<int>(n, -1));
        
        queue<pair<int, int>> q; //{i, j}
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        //put all water cells in the queue and mark them visited
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(isWater[i][j] == 1){
                    vis[i][j] = true;
                    q.push({i, j});
                }
            }
        }

        //apply multisource BFS to propagate from water cells
        int currLevel = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int curr_i = q.front().first;
                int curr_j = q.front().second;
                q.pop();

                ans[curr_i][curr_j] = currLevel;

                for(vector<int>& dir : directions){
                    int new_i = curr_i + dir[0];
                    int new_j = curr_j + dir[1];

                    if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && !vis[new_i][new_j]){
                        vis[new_i][new_j] = true;
                        q.push({new_i, new_j});
                    }
                }
            }
            currLevel++;
        }

        return ans;
    }
};
