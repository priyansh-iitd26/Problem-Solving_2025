// Problem Link : https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups/description/
// Vide : https://www.youtube.com/watch?v=Iku-NBN2jRE&t=0s

// Detailed Code :
class Solution {
public:
    bool isBipartite(unordered_map<int, vector<int>>& adj, int currNode, vector<int>& color, int currColor){
        color[currNode] = currColor;
        
        for(int &v : adj[currNode]){
            if(color[v] == color[currNode]){
                return false;
            }
            else if(color[v] == -1){
                int color_v = 1 - currColor;
                if(isBipartite(adj, v, color, color_v) == false){
                    return false;
                }
            }
        }

        return true;
    }

    int BFS(unordered_map<int, vector<int>>& adj, int currNode, int V){
        queue<int> q;
        vector<bool> visited(V, false);
        q.push(currNode);
        visited[currNode] = true;

        int numLevels = 1;

        while(!q.empty()){
            int size = q.size();

            while(size--){
                int node = q.front();
                q.pop();

                for(int &v : adj[node]){
                    if(!visited[v]){
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }

            numLevels++;
        }

        return (numLevels - 1);
    }

    int getMaxFromThisComponent(unordered_map<int, vector<int>>& adj, int currNode, vector<int>& maxGroupsFromEachNode, vector<bool>& visited){
        visited[currNode] = true;
        int maxGroupsFromThisComponent = maxGroupsFromEachNode[currNode];

        for(int &v : adj[currNode]){
            if(!visited[v]){
                maxGroupsFromThisComponent = max(maxGroupsFromThisComponent, getMaxFromThisComponent(adj, v, maxGroupsFromEachNode, visited));
            }
        }

        return maxGroupsFromThisComponent;
    }
    int magnificentSets(int V, vector<vector<int>>& edges) {
        //graph formation
        unordered_map<int, vector<int>> adj;
        for(auto &edge : edges){
            int u = edge[0] - 1; //converted to 0-based indexing
            int v = edge[1] - 1; //converted to 0-based indexing
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //bipartite check
        vector<int> color(V, -1);
        for(int node = 0; node < V; node++){
            if(color[node] == -1){
                if(isBipartite(adj, node, color, 0) == false){
                    return -1;
                }
            }
        }

        //finding maxLevels / maxGroups for each node using bfs
        vector<int> maxGroupsFromEachNode(V, 0);
        for(int node = 0; node < V; node++){
            maxGroupsFromEachNode[node] = BFS(adj, node, V);
        }

        //finding maxGroups for each disconnected component
        int maxTotalGroups = 0;
        vector<bool> visited(V, false);
        for(int node = 0; node < V; node++){
            if(!visited[node]){
                maxTotalGroups += getMaxFromThisComponent(adj, node, maxGroupsFromEachNode, visited);
            }
        }

        return maxTotalGroups;
    }
};
