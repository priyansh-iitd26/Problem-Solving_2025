// Problem Link : https://codeforces.com/contest/2057/problem/C

// This is a very good problem on Bit Manipulation
// Constraints : l, r < 2^30, and 2^30 ~ 10^9, so looping over l & r won't work, even looping once through l & r won't work
// Try to solve such problems by observing simple cases such as l = 0000...0 and r = 1111...1.
// Also, we have the expression a^b + b^c + c^a. If a = b = c, ans = 0. If a = 1, b = 1, c = 0, then a^b + b^c + a^c = 2
// The objective is to make atleast one bit different from others

// l = 000......000
// r = 111......111
//-------------------
// a = 100......000
// b = 011......111
// c = something != a, b

// By this allocation to a and b, the sum of XORs is maximized.
// In every position bit varies in a and b whatever c may be
// So, when l = 0.....0 and r = 1....1 => a = 1000....0, b = 0111....1, c = something in [l, r] != a, b

// Now, let's consider the case of general l and r
// l = 0101100101001
// r = 0101110001011
//-------------------
// a = 0101110000000
// b = 0101101111111
// c = 01011[something]

// Note that before the first position where bits of l & r differ, we had to put the same bits in a, b and c so that they
// remain in the range [l, r] (properly analyze)

// Subtraction by 1
// When subtracting 1 from a binary number, the operation is ->
  // Start with LSB
  // Flip the bits until you find the first set bit

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ld long double
#define MOD 1000000007

void solve(){
    int l, r;
    cin >> l >> r;

    int ans = 0;

    for(int i = 31; i >= 0; i--){
        int l_bit = l & (1 << i); //extracting the ith bit in l
        int r_bit = r & (1 << i); //extracting the ith bit in r

        if(l_bit == r_bit && (l & (1 << i))){ //if the ith bits in both l and r are same and are set, then set the ith bit in ans also.
                                              //if the ith bits are same and unset, let it be unset (we can't do anything if both l_bit and r_bit are same)
            ans |= (1 << i);
        }
        else if(l_bit != r_bit){ //if the bits are different, then set that bit in ans and break
            ans |= (1 << i);
            break;
        }
    }
    //now a = ans (as discussed in our approach) and b = ans - 1
    int a = ans, b = ans - 1, c; 
    if(a != r) c = r;
    else c = r - 2;

    cout << a << " " << b << " " << c << "\n";
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
