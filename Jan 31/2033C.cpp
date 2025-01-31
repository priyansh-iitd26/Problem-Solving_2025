//Problem Link : https://codeforces.com/problemset/problem/2033/C
//Every position/index can have either a[i] or a[n-i-1]. The first and last elements can be placed in-order or reverse-order.
//Then, from the pairs coming further, if it is required to swap, then we will swap otherwise not
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
 
    for(int i = 1; i <= n / 2; i++){
        if(a[i] == a[i - 1] || a[n - i - 1] == a[n - i]){
            swap(a[i], a[n - i - 1]);
        }
    }
 
    int ans = 0;
    for(int i = 0; i < n - 1; i++){
        if(a[i] == a[i + 1]){
            ans++;
        }
    }
 
    cout << ans << "\n";
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
