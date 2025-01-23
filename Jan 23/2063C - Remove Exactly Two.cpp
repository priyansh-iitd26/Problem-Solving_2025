// Problem Link : https://codeforces.com/contest/2063/problem/C

// My Logic :
// I thought that we should choose the two nodes with maximum degree and remove them, since removing the max degree node and its edges will give maximum number of connected components.
// Form the degree[] vector and create another vector of pairs with {deg[i], i}, where i is the node, and sort it in decreasing order.
// For the first operation, I remove the node which is the first in vector of pairs above. I also remove the edges it had with other nodes and update the degrees after the first operation.
// Then, I sort the updated vector of pairs {deg[i], i} and now the maximum one is again removed. 
// After all this alteration in the graph, I run DFS to calculate the number of connected components. 
// I got WA on pretest 2.

// The above approach is not correct.
// It will fail in those cases where we have multiple nodes with same maximum degree. The maximum number of connected components will depend on which maximum degree nodes are removed. This is a fact!!
// Observe the counter test case explained in TLE video editorial.

// So, now what should be the logic??
// See, your logic would remain almost correct, but now, you would have to try all possible nodes to remove...

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ld long double
#define MOD 1000000007

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<int> deg(n + 1, 0); //to store degree of each node
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    if(n == 2){ //empty graph would be left - edge case
        cout << 0 << "\n";
        return;
    }

    int mx_deg = 0;
    set<pair<int, int>> st; //to efficiently pick up node with maximum degree as second one to remove

    for(int u = 1; u <= n; u++){
        mx_deg = max(mx_deg, deg[u]);
        st.insert({deg[u], u});
    }

    int global_ans = 0;

    for(int u = 1; u <= n; u++){
        if(deg[u] == mx_deg){
            int case_ans = 0;
            st.erase({deg[u], u}); //erase the first node - the one with deg[u] = mx_deg
            
            case_ans += deg[u]; //no. of CCs rise up by deg[u] - u is the FIRST node to be removed

            for(auto &v : adj[u]){ //updating the degrees of all the nodes adjacent to u - recently removed
                st.erase({deg[v], v});
                deg[v]--;
                st.insert({deg[v], v});
            }

            case_ans += (*st.rbegin()).first - 1; //second node is removed, so the no. of CCs rise by its degree - 1. *st.rbegin() gives {deg[x], x} of node x with max degree now

            global_ans = max(global_ans, case_ans); //update the global answer by this combination removal - u (first node) & x (second node)

            // resetting every removal and degree updates for next pair of nodes to be removed in next iteration
            st.insert({deg[u], u}); 
            for(auto &v : adj[u]){
                st.erase({deg[v], v});
                deg[v]++;
                st.insert({deg[v], v});
            }
        }
    }

    cout << global_ans << "\n";
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
