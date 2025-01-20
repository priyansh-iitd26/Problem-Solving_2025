// Problem Link : https://leetcode.com/problems/first-completely-painted-row-or-column/description/?envType=daily-question&envId=2025-01-20
class Solution {
    int m, n;
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();

        unordered_map<int, pair<int, int>> mp;
        
        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                int val = mat[row][col];
                mp[val] = {row, col};
            }
        }

        vector<int> countRowPainted(m, 0);
        vector<int> countColPainted(n, 0);

        for(int i = 0; i < m * n; i++){
            int val = arr[i];
            auto [row, col] = mp[val];

            countRowPainted[row]++;
            countColPainted[col]++;
            
            if(countRowPainted[row] == n || countColPainted[col] == m){
                return i;
            }
        }

        return -1; //will never be the case
    }
};
