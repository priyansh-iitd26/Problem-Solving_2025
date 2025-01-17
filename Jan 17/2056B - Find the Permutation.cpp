// Problem Link : https://codeforces.com/contest/2056/problem/B

void solve(){
    int n;
    cin >> n;
    vector<string> adj(n);
    for(int i = 0; i < n; i++) cin >> adj[i];
 
    vector<int> perm(n, 0);
    for(int i = 0; i < n; i++) perm[i] = i + 1;
 
    auto lambda = [&](int u, int v){
        if(u < v) return adj[u - 1][v - 1] == '1';
        return adj[v - 1][u - 1] == '0';
    };
 
    sort(perm.begin(), perm.end(), lambda);
 
    for(int i = 0; i < n; i++){
        cout << perm[i] << " ";
    }
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
