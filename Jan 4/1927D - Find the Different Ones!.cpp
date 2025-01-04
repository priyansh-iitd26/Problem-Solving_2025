// Problem Link : https://codeforces.com/contest/1927/problem/D

// My Logic :
// I analyzed the first simple example test case and thought that I need to go to each index and assume it to be l of the query. For each index (assuming it to be l), 
// I need to find the next nearest distinct element to this and store it inside a map/vector. But, to populate the next_distinct[] vector, I need to run two nested loops (which would give TLE),
// then, suddenly I realized that I can modify the nextGreaterToRight() code (using stack) to nextDistinctIndexToRight() and get the next_distinct[] in O(n).
// This was my logic.

// My code : (Passed in 2nd attempt)

vector<int> nextDistinctIndexToRight(vector<int>& nums){
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> stk;   
 
    for(int i = n - 1; i >= 0; i--){
        while(!stk.empty() && nums[stk.top()] == nums[i]){
            stk.pop();
        }
 
        if(!stk.empty()){
            result[i] = stk.top() + 1;
        }
 
        stk.push(i);
    }
 
    return result;
}
 
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
 
    vector<int> next_distinct = nextDistinctIndexToRight(a);
 
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
 
        if(next_distinct[l - 1] != -1 && next_distinct[l - 1] <= r){
            cout << l << " " << next_distinct[l - 1] << "\n";
            continue;
        }
 
        cout << -1 << " " << -1 << "\n";
    }
 
    cout << "\n";
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
