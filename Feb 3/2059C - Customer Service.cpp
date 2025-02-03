//Problem Link : https://codeforces.com/contest/2059/problem/C

//Greedy + Constructive Algorithms

/*
    observations:

        - after the final second, when the operation is made on any queue, 0 will surely come
        - so final array will surely contain 0 (also positive values a[i][j] are added each second)
        - to maximize MEX of final array [0, .........], we want 1 to appear so that we can maximize MEX. If 1 already appears, we would be greedy to appearance of 2, then 3 and vice versa
        - maximum MEX we can get would be n (but not always) - this requires a specific configuration of a[i][j] grid

        - suppose the last test case
            - 4 #2 2 17 -> 21
              1 9 3 #1 ->1
              5 5 5 11# -> 0
              1 2 #1 1 -> 2
            [the column represents timestamp as in the input grid a[i][j] and # represent the service at a particular time of that queue]
            - so final array [21, 1, 0, 2] -> MEX = 3 (also the answer in last test case)

        - we have to make 0, 1, 2, 3,.... in the final array somehow 
        - if we fail in making some element (like 4 in above example), then our answer is that element
        
        - but how are we making certain elements in final array?
        - we are taking sums of the last elements of a row (basically suffix sums of every row/queue)

        - when we decide to serve a queue/row i at some timestamp j, then the final_arr[i] would contain sum of all elements starting from (i+1) till (n-1) for that row

        - note:
            - to get 1 in final array, we cannot place the partition beyond one element from the end (since sum of two positive integers can't be 1)
            - similarly, to get 2, we need to get 2 from combinations of two 1's (think)
            - trailing 1's highly matter!!

        - we'll find the maximum 1's in each row. If a queue/row has m 1's, then after all events in that row/queue, we could leave any number from 0 to m, which will participate in MEX
        - we greedily collect the elements by taking the smallest suitable suffix each time
*/

//code :

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ld long double
#define MOD 1000000007
 
void solve(){
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
 
    vector<int> num_trailing_ones; //storing the number of trailing ones in in each row/queue
    //this is the code for storing number of trailing ones
    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = n - 1; j >= 0; j--){
            if(a[i][j] == 1)
                count++;
            else 
                break;
        }
        num_trailing_ones.push_back(count);
    }
    //sorting is required so that I pick up my requirement from the smallest number of 1's giving row first
    sort(num_trailing_ones.begin(), num_trailing_ones.end());
 
    int req = 1; //my current requirement - I know that I can always get 0 in final array(from the last service)
 
    for(int i = 1; i < n; i++){
        if(num_trailing_ones[i] >= req){
            req++; //now I am greedy, so my requirement increases for next element (example, if I have found 1, I look for 2 now)
        }
    }
 
    cout << req << "\n";
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
