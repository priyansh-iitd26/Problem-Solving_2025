// Problem Link : https://codeforces.com/contest/2056/problem/C
// observation-based problem
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
 
    if(n == 6){
        cout << "1 1 2 3 1 2" << "\n";
        return;
    }
    else if(n == 7){
        cout << "1 2 3 4 5 1 2" << "\n";
        return;
    }
    else{
        for(int i = 0; i < n / 2; i++){
            a[i] = i + 1;
        }
        for(int i = n / 2; i < n; i++){
            a[i] = (i - n / 2) + 1;
        }
    }
 
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
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
