// Problem Link : https://leetcode.com/problems/minimize-the-maximum-edge-weight-of-graph/description/

// Main observations and logic : 
// First observation was the problem statement itself. It said to minimize the maximum edge weight, which gives a hint of applying binary search on answer (edge weight in this case)
// The canAllReachZero() had an important optimization. We had to check whether 0 could be reached from all other nodes or not. Naive approach would be to hit BFS/DFS
// from each of the other nodes. This would result in a time complexity of O(V * (V+E)) for the canAllReachZero() function. TLE.
// IMPORTANT OPTIMIZATION : Whenever we've to check whether we can reach all nodes from a node a, then it's better to reverse the edges of the graph and hit BFS/DFS just
// once from the node a. If the visited array contains ALL true, then "YES", otherwise "NO". Using this, the time complexity of canAllReachZero() reduced to O(V+E).

// Solution Code (BFS in canAllReachZero()) :
class Solution {
public:
    typedef pair<int, int> P;

    bool canAllReachZero(int n, unordered_map<int, vector<P>>& adj, int mid){
        //BFS from 0
        queue<int> que;
        vector<bool> visited(n, false);
        que.push(0);
        visited[0] = true;

        while(!que.empty()){
            int u = que.front();
            que.pop();

            for(auto &p : adj[u]){
                int v = p.first;
                int w = p.second;

                if(w <= mid && !visited[v]){
                    visited[v] = true;
                    que.push(v);
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                return false;
            }
        }

        return true;
    }

    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        unordered_map<int, vector<P>> adj;

        for(vector<int>& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[v].push_back({u, w}); //reversed graph
        }

        //binary search on answer (edge weight)
        int ans = INT_MAX;
        int l = 0;
        int r = 1e6;

        while(l <= r){
            int mid = l + (r - l)/2;
            if(canAllReachZero(n, adj, mid)){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

// Solution Code (DFS in canAllReachZero()) :
class Solution {
public:
    typedef pair<int, int> P;

    void dfs(int u, unordered_map<int, vector<P>>& adj, int mid, vector<bool>& visited){
        visited[u] = true;
        for(auto &p : adj[u]){
            int v = p.first;
            int w = p.second;

            if(w <= mid && !visited[v]){
                dfs(v, adj, mid, visited);
            }
        }
    }

    bool canAllReachZero(int n, unordered_map<int, vector<P>>& adj, int mid){
        //DFS
        vector<bool> visited(n, false);
        dfs(0, adj, mid, visited);

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                return false;
            }
        }

        return true;
    }

    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        unordered_map<int, vector<P>> adj;

        for(vector<int>& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[v].push_back({u, w}); //reversed graph
        }

        //binary search on answer (edge weight)
        int ans = INT_MAX;
        int l = 0;
        int r = 1e6;

        while(l <= r){
            int mid = l + (r - l)/2;
            if(canAllReachZero(n, adj, mid)){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
