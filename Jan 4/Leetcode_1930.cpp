// 1930. Unique Length-3 Palindromic Subsequences
/*
Given a string s, return the number of unique palindromes of length three that are a subsequence of s.
Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

Example 1:

Input: s = "aabca"
Output: 3
Explanation: The 3 palindromic subsequences of length 3 are:
- "aba" (subsequence of "aabca")
- "aaa" (subsequence of "aabca")
- "aca" (subsequence of "aabca")
Example 2:

Input: s = "adc"
Output: 0
Explanation: There are no palindromic subsequences of length 3 in "adc".
Example 3:

Input: s = "bbcbaba"
Output: 4
Explanation: The 4 palindromic subsequences of length 3 are:
- "bbb" (subsequence of "bbcbaba")
- "bcb" (subsequence of "bbcbaba")
- "bab" (subsequence of "bbcbaba")
- "aba" (subsequence of "bbcbaba")
 

Constraints:

3 <= s.length <= 10^5
s consists of only lowercase English letters.
*/

// My code (Way-1):

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();

        unordered_set<char> unique_letters;
        for(int i = 0; i < n; i++){
            unique_letters.insert(s[i]);
        }

        int ans = 0;

        for(auto& letter : unique_letters){ //O(26 * n)

            int leftmost_idx = -1;
            int rightmost_idx = -1;

            for(int i = 0; i < n; i++){

                if(s[i] == letter){

                    if(leftmost_idx == -1){
                        leftmost_idx = i;
                    }

                    rightmost_idx = i;
                }
            }

            unordered_set<char> st;

            for(int middle = leftmost_idx + 1; middle <= rightmost_idx - 1; middle++){
                st.insert(s[middle]);
            }

            ans += st.size();
        }

        return ans;
    }
};

// Way-2 : Precompute the leftmost_idx and rightmost_idx of all 26 characters in another vector of size 26

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();

        vector<pair<int, int>> indices(26, {-1, -1}); //will store the leftmost and rightmost indices of every letter

        for(int i = 0; i < n; i++){
            int idx = s[i] - 'a';
            
            if(indices[idx].first == -1){
                indices[idx].first = i;
            }

            indices[idx].second = i;

        }

        int ans = 0;

        for(int i = 0; i < 26; i++){ //O(26)

            int leftmost_idx = indices[i].first;
            int rightmost_idx = indices[i].second;

            if(leftmost_idx == rightmost_idx) //single occurence
                continue;

            unordered_set<char> st;

            for(int middle = leftmost_idx + 1; middle <= rightmost_idx - 1; middle++){
                st.insert(s[middle]);
            }

            ans += st.size();
        }

        return ans;
    }
};
