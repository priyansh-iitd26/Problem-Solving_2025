// Problem Link : https://codeforces.com/contest/2063/problem/B

// Logic :
// Note that the approach of sorting the array in ascending order and printing the sum to first (r - l + 1) elements doesn't work.
// Take a look at this example, a = [3,6,6,4,3,2], l = 3, r = 5. The answer should be 9, but the earlier approach leads to 8.
// Basically, the subsequence reversal (EXACTLY ONCE) doesn't allow for this, i.e. all elements can't be randomly rearranged.

// So, what should be the approach???
// Observation :
// Note that if we chose some two indices i and j, included in the subsequence, such that i < l and j > r at the same time.
// The subsequence chosen is basically, i, i1, i2, i3,...., j. Then, there is no reduction in the sum of the range [l, r], because if we reverse this subsequence,
// then the sum[l, r] still remains the same. So, only benefit is to choose i from left end OR j from right end (BUT NOT AT THE SAME TIME).

// Look at the code below and understand the thought process.

void solve(){
    int n, l, r;
    cin >> n >> l >> r;
    l--, r--; //0-based indexing
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    //left[] stores the elements in the range [0, l - 1]
    //middle[] stores the elements in the interested range [l, r]
    //right[] stores the elements in the range [r + 1, n]
    vector<int> left, middle, right;
  
    for(int i = 0; i < n; i++){
        if(i < l) left.push_back(a[i]);
        else if(i > r) right.push_back(a[i]);
        else middle.push_back(a[i]);
    }
   
    sort(middle.rbegin(), middle.rend()); //Want to replace larger elements in middle[] with smaller elements in either left[] or right[]
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
 
    int i = 0, j = 0;
 
    int sum1 = 0;
    for(i = 0; i < min(left.size(), middle.size()); i++){
        sum1 += min(left[i], middle[i]);
    }
 
    int sum2 = 0;
    for(j = 0; j < min(right.size(), middle.size()); j++){
        sum2 += min(right[j], middle[j]);
    }
 
    for(int k = i; k < middle.size(); k++){
        sum1 += middle[k];
    }
    for(int k = j; k < middle.size(); k++){
        sum2 += middle[k];
    }
 
    cout << min(sum1, sum2) << "\n";
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
