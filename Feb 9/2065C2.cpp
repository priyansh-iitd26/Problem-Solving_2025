/*
Link : https://codeforces.com/contest/2065/problem/C2

For C2, you now have m values in the array b[]. Clearly, we now need to consider (m + 1) different possible options for a particular index of a[]. 
Solving this problem in O(n*m) is clearly too slow. Therefore, we need to employ a different technique.

Note that instead of trying every value, you can sort all the values in b[], and then binary search for the minimal value of b[j] such that b[j] −a[i] >= prev. 

Then, you're left with the original problem, where you either leave a[i] untouched or you set it to b[j] − a[i] for this optimal index j that you found using binary 
search. Now, by proceeding similar to C1, the problem is solved in O(n*logm) time.
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ld long double
#define MOD 1000000007

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    sort(b.begin(), b.end());

    int prev = -1e18;

    for(int i = 0; i < n; i++){
        int option_1;
        if(a[i] >= prev) 
            option_1 = a[i];

        int req = prev + a[i];
        auto iter = lower_bound(b.begin(), b.end(), req);

        int option_2;
        if(iter != b.end()) 
            option_2 = *iter - a[i];

        if(a[i] < prev && iter == b.end()){
            cout << "NO" << "\n";
            return;
        }
        else if(a[i] >= prev && iter != b.end()) 
            prev = min(option_1, option_2);

        else if(a[i] >= prev) 
            prev = option_1;
        
        else 
            prev = option_2;
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
