// Problem Link : https://leetcode.com/problems/redundant-connection/description/
//DFS
class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& adj, vector<bool>& visited, int u, int v){
        visited[u] = true;

        if(u == v){
            return true;
        }

        for(auto &nbr : adj[u]){
            if(!visited[nbr]){
                if(dfs(adj, visited, nbr, v)){
                    return true;
                }
            }
        }

        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        //number of nodes = n
        //number of edges = n

        unordered_map<int, vector<int>> adj;

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];

            vector<bool> visited(n, false);
            if(adj.count(u) > 0 && adj.count(v) > 0 && dfs(adj, visited, u, v)){
                return edge;
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};

//BFS
class Solution {
public:
    bool bfs(unordered_map<int, vector<int>>& adj, vector<bool>& visited, int u, int v){
        visited[u] = true;
        queue<int> q;
        q.push(u);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto &nbr : adj[node]){
                if(!visited[nbr]){
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }

        return visited[v];
        
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        //number of nodes = n
        //number of edges = n

        unordered_map<int, vector<int>> adj;

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];

            vector<bool> visited(n, false);
            if(adj.count(u) > 0 && adj.count(v) > 0 && bfs(adj, visited, u, v)){
                return edge;
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};

//Most Optimal - DSU
class DSU {
    vector<int> rank, parent, size;
public:
    DSU(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int UPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = UPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = UPar(u);
        int ulp_v = UPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);

        for(auto &edge : edges){
            if(dsu.UPar(edge[0]) != dsu.UPar(edge[1])) dsu.unionBySize(edge[0], edge[1]);
            else return edge;
        }

        return {};
    }
};
