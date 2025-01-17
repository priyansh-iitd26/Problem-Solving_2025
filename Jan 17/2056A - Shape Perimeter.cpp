// Problem Link : https://codeforces.com/contest/2056/problem/A
void solve(){
    int n, side;
    cin >> n >> side;
    vector<pair<int, int>> queries(n);
    for(int i = 0; i < n; i++){
        cin >> queries[i].first >> queries[i].second;
    }
 
    int loss = 0;
    int init_peri = side * 4;
    int peri_without_loss = init_peri * n;
 
    int x = queries[0].first;
    int y = queries[0].second;
 
    for(int i = 1; i < n; i++){
        int loss_x_dir = 2 * (side - queries[i].first);
        int loss_y_dir = 2 * (side - queries[i].second);
 
        loss += loss_x_dir;
        loss += loss_y_dir;
    }
 
    int peri_with_loss = peri_without_loss - loss;
    cout << peri_with_loss << "\n";
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
