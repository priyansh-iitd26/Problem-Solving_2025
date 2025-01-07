// Problem Link : https://codeforces.com/contest/1879/problem/C
// Code (with Approach) : 
const int N = 2e5 + 1;
vector<int> fact(N);

void computeFactorial(){
    fact[0] = fact[1] = 1;
    for(int i = 2; i < N; i++){
        fact[i] = (i * fact[i - 1]) % MOD;
    }
}

void solve(){
    string s;
    cin >> s;

    int n = s.length();

    int cnt = 1; //length of the current cluster/plaster
    int ans = 1;
    int len = 1; //length of the final alternating string        

    char prev = s[0];
    for(int i = 1; i < n; i++){
        if(s[i] == prev){ //increase the length of the current cluster/patch
            cnt++;
        }
        else{ //if the cluster ended
            ans = (ans * cnt) % MOD; //update ans (logic below)
            len++; //the final alternating string will contain just one character from this cluster
            cnt = 1; //reset cnt
        }
        prev = s[i]; //updating prev after every iteration
    }

    //answer contribution for the last cluster/patch
    ans = (ans * cnt) % MOD;
    //now, ans stores the number of ways to choose characters to be deleted (x-1 from each cluster of length x)
    //number of removed characters = n - len
    ans = (ans * fact[n - len]) % MOD;
    //fact[n-len] = number of ways to arrange the deleted characters (sinxe ordering also matters as per "111" test case)
    /*
    For example, consider "000110011101000"
    Number of ways to choose the characters to be deleted (from each cluster) = 3C2 * 2C1 * 2C1 * 3C2 * 3C2
                                                                              = 3 * 2 * 2 * 3 * 3    ---eqn.(1)
    Number of ways to arrange the deleted characters = factorial(2 + 1 + 1 + 2 + 2)      ---eqn.(2)
    Total number of ways to choose elements for deletion to make 's' alternating = [eqn.(1) * eqn.(2)]
    */
    cout << n - len << " " << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    computeFactorial(); //pre-compute factorials

    int tc;
    cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}
