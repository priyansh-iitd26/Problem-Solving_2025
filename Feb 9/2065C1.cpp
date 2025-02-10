/*
Link : https://codeforces.com/contest/2065/problem/C1

The overall idea for both subtasks (C1 and C2) is that you need to iterate from left to right, and upon each element, pick the operation such that you obtain the 
smallest value of a[i] that is greater than a[i−1] (prev)
 
For C1, you only have two values to consider for each index : b[0] − a[i] and a[i].
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    int b_num = b.front();
    int prev = min(a.front(), b_num - a.front());

    for(int i = 1; i < n; i++){
        if(max(a[i], b_num - a[i]) < prev){
            cout << "NO" << "\n";
            return;
        }
        if(a[i] >= prev && b_num - a[i] >= prev) prev = min(a[i], b_num - a[i]);
        else if(a[i] >= prev && b_num - a[i] < prev) prev = a[i];
        else if(a[i] < prev && b_num - a[i] >= prev) prev = b_num - a[i];
    }

    cout << "YES" << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}




