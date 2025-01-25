// Problem Link : https://codeforces.com/problemset/problem/2044/E

// I can't iterate over x or y
// No solution would pass the tests which loops over l1, r1 or l2, r2 (since the constraints are too harsh)

// First decide what is the term or parameter we can iterate upon ?
// Notice that k >= 2 and k^n <= 1e9. If we take the minimum value of k, then also 2^30 > 1e9

// Now we get some hint :) 
// We can iterate over n as n <= 32 (infact 30) and n >= 0

// Also for a fixed value of k^n, we can write y = k^n * x
// Since, l1 <= x <= r1 ---(1)
// and, l2 <= k^n * x <= r2 => (l2/k^n) <= x <= (r2/k^n)
// but as x is an integer, we can write => ceil(l2/k^n) <= x <= floor(r2/k^n) [NOTE THIS TRICK!!] ---(2)

// So, we need to find intersection of (1) and (2) at each n

void solve(){
    int k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;

    int p = 1;
    int ans = 0;

    while(p <= 1e9){ //at max 30 iterations as discussed earlier
        
        int L = max(l1, (l2 + p - 1) / p); //lower bound for intersection
        int R = min(r1, r2 / p); //upper bound for intersection
        
        if((R - L + 1) > 0){ //or you could write ans = max(R-L+1, 0LL) directly instead of this if-else
            ans += (R - L + 1);
        }

        p *= k; //multiplying by k at end of each iteration
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
