//Problem Link : https://codeforces.com/contest/2059/problem/B

//Great constructive problem!! Too much test case thinking is required!! List all the observations at one place in order to solve these!! :)

/* 
observations
    - if a[1] != 1 and we have enough elements to the right of a[0] to make (k-1) subarrays, then minimum cost is 1
    - if a[1] == 1, then look for a[2] != 1 or not
        - if a[2] != 1, then we need to include both a[0] and a[1] in first subarray and then check if we have enough elements to the right of a[1] to make (k-1) subarrays, if satisfied the minimum cost is still 1
        - if a[2] == 1 as well, then if repeat the same thing for a[3] but we've to check that there are enough elements to the right of a[2] to make (k-1) subarrays
    - if either of a[1] or a[2] is != 1, then our answer is 1
    - if both a[1] and a[2] == 1, then we can take both a[1] and a[2] as the part of same subarray and achieve a cost = 2

    - if n = k, answer can be calculated explicitly easily

    - suppose a = [a1, 1, 1, a4, a5, a6, a7] and k = 6 (n - k = 1 case)
        - we can't take {a1, 1, 1} into one subarray because then 4 elements would be left with 5 subarrays to be formed - not possible - so we can't get min cost of 1
        - the optimal way of partitioning would be to take first subarray as {a1}, second subarray as {1,1}, then min cost = 2 (best possible since we can't get 1 in such case)

    - till which index i we can go so that (k-1) subarrays can be formed ?
    - in 1-based indexing, n - i + 1 = k - 1 (in limiting case, just k - 1 elements are left)
                        => i = n - k + 2 (1-based)
    - in 0-based indexing, (n - 1) - i + 1 = k - 1 => i = n - k + 1

    - we can't get answer exceeding 2

    - main pseudo code (for n != k case):
        - for i = 1 -----> i <= n - k + 1
            - if all a[i] == 1
                - min cost = 2
            - if atleast one a[i] != 1
                - min cost = 1
    
    - for n = k case, we can form the array b and check explicitly
*/

//code is very simple after the key observations



#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ld long double
#define MOD 1000000007

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    if(n == k){
        vector<int> b;

        for(int i = 0; i < n; i++){
            if(i % 2 == 1) b.push_back(a[i]);
        }
        b.push_back(0);

        for(int i = 0; i < b.size(); i++){
            if(b[i] != i + 1){
                cout << i + 1 << "\n";
                return;
            }
        }
    }

    for(int i = 1; i <= n - k + 1; i++){
        if(a[i] != 1){
            cout << 1 << "\n";
            return;
        }
    }
    
    cout << 2 << "\n";
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
