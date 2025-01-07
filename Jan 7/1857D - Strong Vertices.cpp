// Problem Link : https://codeforces.com/problemset/problem/1857/D
// Code (Easy Problem) : 
void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
 
    vector<pair<int, int>> diff(n, {0, 0});
    
    for(int i = 0; i < n; i++){
        diff[i] = {a[i] - b[i], i + 1};
    }
 
    auto lambda = [](const pair<int, int>& p1, const pair<int, int>& p2){
        if (p1.first != p2.first)
            return p1.first < p2.first;
        return p1.second < p2.second;
    };
 
    sort(diff.begin(), diff.end(), lambda);
 
    set<int> st;
    st.insert(diff.back().second);
    int cnt = 1;
    int maxVal = diff.back().first;
 
    for(int i = 0; i < n - 1; i++){
        if(diff[i].first == maxVal){
            st.insert(diff[i].second);
            cnt++;
        }
    }
 
    cout << cnt << "\n";
    for(auto& num : st){
        cout << num << " ";
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
