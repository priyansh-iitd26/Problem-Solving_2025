// Problem Link : https://codeforces.com/contest/2060/problem/A

void solve(){
    int a1, a2, a4, a5;
    cin >> a1 >> a2 >> a4 >> a5;

    set<int> st; //to store the values of a3
    
    int a3 = a1 + a2;
    st.insert(a3); //to satisfy a3 = a1 + a2, this value of a3 is required

    a3 = a4 - a2;
    st.insert(a3); //to satisfy a4 = a2 + a3, this value of a3 is required

    a3 = a5 - a4;
    st.insert(a3); //to satisfy a5 = a3 + a4, this value of a3 is required
    
    if(st.size() == 3){ //if all the above values are distinct, then maximum fibonaaciness can be 1 only
        cout << 1 << "\n";
        return;
    }
    else if(st.size() == 2){
        cout << 2 << "\n";
        return;
    }
    cout << 3 << "\n"; //if all are same, then maximum fibonacciness can be 3
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
