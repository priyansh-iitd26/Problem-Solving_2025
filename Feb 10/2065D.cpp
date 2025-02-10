/*
Link : https://codeforces.com/contest/2065/problem/D

First analyze score. The final concatenated array would be of size n*m, so score would be nm * a[1] + (nm - 1) * a[2] + (nm - 2) * a[3] + ........ 2 * a[nm-1] + 1 * a[nm]  ---> in 1-based indexing
So, our claim is that we arrange the arrays such that the arrays which have a larger sum come first (so that they contribute more to final score)

We write custom comparator to sort the 2D arrays on the basis of sum

The logic of writing custom comparator is "If sum1 and sum2 are unequal, then the array with greater sum should come first, and if sum1 == sum2, then the array with larger elements in the beginning will come first"
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
    vector<vector<int>> A(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> A[i][j];
        }
    }

    sort(A.begin(), A.end(), [&](const vector<int>& a, const vector<int>& b){
        int sum1 = accumulate(a.begin(), a.end(), 0LL);
        int sum2 = accumulate(b.begin(), b.end(), 0LL);

        if(sum1 != sum2) return sum1 > sum2;
        
        return a > b;
    });

    int ans = 0;
    int pref_sum = 0;

    for(auto& arr : A){
        for(int &ele : arr){
            pref_sum += ele;
            ans += pref_sum;
        }
    }

    cout << ans << "\n";
    
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
