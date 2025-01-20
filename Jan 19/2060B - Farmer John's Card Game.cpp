// Problem Link : https://codeforces.com/contest/2060/problem/B

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        sort(v[i].begin(), v[i].end());
    }

    vector<int> cnt(n);
    for(int i = 0; i < n; i++){
        cnt[i] = i + 1;
    }

    for(int i = 0; i < n; i++){ //bubble sort logic
        for(int j = i + 1; j < n; j++){
            if(v[i][0] > v[j][0]){
                swap(v[i], v[j]);
                swap(cnt[i], cnt[j]);
            }
        }
    }

    int order = 0;
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            if(v[i][j] != order){
                cout << -1 << "\n";
                return;
            }
            order++;
        }
    }

    for(int i = 0; i < n; i++){
        cout << cnt[i] << " ";
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
