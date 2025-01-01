// Problem Link : https://codeforces.com/problemset/problem/1548/A
// My code
void solve(){
    int n, m;
    cin >> n >> m;
 
    vector<int> adj[n + 1];
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    vector<int> count(n + 1, 0); //count[i] = number of nodes greater than i and connected to i
 
    for(int node = 1; node < n + 1; node++){
        for(auto& nbr : adj[node]){
            if(nbr > node){
                count[node]++;
            }
        }
    }
 
    int ans = 0;
    for(int i = 1; i < n + 1; i++){
        if(count[i] == 0) ans++;
    }
 
    int q;
    cin >> q;
    while(q--){
        int type;
        cin >> type;
 
        if(type == 1){
            int u, v;
            cin >> u >> v;
 
            if(u > v) swap(u, v);
 
            bool fl = false;
            if(count[u] == 0) fl = true;
 
            count[u]++;
 
            if(fl && count[u] > 0) ans--;
        }
        else if(type == 2){
            int u, v;
            cin >> u >> v;
 
            if(u > v) swap(u, v);
 
            bool fl = false;
            if(count[u] == 0) fl = true;
 
            count[u]--;
 
            if(!fl && count[u] == 0) ans++;
        }
        else{
            cout << ans << "\n";
        }
    }
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    solve();
    return 0;
}
