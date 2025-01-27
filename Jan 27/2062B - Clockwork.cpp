// Problem Link : https://codeforces.com/contest/2062/problem/B
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
 
    // for(int i = 0; i < n; i++){
    //     if(a[i] == 1){
    //         cout << "no" << "\n";
    //         return;
    //     }
    // }
 
    for(int i = 0; i < n; i++){
        if(a[i] >= 1 + max(2 * i, 2 * (n - i - 1))){
            continue;
        }
        else{
            cout << "no" << "\n";
            return;
        }
    }
 
    cout << "yes" << "\n";
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
