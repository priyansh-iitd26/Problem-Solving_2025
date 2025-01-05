// Problem Link : https://codeforces.com/problemset/problem/1881/D

// Logic (Editorial) :
// Decompose each element to prime factors. Then, calculate the number of each divisor after decomposition of all numbers.
// If each divisor is some k times n, where k is a natural number and n is the array length, then we can equalize all elements
// in the array : sequentially apply the operation so that each number contains the same set of prime divisors.
// For example, consider a[] = [30, 50, 27, 20]
// If some divisor enters a different number of times, then it will not be possible to equalize the numbers in the array.

// Code :
// Array a [_, _, _, _, .....(only -1 or 1)] -> aint subarray sums lie within [mn, mx]
// Array a with aint -1/1, and atmost one other element x (-1e9 <= x <= 1e9) -> aint subarray sums within [mn_p + mn_s + x, mx_p + mx_s + x]
// where mn = min_subarray_sum, mx = max_subarray_sum
// mn_p = minimum prefix sum, mn_s = minimum suffix sum & so on
// Max. Subarray Sum in O(n) => Kadane's Algorithm
// Min. Subarray Sum in O(n) => Reverse signs of -1 & 1 => and apply -ve Kadane's Algorithm and reverse sign of answer

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define MOD 1000000007
/*-----------------------------------------------------------------------------------------*/
//divisors
//this is simple code to fill divisors of a number 'x' in a map 'divs'
void add_divs(int x, map<int, int>&divs){
    int i = 2;
    while(i * i <= x){
        while(x % i == 0){
            divs[i]++;
            x /= i;
        }
        i++;
    }

    if(x > 1) divs[x]++; //means that the leftover x is prime in nature
}
/*-----------------------------------------------------------------------------------------*/
void solve(){
    int n;
    cin >> n;
    
    vector<int> arr(n); //the input array
    map<int, int> divs; //this map stores the count of each divisor of each element of the array

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        add_divs(arr[i], divs); //we're invoking this function after each element is taken as input and populating the map
    }

    bool fl = true;
    for(auto& div : divs){
        if(div.second % n != 0) fl = false; //if the count of any divisor is not a multiple of n, we can't split it equally among all elements 
    }

    cout << (fl ? "yes" : "no") << "\n";
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
