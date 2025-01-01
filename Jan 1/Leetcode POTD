# Leetcode 1422 - Maximum Score After Splitting a String

Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings (i.e. left substring and right substring).
The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.

Example 1:

Input: s = "011101"
Output: 5 
Explanation: 
All possible ways of splitting s into two non-empty substrings are:
left = "0" and right = "11101", score = 1 + 4 = 5 
left = "01" and right = "1101", score = 1 + 3 = 4 
left = "011" and right = "101", score = 1 + 2 = 3 
left = "0111" and right = "01", score = 1 + 1 = 2 
left = "01110" and right = "1", score = 2 + 1 = 3
Example 2:

Input: s = "00111"
Output: 5
Explanation: When left = "00" and right = "111", we get the maximum score = 2 + 3 = 5
Example 3:

Input: s = "1111"
Output: 3

My Solution Code :
class Solution {
public:
    int maxScore(string s) {
        int n = s.length();

        vector<int> prefixSum(n, 0);
        prefixSum[0] = (s[0] == '1');

        for(int i = 1; i < n; i++){
            prefixSum[i] = prefixSum[i - 1] + (s[i] == '1');
        }

        int cnt_zero = 0;
        int num_ones = prefixSum.back();

        if(num_ones == n) return n - 1; //edge case

        int ans = INT_MIN;

        for(int i = 0; i < n - 1; i++){ //not iterating till last as to avoid empty substring 
            if(s[i] == '0') cnt_zero++;
            ans = max(ans, cnt_zero + num_ones - prefixSum[i]);
        }

        if(cnt_zero == n) return n - 1; //edge case

        return ans;
    }
};
