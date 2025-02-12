Link : codeforces.com/contest/2067/problem/B

Let's take a test case to get some intuition
arr = [1 1 1 1 1 1 1 4] => Bag1 = [1 1 1 1 1 1 1 4], Bag2 = [] (initial conditions)
There are 7 1's and 1 4. So, let's transfer 3 1's to Bag2. But, now we're stuck and output "NO". But the sample answer is "YES"!! Why ?

Optimal application of operations is like - 
- Shift one 1 to bag2 and then match that 1 with an already existing 1 in bag1 and do not apply any operation on that fixed 1 in bag1
- Increase all other same 1's (except the fixed/blocked 1) by one. They become 2. Now, again repeat the above step and shift one 2 to bag2 and block an existing 2 in 
  bag1. Keep on doing this. We'll reach the state where both bags have same content.

Also, if the minimum element in the array is unique (only appears once), then the answer is NO (always)

So, our algorithm is -
  Always match one pair and increase all other same values by one.
  If unique minimum exist at any stage, output NO.

Implementation is a bit tricky -

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ld long double
#define MOD 1000000007

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    set<int> st;
    map<int, int> mp;

    for(int i = 0; i < n; i++){
        st.insert(arr[i]);
        mp[arr[i]]++;
    }

    while(!st.empty()){
        int mn = *st.begin();

        if(mp[mn] == 1){
            cout << "NO" << "\n";
            return;
        }

        mp[mn + 1] += mp[mn] - 2;
        if(mp[mn + 1] > 0) st.insert(mn + 1);

        st.erase(mn);
        mp[mn] = 0;
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
