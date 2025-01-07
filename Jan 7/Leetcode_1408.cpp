/*
1408. String Matching in an Array

Given an array of string words, return all strings in words that is a substring of another word. 
You can return the answer in any order.

Example 1:

Input: words = ["mass","as","hero","superhero"]
Output: ["as","hero"]
Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
["hero","as"] is also a valid answer.
Example 2:

Input: words = ["leetcode","et","code"]
Output: ["et","code"]
Explanation: "et", "code" are substring of "leetcode".
Example 3:

Input: words = ["blue","green","bu"]
Output: []
Explanation: No string of words is substring of another string.
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 30
words[i] contains only lowercase English letters.
All the strings of words are unique.
*/

// Approach - 1 : Extreme brute force - AC (as constraints are too low)
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        
        int n = words.size();
        vector<string> ans;

        for(int i = 0; i < n; i++){
            string s = words[i];
            for(auto& word : words){
                if(s != word){
                    if(word.find(s) != string::npos){ //check if 'word' contains 's' as a substring or not
                        ans.push_back(s);
                        continue; //skip the current test case if 's' is a substring
                    }
                }
            }
        }

        //to remove duplicate strings in 'ans'
        sort(ans.begin(), ans.end());
        auto it = unique(ans.begin(), ans.end());
        ans.erase(it, ans.end());

        return ans;

    }
};

// Approach - 2 : Brute Force - Using std::set to avoid duplicate strings (avoid using sort, unique on vector 'ans')
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        
        int n = words.size();
        set<string> unique_strings;
        vector<string> ans;

        for(int i = 0; i < n; i++){
            string s = words[i];
            for(auto& word : words){
                if(s != word){
                    if(word.find(s) != string::npos){
                        unique_strings.insert(s);
                        continue;
                    }
                }
            }
        }

        for(auto& str : unique_strings){
            ans.push_back(str);
        }

        return ans;
    }
};

// Appraoch - 3 : Using some string-matching algorithm - KMP Algorithm
