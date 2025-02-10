/*
Link : https://codeforces.com/contest/2065/problem/E

It is a constructive type problem.

Just observe that when k < abs(n - m) OR k > max(n, m) --> required binary string can't be formed

for string construction, if n >= m (dominant zeros), place a block of 'k' zeroes in the beginning and then alternate between 0's and 1's
similar to n < m (dominant ones) case
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ld long double
#define MOD 1000000007

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    if(k < abs(n - m) || k > max(n, m)){
        cout << -1 << "\n";
        return;
    }

    string s;

    if(n >= m){
        for(int i = 0; i < k; i++){
            s.push_back('0');
            n--;
        }

        while(n > 0 || m > 0){
            if(m > 0){
                s.push_back('1');
                m--;
            }
            if(n > 0){
                s.push_back('0');
                n--;
            }
        }
    }

    else{
        for(int i = 0; i < k; i++){
            s.push_back('1');
            m--;
        }

        while(n > 0 || m > 0){
            if(n > 0){
                s.push_back('0');
                n--;
            }
            if(m > 0){
                s.push_back('1');
                m--;
            }
        }
    }

    cout << s << "\n";
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
