// Problem Link : https://codeforces.com/problemset/problem/1846/E1

// Logic :
// n <= 1e6, so we precompute all possible number of nodes in a noolean vector "possible" and when taking input of n, just see whether possible[n] is true or not.
// Look at the precompute() function

// Code :
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define MOD 1000000007
 
int N = 1e6 + 1;
vector<bool> possible(N);
 
void precompute(){
 
    for(int k = 2; ; k++){
        
        int total_nodes = 1 + k + k * 1LL * k;
        int x = k * 1LL * k;
 
        if(total_nodes > N) break;
 
        while(total_nodes < N){
            possible[total_nodes] = true;
            total_nodes += (x * k);
            x *= k;
        }
    }
}
 
void solve(){
    int n;
    cin >> n;
 
    if(possible[n]) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    precompute();
 
    int tc;
    cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}
