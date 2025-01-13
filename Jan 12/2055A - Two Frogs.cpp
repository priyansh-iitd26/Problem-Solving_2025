// Problem Link : https://codeforces.com/contest/2055/problem/A

// Observe that if Alice and Bob are separated by even distance, then only Alice can force a win against Bob, otherwise not.
void solve(){
    int n, a, b;
    cin >> n >> a >> b;
 
    if(abs(a - b) % 2 == 0)
        cout << "YES";
    else 
        cout << "NO";
 
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
