//Problem Link : https://leetcode.com/problems/making-a-large-island/description/

//Approach 1 : Super Brute Force (DFS/BFS) - TLE
//T.C : O(n^4)
//S.C : O(n^2)
class Solution {
public:
    int n;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int DFS(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
        if(i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == 0 || visited[i][j])
            return 0;

        visited[i][j] = true;
        int count = 1;

        for(vector<int>& dir : directions) {
            count += DFS(grid, i + dir[0], j + dir[1], visited);
        }

        return count;
    }

    int findLargestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        int maxArea = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {  // Try converting each 0 to 1
                    grid[i][j] = 1;
                    
                    vector<vector<bool>> visited(m, vector<bool>(n, false));
                    int largest = 0;
                    
                    for(int x = 0; x < n; x++) {
                        for(int y = 0; y < n; y++) {
                            if(grid[x][y] == 1 && !visited[x][y]) {
                                largest = max(largest, DFS(grid, x, y, visited));
                            }
                        }
                    }
                    
                    maxArea = max(maxArea, largest);
                    grid[i][j] = 0; // Backtrack
                }
            }
        }
        
        return (maxArea == 0) ? n * n : maxArea; // If the grid was full of 1s
    }

    int largestIsland(vector<vector<int>>& grid) {
        return findLargestIsland(grid);
    }
};

//Approach 2 : Better Brute Force (DFS/BFS) - TLE
//T.C : O(n^4)
//S.C : O(n^2)
class Solution {
    int n;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int DFS(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited){
        if(i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == 0 || visited[i][j])
            return 0;

        visited[i][j] = true;
        int size = 1;
        
        for(auto &dir : directions){
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            size += DFS(grid, new_i, new_j, visited);
        }

        return size;
    }

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();

        int maxSize = 0;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    maxSize = max(maxSize, DFS(grid, i, j, visited));
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    grid[i][j] = 1; //trying this 0 to 1 conversion

                    visited = vector<vector<bool>>(n, vector<bool>(n, false));
                    int size = DFS(grid, i, j, visited);

                    maxSize = max(maxSize, size);
                    grid[i][j] = 0; //undo
                }
            }
        }

        return (maxSize == 0 ? n * n : maxSize);

    }
};

//Approach 3 : Unique ID Approach
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
    int n;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int DFS(vector<vector<int>>& grid, int i, int j, int id){
        if(i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1)
            return 0;

        grid[i][j] = id; //will work as our visited array
        int size = 1;

        for(auto &dir : directions){
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            size += DFS(grid, new_i, new_j, id);
        }

        return size;
    }
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        unordered_map<int, int> uniqueID_size;

        int maxSize = 0;
        int uniqueID = 2;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    int size = DFS(grid, i, j, uniqueID);
                    maxSize = max(maxSize, size);
                    uniqueID_size[uniqueID] = size;
                    uniqueID++;
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    grid[i][j] = 1; //change to 1

                    unordered_set<int> uniqueIDs;
                    for(auto &dir : directions){
                        int new_i = i + dir[0];
                        int new_j = j + dir[1];

                        if(new_i >= 0 && new_i < n && new_j >= 0 && new_j < n && grid[new_i][new_j] != 0){
                            uniqueIDs.insert(grid[new_i][new_j]);
                        }
                    }

                    int currSize = 1;
                    for(auto iter = uniqueIDs.begin(); iter != uniqueIDs.end(); iter++){
                        currSize += uniqueID_size[*iter];
                    }
                    maxSize = max(maxSize, currSize);

                    grid[i][j] = 0; //undo
                }
            }
        }

        return maxSize;
    }
};
