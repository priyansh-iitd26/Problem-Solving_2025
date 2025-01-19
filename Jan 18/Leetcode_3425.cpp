// Problem Link : https://leetcode.com/problems/longest-special-path/description/
// Topics Used : DFS (Backtracking) + Sliding Window
// Intuition :
/*
To find the longest special path, we need to traverse the undirected tree and then backtrack several times to visit the entire tree.
But, we need to make sure of one thing - special path is a path with all unique valued (or unique colored) nodes.
We keep a map to store the latest seen index of a particular node color. This will update when backtracking, to its original value.
Rest is DFS + Backtracking logic
*/
class Solution {

    int maxLength = INT_MIN; 
    int minNodes = INT_MAX;
    
    void dfs(int u, int parent, vector<vector<pair<int, int>>>& adj, vector<int>& nums, int pathSum, int start, int end, map<int, int>& indexMap, vector<int>& path){
        
        int prevIdx = indexMap.count(nums[u]) ? indexMap[nums[u]] : -1; //last seen index of current color -> if not in map, take it as -1
    
        while(start <= prevIdx){ //remove all the edge lengths before the last seen index of same color
            pathSum -= path[start]; //note that don't remove from path vector since it will be handled by backtracking. Only remove contribution fromm pathSum
            start++;
        }

        //update the answers
        if(maxLength < pathSum){
            maxLength = pathSum;
            minNodes = end - start + 1;
        }
        else if(maxLength == pathSum){
            minNodes = min(minNodes, end - start + 1);
        }

        indexMap[nums[u]] = end; //latest seen index of current color
        
        //explore neighbors of u
        for(auto& [v, wt] : adj[u]){
            if(v != parent){
                path.push_back(wt);
                dfs(v, u, adj, nums, pathSum + wt, start, end + 1, indexMap, path);
                path.pop_back(); //backtrack from current neighbor of u
            }
        }

        indexMap[nums[u]] = prevIdx; //backtrack from u
    }

public:
    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        int n = nums.size();
        vector<vector<pair<int, int>>> adj(n);

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        map<int, int> indexMap; //O(log(n)) insertion and lookup for std::map and O(n) insertion and lookup if use std::unordered_map
        vector<int> path;
        
        dfs(0, -1, adj, nums, 0, 0, 0, indexMap, path);
        
        return {maxLength, minNodes};
    }
};
//T.C : O(n*logn)
//S.C : O(n)
