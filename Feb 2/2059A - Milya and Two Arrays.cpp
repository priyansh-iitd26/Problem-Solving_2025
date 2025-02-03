//Problem Link : https://codeforces.com/contest/2059/problem/A

//Just think and work hands-on test cases!! You'll get the logic
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ld long double
#define MOD 1000000007

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    set<int> st1(a.begin(), a.end()), st2(b.begin(), b.end());
    vector<int> c(n);

    for(int i = 0; i < n; i++){
        c[i] = a[i] + b[i];
    }

    set<int> st3(c.begin(), c.end());

    if(st3.size() >= 3){
        cout << "YES" << "\n";
        return;
    }

    if(st1.size() == 1 || st2.size() == 1){
        cout << "NO" << "\n";
        return;
    }

    cout << "YES" << "\n";
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
