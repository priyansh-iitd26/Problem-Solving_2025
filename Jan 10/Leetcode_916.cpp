/*
916. Word Subsets

You are given two string arrays words1 and words2.
A string b is a subset of string a if every letter in b occurs in a including multiplicity.

For example, "wrr" is a subset of "warrior" but is not a subset of "world".
A string a from words1 is universal if for every string b in words2, b is a subset of a.

Return an array of all the universal strings in words1. You may return the answer in any order.

Example 1:

Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
Output: ["facebook","google","leetcode"]
Example 2:

Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["l","e"]
Output: ["apple","google","leetcode"]


Constraints:

1 <= words1.length, words2.length <= 10^4
1 <= words1[i].length, words2[i].length <= 10
words1[i] and words2[i] consist only of lowercase English letters.
All the strings of words1 are unique.
*/

// Code :
class Solution {
private:
    bool isSubset(vector<int>& freq2, vector<int>& temp){
        for(int i = 0; i < 26; i++){ //O(1)
            if(temp[i] < freq2[i]){
                return false; //not a subset
            }
        }
        return true;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;

        vector<int> freq2(26, 0);
        //O(n*l1)
        for(string& word : words2){ //O(n)
            vector<int> temp(26, 0);

            for(char& ch : word){ //O(l1)
                temp[ch - 'a']++;

                freq2[ch - 'a'] = max(freq2[ch - 'a'], temp[ch - 'a']);
            }
        }
        //O(m*l2)
        for(string& word : words1){ //O(m)
            vector<int> temp(26, 0);

            for(char& ch : word){ //O(l2)
                temp[ch - 'a']++;
            }

            if(isSubset(freq2, temp)){ //O(1)
                ans.push_back(word);
            }
        }

        return ans;
    }
};

//T.C : O(n * l1 + m * l2) = iterating on total characters of words1 and words2
//S.C : O(26) ~ O(1)
