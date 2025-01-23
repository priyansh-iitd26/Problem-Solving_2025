// Problem Link : https://codeforces.com/contest/2050/problem/E

// Logic : Recursion - Trying all possibilities
// Recursion + Memo problem
// if c[pos] != a[i], then it is surely changed to some other character, hence add 1 with recursive call
// similar for b[j] & c[pos]

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
 
int solve(int i, int j, string &a, string &b, string &c)
{
    if (i == a.size() && j == b.size())
        return 0;
 
    if (dp[i][j] != -1)
        return dp[i][j];
 
    int pos = i + j; // pos in c
    int ans = 1e9;
 
    if (i < a.size())
    {
        int cost = solve(i + 1, j, a, b, c) + (a[i] != c[pos]);
        ans = min(ans, cost);
    }
    if (j < b.size())
    {
        int cost = solve(i, j + 1, a, b, c) + (b[j] != c[pos]);
        ans = min(ans, cost);
    }
 
    return dp[i][j] = ans;
}
 
// dp[i][j] = minimum cost to make c[0...i+j-1] from a[0...i-1] and b[0...j-1]
 
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b, c;
        cin >> a >> b >> c;
        int n = a.size();
        int m = b.size();
        dp.assign(n + 1, vector<int>(m + 1, -1));
        cout << solve(0, 0, a, b, c) << endl;
    }
    return 0;
}
