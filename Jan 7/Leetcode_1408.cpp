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

// Approach - 3 : Using some string-matching algorithm - KMP Algorithm
class Solution {
private:
    void computeLPS(string pat, vector<int>& lps){
        int M = pat.length();
        int len = 0; //length of previous longest prefix & suffix

        lps[0] = 0; //because there is no proper prefix or suffix of pat[0...0]

        int i = 1;
        while(i < M){
            if(pat[i] == pat[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len != 0){
                    len = lps[len - 1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    bool searchKMP(string pat, string txt){
        int N = txt.length();
        int M = pat.length();

        //create an LPS array to store the longest proper prefix which is also a suffix
        //lps[i] = the longest proper prefix of pat[0...i] which is also a suffix of pat[0...i]
        vector<int> lps(M, 0);
        computeLPS(pat, lps);

        int i = 0; //index for txt
        int j = 0; //index for pat

        while(i < N){
            if(txt[i] == pat[j]){
                i++;
                j++;
            }

            if(j == M) //found
                return true;
            
            else if(i < N && txt[i] != pat[j]){
                if(j != 0)
                    j = lps[j - 1];
                else 
                    i++;
            }
        }

        return false;
    }
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> ans;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j && searchKMP(words[i], words[j])){
                    ans.push_back(words[i]);
                    break;
                }
            }
        }

        return ans;
    }
};
