Link : https://codeforces.com/contest/2067/problem/A

Take general case of a number n with m digits a1, a2, a3,...., am

- Case 1 : If am != 9, then adding 1 to n will result in the digits a1, a2, a3,...., am + 1 (all other digits other than am remain unchanged)
- Case 2 : If n contains a block of 'k' 9s at the end, then adding 1 to n will make 'k' zeroes at the end in n + 1 and the last element (say A) != 9 will be changed 
to A + 1, and rest remain unchanged

In Case-1, we can clearly see that y = x + 1 (y is the sum of digits of n + 1 and x is the sum of digits of n)
In Case-2, since (n + 1) has sum y, y = x + 1 - (k * 9) => y - x + 1 = - (k * 9) => x - y + 1 = k * 9 => y - x + 1 is divisible by 9

If we see clearly, y = x + 1 from Case-1 can be incorporated into Case-2 result as well since substituting y = x + 1 in (y - x + 1) becomes 0, which is obviously
divisible by 9.

So, till now our pseudo code is :

void solve(){
    int x, y;
    cin >> x >> y;
    
    if((x - y + 1) % 9 == 0){
        cout << "YES" << "\n";
        return;
    }

    cout << "NO" << "\n";
}

If we see the sample test cases, then the sample with x = 1 and y = 11 fails here. Just add (x - y + 1) >= 0 check as well.

void solve(){
    int x, y;
    cin >> x >> y;
    
    if((x - y + 1 >= 0) && (x - y + 1) % 9 == 0){
        cout << "YES" << "\n";
        return;
    }

    cout << "NO" << "\n";
}



