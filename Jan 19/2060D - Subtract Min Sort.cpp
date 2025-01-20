// Problem Link : https://codeforces.com/contest/2060/problem/D

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < n - 1; i++){
        if(a[i + 1] < a[i]){
            cout << "NO" << "\n";
            return;
        }
        else{
            a[i + 1] -= a[i];
            a[i] = 0;
        }
    }

    cout << "YES" << "\n";
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
