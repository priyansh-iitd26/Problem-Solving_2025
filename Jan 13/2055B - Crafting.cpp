// Problem Link : https://codeforces.com/contest/2055/problem/B

// CLAIM : By the virtue of the type of the operation, we cannot increase the value of a at >= 2 indices at the same time.
void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
 
    int cnt = 0; //stores the number of indices i where a[i] < b[i] - violations
 
    for(int i = 0; i < n; i++){
        if(a[i] < b[i]) cnt++;
    }
 
    if(cnt >= 2) cout << "NO"; //>=2 violations can't be resolved in any way
    else if(cnt == 0) cout << "YES"; //no violation - a[i] >= b[i] for all i 
    else{ //cnt == 1 case is only left. Easiest way is to simulate the operation since only one index is there to apply operation multiple times
        int increment = -1; //stores the increment required by the violating index
        int idx = -1; //only index where violation is present
        for(int i = 0; i < n; i++){
            if(a[i] >= b[i]) continue;
            else{
                increment = b[i] - a[i];
                idx = i;
                break;
            }
        }
        //actually applying the operation on idx
        for(int i = 0; i < n; i++){
            if(i != idx) a[i] -= increment;
            else a[i] += increment;
        }
        //now checking that whether a[i] >= b[i] for all i or not
        bool fl = true;
        for(int i = 0; i < n; i++){
            if(a[i] < b[i]){ //some other violation created in attempt to resolve violation at index = idx
                fl = false;
                break;
            }
        }
        cout << (fl ? "YES" : "NO");
    }
    cout << "\n";
}
