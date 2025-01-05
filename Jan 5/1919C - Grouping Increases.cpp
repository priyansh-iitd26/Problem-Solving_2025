// Problem Link : https://codeforces.com/contest/1919/problem/C
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
 
    int s = LLONG_MAX, t = LLONG_MAX, penalty = 0;
 
    for(int i = 0; i < n; i++){
        if(s > t){
            swap(s, t);
        }
        if(a[i] <= s){
            s = a[i];
        }
        else if(a[i] <= t){
            t = a[i];
        }
        else{
            penalty++;
            s = a[i];
        }
    }
 
    cout << penalty << "\n";
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
