// Problem Link : https://codeforces.com/contest/1931/problem/D

// The Logic : 
// Modulus property used : (a + b) % m = (a % m + b % m) % m
// Expand the conditions of a good pair :
// 1. a[i] − a[j] is divisible by y.
// (a[i] - a[j]) % y = 0
// (a[i] - a[j] + a[j]) % y = a[j] % y
// a[j] % y = a[i] % y ---(1)
// 2. a[i] + a[j] is divisible by x.
// (a[i] % x + a[j] % x) % x = 0
// a[j] % x = (x - a[i] % x) % x ---(2)
// Now, iterate j over the array and apply same logic as the Two-Sum problem on Leetcode.

// Code :

void solve(){
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
 
    map<pair<int, int>, int> mp; //pair.first stores a[j] % x and pair.second stores a[j] % y
    int ans = 0;
    
    for(int j = 0; j < n; j++){
 
        int xMod_req = (x - a[j] % x) % x; 
        int yMod_req = a[j] % y;
 
        ans += mp[{xMod_req, yMod_req}]; //xMod_req and yMod_req are conditions required to form good pair with current a[j]
        mp[{a[j] % x, a[j] % y}]++; 
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
