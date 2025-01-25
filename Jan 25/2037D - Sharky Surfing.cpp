// Problem Link : https://codeforces.com/contest/2037/problem/D

// USING MAX_HEAP PQ :
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ld long double
#define MOD 1000000007

void solve(){
    int n, m, L;
    cin >> n >> m >> L;
    vector<pair<int, int>> hurdles(n);
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        hurdles[i] = {l, r};
    }
    vector<pair<int, int>> powerUps(m);
    for(int i = 0; i < m; i++){
        int x, v;
        cin >> x >> v;
        powerUps[i] = {x, v};
    }

    int curr_power = 1, cnt = 0, idx = 0;
    priority_queue<int, vector<int>> pq;

    for(auto [l, r] : hurdles){
        if(curr_power <= r - l + 1){
            for(;idx < m && powerUps[idx].first <= l; idx++){
                pq.push(powerUps[idx].second);
            }

            while(!pq.empty() && curr_power <= r - l + 1){
                curr_power += pq.top();
                pq.pop();
                cnt++;
            }

            if(curr_power <= r - l + 1){
                cnt = -1;
                break;
            }
        }
    }

    cout << cnt << "\n";
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

//USING MULTISET :
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ld long double
#define MOD 1000000007

void solve(){
    int n, m, L;
    cin >> n >> m >> L;
    vector<pair<int, int>> hurdles(n);
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        hurdles[i] = {l, r};
    }
    vector<pair<int, int>> powerUps(m);
    for(int i = 0; i < m; i++){
        int x, v;
        cin >> x >> v;
        powerUps[i] = {x, v};
    }

    int curr_power = 1, cnt = 0, idx = 0;
    multiset<int> ms;

    for(auto [l, r] : hurdles){
        if(curr_power <= r - l + 1){
            for(;idx < m && powerUps[idx].first <= l; idx++){
                ms.insert(powerUps[idx].second);
            }

            while(!ms.empty() && curr_power <= r - l + 1){
                curr_power += *ms.rbegin();
                ms.erase(prev(ms.end()));
                cnt++;
            }

            if(curr_power <= r - l + 1){
                cnt = -1;
                break;
            }
        }
    }

    cout << cnt << "\n";
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
