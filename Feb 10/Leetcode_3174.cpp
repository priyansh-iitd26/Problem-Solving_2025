You are given a string s.
Your task is to remove all digits by doing this operation repeatedly:
- Delete the first digit and the closest non-digit character to its left.
- Return the resulting string after removing all digits.

Example 1:
Input: s = "abc"
Output: "abc"
Explanation:
There is no digit in the string.

Example 2:
Input: s = "cb34"
Output: ""
Explanation:
First, we apply the operation on s[2], and s becomes "c4".
Then we apply the operation on s[1], and s becomes "".

Constraints:
1 <= s.length <= 100
s consists only of lowercase English letters and digits.
The input is generated such that it is possible to delete all digits.

** Observing the word "CLOSEST NON-DIGIT CHARACTER TO ITS LEFT" quickly reminds application of STACK data structure !!!





class Solution {
public:
    string clearDigits(string s) {
        int n = s.length();
        stack<char> st;

        for(int i = 0; i < n; i++){
            char ch = s[i];
            
            if(ch >= 'a' && ch <= 'z')
                st.push(ch);
            
            if(ch - '0' >= 0 && ch - '0' <= 9)
                st.pop();
        }

        string ans;

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
