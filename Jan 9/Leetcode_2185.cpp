/*
2185. Counting Words With a Given Prefix

You are given an array of strings words and a string pref.
Return the number of strings in words that contain pref as a prefix.
A prefix of a string s is any leading contiguous substring of s.

Example 1:

Input: words = ["pay","attention","practice","attend"], pref = "at"
Output: 2
Explanation: The 2 strings that contain "at" as a prefix are: "attention" and "attend".
Example 2:

Input: words = ["leetcode","win","loops","success"], pref = "code"
Output: 0
Explanation: There are no strings that contain "code" as a prefix.
 
Constraints:
1 <= words.length <= 100
1 <= words[i].length, pref.length <= 100
words[i] and pref consist of lowercase English letters.
*/

// Approach - 1 : Using std::string::substr() STL function
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size();
        int m = pref.size();

        int ans = 0;

        for(int i = 0; i < n; i++){ //O(n)
            int len = words[i].length();
            if(m > len) continue;
            if(words[i].substr(0, m) == pref){ //O(m)
                ans++;
            }
        }

        return ans;
    }
};
//TC: O(n * m)
//SC: O(1)

// Approach - 2 : Using Trie
struct TrieNode{
    TrieNode* children[26];
    bool isEnd = false;
};

TrieNode* getNode(){
    TrieNode* newNode = new TrieNode();
    for(int i = 0; i < 26; i++){
        newNode->children[i] = NULL;
    }
    return newNode;
}

class Trie{
    public:
        TrieNode* root;

        Trie(){
            root = getNode();
        }

        void insert(string word){
            TrieNode* pCrawl = root;
            for(int i = 0; i < word.length(); i++){
                int idx = word[i] - 'a';
                if(pCrawl->children[idx] == NULL){
                    pCrawl->children[idx] = getNode();
                }
                pCrawl = pCrawl->children[idx];
            }
            pCrawl->isEnd = true;
        }

        bool isPrefix(string pref){
            TrieNode* pCrawl = root;
            for(int i = 0; i < pref.length(); i++){
                int idx = pref[i] - 'a';
                if(pCrawl->children[idx] == NULL){
                    return false;
                }
                pCrawl = pCrawl->children[idx];
            }
            return true;
        }
};

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size();
        int m = pref.length();

        int ans = 0;

        for(int i = 0; i < n; i++){ //O(n)
            int len = words[i].length();
            if(m > len) continue;

            Trie trie;
            trie.insert(words[i]); //O(len)

            if(trie.isPrefix(pref)){ //O(m)
                ans++;
            }
        }

        return ans;
    }
};
//TC: O(n * (len + m))
//SC: O(n * len)
// Note : This solution creates a new Trie for every word in the words[] array, leading to redundant Trie construction and checks. 
// A more efficient solution would involve inserting all words (of words[]) into a single Trie and then performing the prefix check.

// Approach - 3 : Optimized Trie Implementation
// Note that the TrieNode* implementation is different from above
struct TrieNode{
    TrieNode* children[26];
    bool isEnd = false;
    int prefixCount = 0; //to keep track how many words share this prefix
};

TrieNode* getNode(){
    TrieNode* newNode = new TrieNode();
    for(int i = 0; i < 26; i++){
        newNode->children[i] = NULL;
    }
    return newNode;
}

class Trie{
    public:
        TrieNode* root;

        Trie(){
            root = getNode();
        }

        void insert(string word){
            TrieNode* pCrawl = root;
            for(int i = 0; i < word.length(); i++){
                int idx = word[i] - 'a';
                if(pCrawl->children[idx] == NULL){
                    pCrawl->children[idx] = getNode();
                }
                pCrawl = pCrawl->children[idx];
                pCrawl->prefixCount++; //increment the prefix count at this node
            }
            pCrawl->isEnd = true;
        }

        int countWordsWithPrefix(const string& pref) {
            TrieNode* pCrawl = root;
            for(int i = 0; i < pref.length(); i++) {
                int idx = pref[i] - 'a';
                if(pCrawl->children[idx] == NULL) {
                    return 0; //if the prefix does not exist, return 0
                }
                pCrawl = pCrawl->children[idx];
            }
            return pCrawl->prefixCount; //return the number of words with this prefix
        }
};

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        Trie trie;

        //insert all words in words[] in trie
        for (const string& word : words) {
            trie.insert(word);
        }

        return trie.countWordsWithPrefix(pref);
    }
};
//TC: O((n * len) + m)
//SC: O(n * len)
