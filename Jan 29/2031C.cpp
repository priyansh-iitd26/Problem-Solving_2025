// Problem Link : https://codeforces.com/contest/2031/problem/C

// Beautiful Math + Constructive Algorithm problem!!!

// Here's the solution

void solve(){
    int n;
    cin >> n;
 
    if(n % 2 == 1 && n <= 25){
        cout << -1 << "\n";
        return;
    }
 
    else if(n == 27){
        cout << "1 3 3 4 4 5 5 6 6 1 2 7 7 8 8 9 9 10 10 11 11 12 12 13 13 1 2" << "\n";
        return;
    }
 
    else if(n % 2 == 1 && n > 27){
        cout << "1 3 3 4 4 5 5 6 6 1 2 7 7 8 8 9 9 10 10 11 11 12 12 13 13 1 2 " << "\n";
        int val = 14;
        for(int extra = 0; 27 + 2 * extra < n; extra++){
            cout << val << " " << val << " ";
            val++;
        }
    }
 
    else{
        vector<int> vec(n);
        int cnt = 1;
 
        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                vec[i] = cnt;
                cnt++;
            }
        }
 
        cnt = 1;
 
        for(int i = 0; i < n; i++){
            if(i % 2 == 1){
                vec[i] = cnt;
                cnt++;
            }
        }
 
        for(int i = 0; i < n; i++){
            cout << vec[i] << " ";
        }
        cout << "\n";
    }
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
