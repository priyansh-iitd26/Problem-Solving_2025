/* 2381. Shifting Letters II

You are given a string s of lowercase English letters and a 2D integer array shifts where shifts[i] = [starti, endi, directioni]. For every i, shift the characters in s from the index starti to the index endi (inclusive) forward if directioni = 1, or shift the characters backward if directioni = 0.

Shifting a character forward means replacing it with the next letter in the alphabet (wrapping around so that 'z' becomes 'a'). Similarly, shifting a character backward means replacing it with the previous letter in the alphabet (wrapping around so that 'a' becomes 'z').

Return the final string after all such shifts to s are applied.

Example 1:

Input: s = "abc", shifts = [[0,1,0],[1,2,1],[0,2,1]]
Output: "ace"
Explanation: Firstly, shift the characters from index 0 to index 1 backward. Now s = "zac".
Secondly, shift the characters from index 1 to index 2 forward. Now s = "zbd".
Finally, shift the characters from index 0 to index 2 forward. Now s = "ace".
Example 2:

Input: s = "dztz", shifts = [[0,0,0],[1,1,1]]
Output: "catz"
Explanation: Firstly, shift the characters from index 0 to index 0 backward. Now s = "cztz".
Finally, shift the characters from index 1 to index 1 forward. Now s = "catz".
 

Constraints:

1 <= s.length, shifts.length <= 5 * 10^4
shifts[i].length == 3
0 <= starti <= endi < s.length
0 <= directioni <= 1
s consists of lowercase English letters.
*/

// Approach : Difference Array for Range Addition/Subtraction Queries
// Note that Segment/Fenwick Tree can also be used but not used here because there are no updates, i.e. static queries.
// As difference array + cumulative sum approach is easy to implement and of lesser space complexity than segment tree, it is preferred.

// Code :

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        // difference array
        vector<int> diff(n, 0); //to store the total shifts/changes (to be updated later in the initial string s) 

        for(auto& query : shifts){
            int l = query[0];
            int r = query[1];
            int dir = query[2];

            if(dir == 1){ //forward shift //USED DIFFERENCE ARRAY TECHNIQUE HERE!!!
                diff[l]++;
                if(r + 1 < n){
                    diff[r + 1]--;
                }
            }
            else{ //backward shift //USED DIFFERENCE ARRAY TECHNIQUE HERE!!!
                diff[l]--;
                if(r + 1 < n){
                    diff[r + 1]++;
                }
            }
        }
        // Now build the new result string by applying the changes to string s
        string ans = "";
        int cum_sum = 0; //the cumulative sum stores the changes at a particular index of string s : This needs to be reflected in new string ans.

        for(int i = 0; i < n; i++){
            sum = (sum + diff[i]) % 26; //to ensure wrapping around 'a' or 'z'
            if(sum < 0) sum += 26; //to ensure wrapping around 'a' or 'z'

            char newChar = ('a' + (s[i] - 'a' + sum) % 26); //analyze this properly!!!
            ans.push_back(newChar);
        }

        return ans;
    }
};
