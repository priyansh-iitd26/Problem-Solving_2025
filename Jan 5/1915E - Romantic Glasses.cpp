// Problem Link : https://codeforces.com/problemset/problem/1915/E

// Logic :
/* Rewrite the given equation: a[l] + a[l+2] + a[l+4] + ⋯ + a[r] = a[l+1] + a[l+3] + ⋯ +a[r−1] as
(a[l] − a[l+1]) + (a[l+2] − a[l+3]) + a[l+4] + ⋯ − a[r−1] + a[r] = 0.
From here, it's clear that we need to find if there is a subarray with alternating sum equal to 0
How to check this? Flip the sign of all elements on either odd or even indices.
So, now we just need to check if there is a subarray with sum 0. 
This is a standard problem with prefix sums: if two prefix sums are equal, then the subarray between them has sum 0; otherwise, no subarray has sum 0
*/

// Code :
// Using the std::map approach
void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
 
    for(int i = 0; i < n; i++){
        if(i % 2 == 1) arr[i] *= -1;
    }
 
    map<int, int> mp;
    int sum = 0;
    bool fl = false;
 
    for(int i = 0; i < n; i++){
        sum += arr[i];
 
        if(sum == 0 || mp.find(sum) != mp.end()){
            fl = true;
            break;
        }
 
        mp[sum]++;
    }
 
    cout << (fl ? "YES" : "NO") << "\n";
}

// Using the std::set approach
void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
 
    for(int i = 0; i < n; i++){
        if(i % 2 == 1) arr[i] *= -1;
    }
 
    set<int> st;
    int sum = 0;
    bool fl = false;
 
    for(int i = 0; i < n; i++){
        sum += arr[i];
 
        if(sum == 0 || st.find(sum) != st.end()){
            fl = true;
            break;
        }
 
        st.insert(sum);
    }
 
    cout << (fl ? "YES" : "NO") << "\n";
}
