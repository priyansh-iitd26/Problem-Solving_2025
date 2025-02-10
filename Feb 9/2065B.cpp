//Link : https://codeforces.com/contest/2065/problem/B

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ld long double
#define MOD 1000000007

void solve(){
    string s;
    cin >> s;

    bool fl = false;
    for(int i = 0; i < s.size() - 1; i++){
        if(s[i] == s[i + 1]){
            fl = true;
            break;
        }
    }

    if(!fl) cout << s.size() << "\n";
    else cout << 1 << "\n";
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
