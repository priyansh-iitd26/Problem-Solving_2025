// Problem Link : https://codeforces.com/contest/2060/problem/E

// Step-by-step approach :
// Just check the connected components in G
// Remove the unwanted edges in F
// Now, if F has more connected components than G, then add the remaining edges in F so that final number of connected components in both F & G are same
// Final answer = number of edges removed + number of edges added

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ld long double
#define MOD 1000000007

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

    bool isConnected(int u, int v){
        u = UPar(u);
        v = UPar(v);
        return u == v;
    }
};

void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis) {
    vis[node] = true;
    for (int neighbor : adj[node]) {
        if (!vis[neighbor]) {
            dfs(neighbor, adj, vis);
        }
    }
}

int countConnectedComponents(int n, vector<pair<int, int>>& edges) {
    vector<vector<int>> adj(n);
    vector<bool> vis(n, false);
    for (auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cc = 0;
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            dfs(i, adj, vis);
            cc++;
        }
    }
    return cc;
}

void solve(){
    int n, m1, m2;
    cin >> n >> m1 >> m2;

    vector<pair<int, int>> gr_f(m1), gr_g(m2);
    for(int i = 0; i < m1; i++){
        int u, v;
        cin >> u >> v;
        gr_f.push_back({u - 1, v - 1});
    }
    for(int i = 0; i < m2; i++){
        int u, v;
        cin >> u >> v;
        gr_g.push_back({u - 1, v - 1});
    }

    DSU F(n);
    DSU G(n);

    for(auto &p : gr_g){
        int u = p.first, v = p.second;
        G.unionBySize(u, v);
    }

    int ans = 0;

    for(auto &p : gr_f){
        int u = p.first, v = p.second;
        if(G.isConnected(u, v)){
            F.unionBySize(u, v);
        }
        else{
            ans++;
        }
    }
    //way to find number of connected components using DSU 
    set<int> st1, st2;
    for(int i = 0; i < n; i++){
        st1.insert(F.UPar(i));
        st2.insert(G.UPar(i));
    }

    if(st1.size() > st2.size()) cout << ans + st1.size() - st2.size();
    else cout << ans;

    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}
