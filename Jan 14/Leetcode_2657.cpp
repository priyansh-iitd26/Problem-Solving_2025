/*
2657. Find the Prefix Common Array of Two Arrays

You are given two 0-indexed integer permutations A and B of length n.
A prefix common array of A and B is an array C such that C[i] is equal to the count of numbers that are present at or before the index i in both A and B.
Return the prefix common array of A and B.

A sequence of n integers is called a permutation if it contains all integers from 1 to n exactly once.

Example 1:
Input: A = [1,3,2,4], B = [3,1,2,4]
Output: [0,2,3,4]
Explanation: At i = 0: no number is common, so C[0] = 0.
At i = 1: 1 and 3 are common in A and B, so C[1] = 2.
At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.
At i = 3: 1, 2, 3, and 4 are common in A and B, so C[3] = 4.

Example 2:
Input: A = [2,3,1], B = [3,1,2]
Output: [0,1,3]
Explanation: At i = 0: no number is common, so C[0] = 0.
At i = 1: only 3 is common in A and B, so C[1] = 1.
At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.

Constraints:
1 <= A.length == B.length == n <= 50
1 <= A[i], B[i] <= n
It is guaranteed that A and B are both a permutation of n integers.
*/

// Approach - 1 
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<bool> cntA(51, false);
        vector<bool> cntB(51, false);

        vector<int> C;

        for(int i = 0; i < n; i++){ //O(n)
            cntA[A[i]] = true;
            cntB[B[i]] = true;

            int count = 0;
            for(int i = 1; i < 51; i++){ //O(50)
                if(cntA[i] && cntB[i]){
                    count++;
                }
            }

            C.push_back(count);
        }

        return C;
    }
};
//T.C : O(n)
//S.C : O(2*51) ~ O(1)

// Approach 2 : Since A and B are permutations, we can use a frequency array instead of two boolean arrays. If frequency of any character == 2, it means that it occurs in both A and B.
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> freq(51, 0); //O(51) space

        int count = 0;
        vector<int> C;

        for(int i = 0; i < n; i++){ //O(n)
            freq[A[i]]++;
            if(freq[A[i]] == 2)
                count++;

            freq[B[i]]++;
            if(freq[B[i]] == 2)
                count++;

            C.push_back(count);
        }

        return C;
    }
};
//T.C : O(n)
//S.C : O(1)
