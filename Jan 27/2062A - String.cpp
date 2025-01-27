// Problem Link : https://codeforces.com/contest/2062/problem/A
void solve(){
    string s;
    cin >> s;
    
    int n = s.length();
    int cnt = 0;
    
    for(int i = 0; i < n; i++){
        if(s[i] == '1') cnt++;
    }
 
    cout << cnt << "\n";
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
