// Problem Link : https://leetcode.com/problems/is-graph-bipartite/description/
// Note : Can also be done using BFS (queue)

class Solution {
private:
    bool dfs(vector<vector<int>>& adj, int currNode, vector<int>& color, int currColor){
        color[currNode] = currColor;

        for(int &v : adj[currNode]){
            if(color[v] == color[currNode]){
                return false;
            }
            else if(color[v] == -1){
                int color_v = 1 - color[currNode];
                if(dfs(adj, v, color, color_v) == false){
                    return false;
                }
            }
        }
        
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                if(dfs(graph, i, color, 0) == false){
                    return false;
                }
            }
        }

        return true;
    }
};
