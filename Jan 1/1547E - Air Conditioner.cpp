// Problem Link : https://codeforces.com/problemset/problem/1547/E
// My code :

#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define INF (int)1e15
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
void solve() {
    int n, k;
    cin >> n >> k;
 
    vector<int> a(k);
    for (int i = 0; i < k; i++) cin >> a[i];
 
    vector<int> t(n, 0);
    for (int i = 0; i < k; i++) {
        int temp;
        cin >> temp;
        t[a[i] - 1] = temp;
    }
 
    vector<int> L(n, (int)1e15);
    vector<int> R(n, (int)1e15);
 
    //for right to left propagation
    //if (n-1)th cell has AC
    if(t[n - 1] != 0)
        R[n - 1] = t[n - 1];
 
    for(int i = n - 2; i >= 0; i--){
        //if current cell has AC
        if(t[i] != 0)
            R[i] = min(t[i], 1 + R[i + 1]);
        else
            R[i] = 1 + R[i + 1];
    }
 
    //for left to right propagation
    //if 0th cell has AC
    if(t[0] != 0)
        L[0] = t[0];
 
    for(int i = 1; i < n; i++){
        //if current cell has AC
        if(t[i] != 0)
            L[i] = min(t[i], 1 + L[i - 1]);
        else
            L[i] = 1 + L[i - 1];
    }
 
    for(int i = 0; i < n; i++){
        cout << min(L[i], R[i]) << " ";
    }
    cout << "\n";
}
 
signed main() {
    fast_io;
    
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
