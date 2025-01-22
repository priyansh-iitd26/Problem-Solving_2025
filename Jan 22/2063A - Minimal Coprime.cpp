// Problem Link : https://codeforces.com/contest/2063/problem/A

// Observation : [1,1] is minimal coprime
// For all l > 1, [l, l + 1] is minimal coprime
// There is no other segment that is minimal coprime

void solve(){
    int l, r;
    cin >> l >> r;
 
    if(l == 1 && r == 1){
        cout << 1 << "\n";
        return;
    }
    cout << r - l << "\n";
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
