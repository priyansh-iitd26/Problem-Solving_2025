// Problem Link : https://codeforces.com/problemset/problem/2050/D

// Ek digit jitna ledt jaa sakta hai utna lekar jaao. Ek digit atmost 8-9 steps hii left jaa sakta hai kyunki 1 se decrease bhi toh ho raha hai naa...
// Brute Force + Greedy

void solve(){
    string s;
    cin >> s;
    vector<int> arr(s.size());
    for(int i = 0; i < s.size(); i++){
        arr[i] = s[i] - '0';
    }

    for(int i = 1; i < s.size(); i++){ //O(n)
        int idx = i;

        while(idx >= 1 && arr[idx] - 1 > arr[idx - 1]){ //NOT O(n) it is O(10)
            int val = arr[idx];
            arr[idx] = arr[idx - 1];
            arr[idx - 1] = val - 1;

            if(idx <= 1) break;
            else idx--;
        }
    }

    string ans = "";
    for(int i = 0; i < s.size(); i++){
        ans += to_string(arr[i]);
    }

    cout << ans << "\n";
}
//T.C : O(n*10) ~ O(n)

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
