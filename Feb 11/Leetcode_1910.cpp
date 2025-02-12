Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:
- Find the leftmost occurrence of the substring part and remove it from s.
- Return s after removing all occurrences of part.

Example 1:
Input: s = "daabcbaabcbc", part = "abc"
Output: "dab"
Explanation: The following operations are done:
- s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
- s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
- s = "dababc", remove "abc" starting at index 3, so s = "dab".
Now s has no occurrences of "abc".
  
Example 2:
Input: s = "axxxxyyyyb", part = "xy"
Output: "ab"
Explanation: The following operations are done:
- s = "axxxxyyyyb", remove "xy" starting at index 4 so s = "axxxyyyb".
- s = "axxxyyyb", remove "xy" starting at index 3 so s = "axxyyb".
- s = "axxyyb", remove "xy" starting at index 2 so s = "axyb".
- s = "axyb", remove "xy" starting at index 1 so s = "ab".
Now s has no occurrences of "xy".

Constraints:
1 <= s.length <= 1000
1 <= part.length <= 1000
s​​​​​​ and part consists of lowercase English letters.

----------------------------------------------------------------------------** CODE **------------------------------------------------------------------------------------------------------------------------------
  
class Solution {
private:
    bool check(stack<char> st, string& part, int &p){ //st --> pass by value  
        for(int ptr = p - 1; ptr >= 0; ptr--){ //start from right to left since its a stack
            if(st.top() != part[ptr])
                return false;
            st.pop();
        }
        return true;
    }
public:
    string removeOccurrences(string s, string part) {
        int n = s.length();
        int p = part.length();

        stack<char> st;

        for(int i = 0; i < n; i++){
            st.push(s[i]);
            
            if(st.size() >= p && check(st, part, p)){
                //remove
                for(int cnt = 0; cnt < p; cnt++){
                    st.pop();
                }
            }
        }

        string ans = "";

        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        
        return ans;
    }
};
