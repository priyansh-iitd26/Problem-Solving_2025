// Problem Link : https://leetcode.com/problems/paint-house-iv/description/
// [APPROACH] : https://youtu.be/zrzyxUDuCHk?feature=shared&t=3236

#define ll long long
class Solution {
public:
    ll dp[100005][3][3];
    long long minCost(int n, vector<vector<int>>& cost) {
        //base case (i == 0)
        for(ll j = 0; j < 3; j++){
            for(ll k = 0; k < 3; k++){
                if(j != k){
                    dp[0][j][k] = cost[0][j] + cost[n - 1][k];
                }
                else{ //j == k (invalid case)
                    dp[0][j][k] = 1e15;
                }
            }
        }
        //main iterative dp (tabulation) 
        for(ll i = 1; i < n / 2; i++){
            for(ll j = 0; j < 3; j++){
                for(ll k = 0; k < 3; k++){
                    if(j == k){
                        dp[i][j][k] = 1e15;
                    }
                    else{
                        dp[i][j][k] = 1e15;
                        for(ll nj = 0; nj < 3; nj++){
                            for(ll nk = 0; nk < 3; nk++){
                                if(nj != j && nk != k && nj != nk){
                                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][nj][nk]);
                                }
                            }
                        }
                        dp[i][j][k] += cost[i][j] + cost[n - i - 1][k];
                    }
                }
            }
        }
        // our answer is in the middle - minimize over colors j, k => dp[n/2-1][j][k]
        ll ans = 1e15;
        for(ll j = 0; j < 3; j++){
            for(ll k = 0; k < 3; k++){
                ans = min(ans, dp[n / 2 - 1][j][k]);
            }
        }

        return ans;
    }
};
