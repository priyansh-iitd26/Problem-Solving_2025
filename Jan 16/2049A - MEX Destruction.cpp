// Problem Link : https://codeforces.com/contest/2049/problem/A
// observation based 800-level
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
 
    int count = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 0) count++;
    }
 
    if(count == n){
        cout << 0 << "\n";
        return;
    }
 
    int i = 0;
    while(i < n && a[i] == 0){
        i++;
    }
    int j = n - 1;
    while(j >= 0 && a[j] == 0){
        j--;
    }
 
    bool fl = true;
    for(int idx = i; idx <= j; idx++){
        if(a[idx] == 0){
            fl = false;
            break;
        }
    }
 
    if(fl) cout << 1;
    else cout << 2;
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
