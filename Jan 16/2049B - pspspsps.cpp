// Problem Link : https://codeforces.com/contest/2049/problem/B

// This problem requires observations and pen-paper try-test to solve.
// Few Observations :
// In the string whenever a 'p' comes before 's' --> ans = "NO"
// If the string consists of only 'p' or '.' --> ans = "YES" [1,2,3,....,n] permutation valid
// If the string consists of only 's' or '.' --> ans = "YES" [n-1, n-2,.....,1] permutation valid
// s....s...p....p --> NOT VALID contradiction on value n.
// "YES" answers on --> ...p...
//                  --> ...s...
//                  --> s...p...p...p...
//                  --> ...s...s...s...p
// All other cases --> ans = "NO"

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
 
    int cnt_s = 0, cnt_p = 0;
    int first_p = -1, last_s = -1;
 
    for(int i = 0; i < n; i++){
        if(s[i] == 'p'){
            cnt_p++;
            if(first_p == -1){ //first occurence of 'p'
                first_p = i;
            }
        }
        else if(s[i] == 's'){
            cnt_s++;
            last_s = i; //last occurence of 's'
        }
    }
    //pure 's' OR pure 'p' case
    if(cnt_p == 0 || cnt_s == 0){ 
        cout << "YES" << "\n";
        return;
    }
    //s...p...p...p... OR ...s...s...s...p 
    if(first_p == n - 1 || last_s == 0){
        cout << "YES" << "\n";
        return;
    }
    //all other cases 
    cout << "NO" << "\n";
    return;
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
