// Problem Link : https://codeforces.com/contest/2055/problem/C

// Logic : Let's try to fill the cells on the path such that the rowSum and colSum equal zero.
// When we encounter 'D', our path leaves the entire row and hence path never crosses that row again.
// Same for 'R'. Our path leaves that column forever and moves to the next coliumn.

// Key observation : Why we chosed '0' to make every rowSum = colSum = 0 ?
// For grids in which m != n, no non-zero value of rowSum & colSum can be used.
// Proof :
// In the problem C (The Trail), I was asked why I kept the Target sum x value to 0. We saw that a non-zero value of x doesn't work for test cases where n != m.

// I apologise that I couldn't formally show a proof in the PCD as I incorrectly thought it would work for all values. (And luckily chose 0 which worked).

// Here is a formal proof why no value of x != 0 works when n != m.

// Suppose, all the row sums and column sums are x.
// So, Sum of all cells in the grid = x*n (No. of rows * Sum of each row)
// Also, Sum of all cells in the grid = x*m (No. of columns * Sum of each Column)

// That means, x*n = x*m.
// But since n != m, It's true only when x = 0.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define MOD 1000000007

void solve(){
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    vector<int> rowSum(n), colSum(m);

    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = 0; j < m; j++){
            sum += grid[i][j];
        }
        rowSum[i] = sum;
    }

    for(int j = 0; j < m; j++){
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += grid[i][j];
        }
        colSum[j] = sum;
    }

    int x = 0, y = 0;
    int ptr = 0;

    while(ptr < n + m - 1){
        if(s[ptr] == 'D'){
            grid[x][y] = -rowSum[x];
            rowSum[x] += grid[x][y];
            colSum[y] += grid[x][y];
            x++;
        }
        else{
            grid[x][y] = -colSum[y];
            rowSum[x] += grid[x][y];
            colSum[y] += grid[x][y];
            y++;
        }
        ptr++;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << grid[i][j] << " ";
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
