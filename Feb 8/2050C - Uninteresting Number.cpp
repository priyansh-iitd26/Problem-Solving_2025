//Link : https://codeforces.com/contest/2050/problem/C

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ld long double
#define MOD 1000000007
/*
    (a + b) % m = a % m + b % m
*/
void solve(){
    string num;
    cin >> num;

    int tot_sum = 0, cnt_two = 0, cnt_three = 0;

    for(int i = 0; i < num.length(); i++){
        tot_sum += num[i] - '0';
        if(num[i] - '0' == 2) cnt_two++;
        if(num[i] - '0' == 3) cnt_three++;
    }

    for(int a = 0; a <= min(8LL, cnt_two); a++){
        for(int b = 0; b <= min(2LL, cnt_three); b++){
            int gain = 2 * a + 6 * b;
            if((tot_sum + gain) % 9 == 0){
                cout << "YES" << "\n";
                return;
            }
        }
    }

    cout << "NO" << "\n";
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
