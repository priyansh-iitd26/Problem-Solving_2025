// Problem Link : https://codeforces.com/problemset/problem/1794/C

// Logic :
//"https://youtu.be/UUvUMYNeO9Y?feature=shared&t=696"
//--GREAT LOGIC EXPLANATION--

// Code :
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << 1 << " ";
    int count = 1;
    
    for(int i = 1; i < n; i++){
        if(a[i - count] >= count + 1){
            count++;
        }
        cout << count << " ";
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
