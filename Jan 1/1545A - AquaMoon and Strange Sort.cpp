// Problem Link : https://codeforces.com/problemset/problem/1545/A
// My code :

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
 
    vector<int> odd, even;
    for(int i = 0; i < n; i++){
        if(i & 1) odd.push_back(arr[i]);
        else even.push_back(arr[i]);
    }
 
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    sort(arr.begin(), arr.end());
 
    int odd_ptr = 0, even_ptr = 0;
    bool fl = true;
 
    for(int i = 0; i < n; i++){
        int ele;
        if(i & 1) ele = odd[odd_ptr++];
        else ele = even[even_ptr++];
 
        if(arr[i] != ele){
            fl = false;
            break;
        }
    }
 
    if(fl) cout << "YES" << "\n";
    else cout << "NO" << "\n";
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
